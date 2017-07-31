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

#include <bitmaps.h>
#include <project.h>
#include <wx/dirdlg.h>
#include <confirm.h>
#include "dialog_env_var_single.h"
#include "validators.h"

DIALOG_ENV_VAR_SINGLE::DIALOG_ENV_VAR_SINGLE( wxWindow* parent, const wxString aEnvVarName, const wxString aEnvVarPath ) :
    DIALOG_ENV_VAR_SINGLE_BASE( parent )
{
    m_selectPathButton->SetBitmap( KiBitmap( directory_xpm ) );

    m_envVarName->SetValue( aEnvVarName );

    m_envVarPath->SetValue( aEnvVarPath );

    m_envVarName->SetValidator( ENVIRONMENT_VARIABLE_CHAR_VALIDATOR() );
}


wxString DIALOG_ENV_VAR_SINGLE::GetEnvVarName() const
{
    return m_envVarName->GetValue();
}


wxString DIALOG_ENV_VAR_SINGLE::GetEnvVarPath() const
{
    return m_envVarPath->GetValue();
}


void DIALOG_ENV_VAR_SINGLE::SetEnvVarProtected()
{
    m_envVarName->Enable( false );
}


void DIALOG_ENV_VAR_SINGLE::OnSelectPath( wxCommandEvent& event )
{
    wxString title = _( "Set path for ENV_VAR" );

    wxString path = wxEmptyString;

    if( 1 )
    {
        //path = Prj().GetProjectPath();
    }

    wxDirDialog dlg( this,
                     title,
                     path,
                     wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR );

    if( dlg.ShowModal() == wxID_OK )
    {
        path = dlg.GetPath();

        m_envVarPath->SetValue( path );
    }
}


void DIALOG_ENV_VAR_SINGLE::OnOkButton( wxCommandEvent& aEvent )
{
    // If user pressed the OK button, test data validity
    if( aEvent.GetId() == wxID_OK )
    {
        wxString name = GetEnvVarName();
        wxString path = GetEnvVarPath();

        // Neither name nor path can be empt
        if( name.IsEmpty() )
        {
            DisplayError( this, _( "Environment variable name cannot be empty." ) );
            //aEvent.Veto();
            return;
        }

        if( path.IsEmpty() )
        {
            DisplayError( this, _( "Environment variable value cannot be empty." ) );
            //aEvent.Veto();
            return;
        }

        // Name cannot start with a number
        if( name.Left( 1 ).IsNumber() )
        {
            DisplayError( this, _( "Environment variable name cannot start with a digit (0-9)." ) );
            //aEvent.Veto();
            return;
        }
    }

    // No errors detected
    EndModal( wxID_OK );
}
