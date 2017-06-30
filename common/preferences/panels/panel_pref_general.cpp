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

#include <pgm_base.h>

#include "panel_pref_general.h"

enum PdfViewerOptions
{
    PDF_VIEWER_DEFAULT = 0,
    PDF_VIEWER_CUSTOM
};

PANEL_PREF_GENERAL::PANEL_PREF_GENERAL( wxWindow* aParent ) : PANEL_PREF_GENERAL_BASE( aParent )
{
}


PANEL_PREF_GENERAL::~PANEL_PREF_GENERAL()
{

}

void PANEL_PREF_GENERAL::TransferDataFromPanel()
{
    auto& pgm = Pgm();

    auto langs = pgm.GetLanguages();

    unsigned int idx = m_comboSelectLanguage->GetSelection();

    int newLang = -1;

    if( idx < langs.size() )
    {
        newLang = langs.at(idx)->m_WX_Lang_Identifier;
    }

    if( newLang != -1 && newLang != m_selectedLanguage )
    {
        //TODO - Make language change now
    }

    // Show icons in menus?
    pgm.SetUseIconsInMenus( m_optShowIconsInMenus->GetValue() );


    //TODO - Set text editor and PDF browser
    //pgm.SetEditorName( )
    //pgm.SetPdfBrowserName()
}

void PANEL_PREF_GENERAL::TransferDataToPanel()
{
    // Add options for PDF viewer
    m_pdfViewerChoice->Append( _( "System default" ) );
    m_pdfViewerChoice->Append( _( "Custom viewer" ) );

    auto& pgm = Pgm();

    // Populate language options
    auto langs = pgm.GetLanguages();

    wxString label;

    // Selection index
    int idx = 0;

    m_selectedLanguage = pgm.GetLanguageId();

    for( unsigned int i=0; i<langs.size(); i++ )
    {
        LANGUAGE_DESCR* lang = langs.at(i);

        if( !lang )
            continue;


        if( lang->m_DoNotTranslate )
        {
            label = lang->m_Lang_Label;
        }
        else
        {
            label = wxGetTranslation( lang->m_Lang_Label );
        }

        // Add the pointer to the language itself as the clientData for the options
        m_comboSelectLanguage->Append( label, KiBitmap( lang->m_Lang_Icon ), lang );

        // Mark it as selected if appropriate
        if( lang->m_WX_Lang_Identifier == pgm.GetLanguageId() )
        {
            m_comboSelectLanguage->SetSelection( idx );
        }

        idx++;
    }

    m_optShowIconsInMenus->SetValue( pgm.GetUseIconsInMenus() );
}

void PANEL_PREF_GENERAL::OnSelectTextEditor( wxCommandEvent& event )
{
    wxString defaultEditor;

    auto te = Pgm().AskUserForPreferredEditor( defaultEditor );
}

void PANEL_PREF_GENERAL::OnSelectPdfViewer( wxCommandEvent& event )
{
    auto pdf = Pgm().AskUserForPdfBrowser();

    if( !pdf.IsEmpty() )
    {
        //TODO - New PDF viewer was selected!
    }
}
