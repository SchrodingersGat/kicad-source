/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2017 Oliver Walters
 * Copyright (C) 2017 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "panel_pref_env_var.h"
#include "dialog_env_var_single.h"

#include <confirm.h>

#define KISYS3DMOD  "KISYS3DMOD"
#define KIGITHUB    "KIGITHUB"
#define KISYSMOD    "KISYSMOD"
#define KIPRJMOD    "KIPRJMOD"
#define KITEMPLATES "KICAD_PTEMPLATES"

PANEL_PREF_ENV_VAR::PANEL_PREF_ENV_VAR( wxWindow* aParent, const ENV_VAR_MAP& aEnvVars ) : PANEL_PREF_ENV_VAR_BASE( aParent )
{
    // Copy environment variables across
    m_envVarMap = aEnvVars;
}


PANEL_PREF_ENV_VAR::~PANEL_PREF_ENV_VAR()
{
}


void PANEL_PREF_ENV_VAR::TransferDataFromPanel()
{
    /* TODO
     * If any ENV_VAR have been changed,
     * and they are also defined externally,
     * set a warning here...
     *
     * The code below was taken from PGM_BASE::ConfigurePaths()
     */

    /*
    DIALOG_ENV_VAR_CONFIG dlg_envvars( aParent, GetLocalEnvVariables() );

    if( dlg_envvars.ShowModal() == wxID_CANCEL )
        return;

    ENV_VAR_MAP envVarMap = dlg_envvars.GetEnvVarMap();

    for( ENV_VAR_MAP_ITER it = envVarMap.begin(); it != envVarMap.end(); ++it )
    {
        wxLogTrace( traceEnvVars, wxT( "Environment variable %s=%s defined externally = %d" ),
                    GetChars( it->first ), GetChars( it->second.GetValue() ),
                    it->second.GetDefinedExternally() );
    }

    // If any of the environment variables are defined externally, warn the user that the
    // next time kicad is run that the externally defined variables will be used instead of
    // the user's settings.  This is by design.
    if( dlg_envvars.ExternalDefsChanged() && m_show_env_var_dialog )
    {
        wxString msg1 = _( "Warning!  Some of paths you have configured have been defined \n"
                           "externally to the running process and will be temporarily overwritten." );
        wxString msg2 = _( "The next time KiCad is launched, any paths that have already\n"
                           "been defined are honored and any settings defined in the path\n"
                           "configuration dialog are ignored.  If you did not intend for this\n"
                           "behavior, either rename any conflicting entries or remove the\n"
                           "external environment variable definition(s) from your system." );
        wxRichMessageDialog dlg( aParent, msg1, _( "Warning" ), wxOK | wxCENTRE );
        dlg.ShowDetailedText( msg2 );
        dlg.ShowCheckBox( _( "Do not show this message again." ) );
        dlg.ShowModal();
        m_show_env_var_dialog = !dlg.IsCheckBoxChecked();
    }

    SetLocalEnvVariables( dlg_envvars.GetEnvVarMap() );

    */

    Pgm().SetLocalEnvVariables( m_envVarMap );
}


void PANEL_PREF_ENV_VAR::TransferDataToPanel()
{
    // Grab the project path var (not editable)
    wxString prjPath;

    wxGetEnv( PROJECT_VAR_NAME, &prjPath );

    m_kiprjmod->SetLabel( prjPath );

    //TODO - Call SetAlternateRowColour first to prevent assertion error
    //m_pathList->EnableAlternateRowColours( true );

    PopulatePathList();

    // Select the first item in the list
    SelectListIndex( 0 );
}


void PANEL_PREF_ENV_VAR::PopulatePathList()
{
    m_pathList->Freeze();

    m_pathList->ClearAll();

    m_pathList->AppendColumn( _( "Name" ) );
    m_pathList->AppendColumn( _( "Path" ) );

    int row = 0;

    for( auto it = m_envVarMap.begin(); it != m_envVarMap.end(); ++it )
    {
        long index = m_pathList->InsertItem( row, it->first );

        m_pathList->SetItem( index, 1, it->second.GetValue() );

        //TODO - Indicate via background colour if the path is defined external to KiCad

        row++;
    }

    m_pathList->Thaw();
}

bool PANEL_PREF_ENV_VAR::GetPathAtIndex( unsigned int aIndex, wxString& aEnvVar, wxString& aEnvPath )
{
    if( aIndex < 0 || aIndex > m_envVarMap.size() )
    {
        return false;
    }

    unsigned int idx = 0;

    for( auto it = m_envVarMap.begin(); it != m_envVarMap.end(); ++it )
    {
        if( idx == aIndex )
        {
            aEnvVar = it->first;
            aEnvPath = it->second.GetValue();

            return true;
        }

        idx++;
    }

    return false;
}


void PANEL_PREF_ENV_VAR::OnAddButton( wxCommandEvent& event )
{
    auto dlg = new DIALOG_ENV_VAR_SINGLE( nullptr, wxEmptyString, wxEmptyString );

    if( dlg->ShowModal() == wxID_OK )
    {
        wxString newName = dlg->GetEnvVarName();
        wxString newPath = dlg->GetEnvVarPath();

        // Check that the name does not already exist
        if( m_envVarMap.count( newName ) > 0 )
        {
            //TODO - Improve this message, use DisplayErrorMessage instead
            DisplayError( this, _( "Path already exists" ) );
        }
        else
        {
            m_envVarMap[newName] = ENV_VAR_ITEM( newPath );

            // Update path list
            PopulatePathList();
        }
    }

    dlg->Destroy();
}


void PANEL_PREF_ENV_VAR::OnEditButton( wxCommandEvent& event )
{
    EditSelectedEntry();
}


void PANEL_PREF_ENV_VAR::EditSelectedEntry()
{
    wxString envName;
    wxString envPath;

    if( GetPathAtIndex( m_pathIndex, envName, envPath ) )
    {
        auto dlg = new DIALOG_ENV_VAR_SINGLE( nullptr, envName, envPath );

        if( IsEnvVarImmutable( envName ) )
        {
            dlg->SetEnvVarProtected();
        }

        if( dlg->ShowModal() == wxID_OK )
        {
            wxString newName = dlg->GetEnvVarName();
            wxString newPath = dlg->GetEnvVarPath();

            // If the path name has not been changed
            if( envName.Cmp( newName ) == 0 )
            {
                m_envVarMap[envName].SetValue( newPath );

                if( m_envVarMap[envName].GetDefinedExternally() )
                {
                    m_extDefsChanged = true;
                }
            }
            // Path-name needs to be updated
            else
            {
                if( IsEnvVarImmutable( envName ) )
                {
                    DisplayErrorMessage( this,
                                         wxString::Format( _( "Environment variable '%s' cannot be renamed" ), envName.ToStdString() ),
                                         _( "The selected environment variable name"
                                            "is required for KiCad functionality and"
                                            "can not be renamed." ) );

                    return;
                }

                auto envVar = m_envVarMap[envName];

                m_envVarMap.erase( envName );

                envVar.SetValue( newPath );
                envVar.SetDefinedExternally( false );
                m_envVarMap[newName] = envVar;
            }

            // Update the path list
            PopulatePathList();
        }

        dlg->Destroy();
    }
}

void PANEL_PREF_ENV_VAR::OnHelpButton( wxCommandEvent& event )
{
    wxString msg = _( "Enter the name and path for each environment variable.  Grey entries "
                      "are names that have been defined externally at the system or user "
                      "level.  Environment variables defined at the system or user level "
                      "take precedence over the ones defined in this table.  This means the "
                      "values in this table are ignored." );
    msg << wxT( "<br><br><b>" );
    msg << _( "To ensure environment variable names are valid on all platforms, the name field "
              "will only accept upper case letters, digits, and the underscore characters." );
    msg << wxT( "</b><br><br>" );
    msg << _( "<b>KIGITHUB</b> is used by KiCad to define the URL of the repository "
              "of the official KiCad libraries." );
    msg << wxT( "<br><br>" );
    msg << _( "<b>KISYS3DMOD</b> is the base path of system footprint 3D "
              "shapes (.3Dshapes folders)." );
    msg << wxT( "<br><br>" );
    msg << _( "<b>KISYSMOD</b> is the base path of locally installed system "
              "footprint libraries (.pretty folders)." );
    msg << wxT( "<br><br>" );
    msg << _( "<b>KIPRJMOD</b> is internally defined by KiCad (cannot be edited) and is set "
              "to the absolute path of the currently loaded project file.  This environment "
              "variable can be used to define files and paths relative to the currently loaded "
              "project.  For instance, ${KIPRJMOD}/libs/footprints.pretty can be defined as a "
              "folder containing a project specific footprint library named footprints.pretty." );
    msg << wxT( "<br><br>" );
    msg << _( "<b>KICAD_PTEMPLATES</b> is optional and can be defined if you want to "
              "create your own project templates folder." );

    DisplayHtmlInfoMessage( GetParent(), _( "Environment Variable Help" ), msg );
}


bool PANEL_PREF_ENV_VAR::IsEnvVarImmutable( const wxString aEnvVar )
{
    static const wxString immutable[] = {
            KIGITHUB,
            KISYS3DMOD,
            KISYSMOD,
            KIPRJMOD,
            KITEMPLATES
    };

    for( unsigned int ii=0; ii<5; ii++ )
    {
        if( aEnvVar.Cmp( immutable[ii] ) == 0 )
        {
            return true;
        }
    }

    return false;
}


void PANEL_PREF_ENV_VAR::OnRemoveButton( wxCommandEvent& event )
{
    wxString envName;
    wxString envPath;

    if( GetPathAtIndex( m_pathIndex, envName, envPath ) )
    {
        if( IsEnvVarImmutable( envName ) )
        {
            return;
        }

        m_envVarMap.erase( envName );

        PopulatePathList();
    }
}


void PANEL_PREF_ENV_VAR::SelectListIndex( unsigned int aIndex )
{
    if( aIndex >= m_envVarMap.size() )
    {
        aIndex = 0;
    }

    m_pathIndex = aIndex;

    wxString envName;
    wxString envPath;

    if( GetPathAtIndex( m_pathIndex, envName, envPath ) )
    {
        // Disable the 'delete' button if the path cannot be deleted
        m_deletePathButton->Enable( !IsEnvVarImmutable( envName ) );
    }
}

void PANEL_PREF_ENV_VAR::OnPathSelected( wxListEvent& event )
{
    SelectListIndex( event.GetIndex() );
}


void PANEL_PREF_ENV_VAR::OnPathActivated( wxListEvent& event )
{
    SelectListIndex( event.GetIndex() );

    EditSelectedEntry();
}
