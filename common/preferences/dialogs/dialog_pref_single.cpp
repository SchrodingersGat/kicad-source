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

#include "dialog_pref_single.h"

#include "../panels/panel_pref_env_var.h"


DIALOG_PREF_SINGLE::DIALOG_PREF_SINGLE( wxWindow* aParent, const wxString aTitle ) :
    DIALOG_PREF_SINGLE_BASE( aParent, wxID_ANY, aTitle )
{
}


DIALOG_PREF_SINGLE::~DIALOG_PREF_SINGLE()
{
    // Safely remove the child panel
    m_panel->Destroy();
}


void DIALOG_PREF_SINGLE::SetPanel( PANEL_PREF* aPanel )
{
    wxASSERT( aPanel );
    m_panel = aPanel;

    TransferDataToWindow();

    m_panelSizer->Add( m_panel, 1, wxALL | wxEXPAND, 5 );

    FinishDialogSettings();
}


bool DIALOG_PREF_SINGLE::TransferDataToWindow()
{
    if( m_panel )
    {
        m_panel->TransferDataToPanel();
    }

    return true;
}


bool DIALOG_PREF_SINGLE::TransferDataFromWindow()
{
    if( m_panel )
    {
        m_panel->TransferDataFromPanel();
    }

    return true;
}
