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


#include <stdio.h>

#include "dialog_pref.h"

DIALOG_PREFERENCES::DIALOG_PREFERENCES( wxWindow* parent ) : DIALOG_PREF_BASE( parent )
{

}

DIALOG_PREFERENCES::~DIALOG_PREFERENCES()
{
    // Delete all the widgets that were created
    for( auto panel : m_panels )
    {
        if( panel )
        {
            panel->Hide();
            delete( panel );
        }
    }

    m_panels.clear();
}

/**
 * Initialize the preferences tree
 */
void DIALOG_PREFERENCES::InitializeTree()
{
    auto root = m_prefTree->AddRoot( "Root" );

    Freeze();

    m_panelSizer = new wxBoxSizer( wxVERTICAL );

    // Add all custom panels for this dialog
    AddItems( root );

    m_preferencePanel->SetSizer( m_panelSizer );

    Thaw();
    Update();

}

/**
 * Add a new preferences item
 *
 * @param aParent is the parent item that this item will be under
 * @param aTitle is the title of the preferences panel
 * @param aId is the enumerated ID of the panel
 * @param aPanel is a pointer to the panel to be added
 */
wxTreeItemId DIALOG_PREFERENCES::AddItem( wxTreeItemId aParent, wxString aTitle, int aId, PANEL_PREF* aPanel )
{
    assert( aParent.IsOk() );

    m_panelSizer->Add( aPanel, 0, wxEXPAND | wxALL, 5 );

    aPanel->Hide();

    aPanel->Title = aTitle;
    aPanel->Id    = aId;

    aPanel->ParentId = aParent;
    aPanel->PanelId = m_prefTree->AppendItem( aParent, aTitle );

    m_panels.push_back( aPanel );

    return aPanel->PanelId;
}

/**
 * Show the preferences panel associated with a particular ID
 * This allows panels to be enumerated based on known ID values
 */
void DIALOG_PREFERENCES::SetPreferencesPanel( int aItemId )
{

    // Test special cases first
    switch( aItemId )
    {
    case PREF_INVALID:
        return;
    case PREF_MOST_RECENT:
        //TODO
        break;
    case PREF_FIRST:
        if( m_panels.size() > 0 )
        {
            SetPreferencesPanel( m_panels[0] );
            return;
        }
        break;
    case PREF_LAST:
        if( m_panels.size() > 0 )
        {
            SetPreferencesPanel( m_panels[m_panels.size() - 1] );
            return;
        }
        break;
    default:
        break;
    }

    // Test if the provided ID matches any
    for( auto panel : m_panels )
    {
        if( !panel )
        {
            continue;
        }

        if( panel->Id == aItemId )
        {
            SetPreferencesPanel( panel );
            break;
        }
    }
}

/**
 * Display a single preferences panel
 * Currently visible panel is first hidden
 *
 * @param aPanel is the panel to be displayed
 */
void DIALOG_PREFERENCES::SetPreferencesPanel( PANEL_PREF* aPanel )
{

    // Hide the currently selected panel
    if( m_currentPanel )
    {
        m_currentPanel->Hide();
    }

    // Show new panel
    m_currentPanel = aPanel;
    m_currentPanel->Show();

    // Update panel title
    m_prefBox->GetStaticBox()->SetLabel( aPanel->Title );

    // Ensure correct tree item is highlighted
    m_prefTree->SetFocusedItem( aPanel->PanelId );
}

/**
 * Called when a new item is selected in the tree view
 */
void DIALOG_PREFERENCES::OnTreeSelectionChanged( wxTreeEvent& event )
{
    void* panelId = event.GetItem().IsOk() ? event.GetItem().GetID() : nullptr;

    if( !panelId )
    {
        return;
    }

    for( auto panel : m_panels )
    {
        if( !panel )
        {
            continue;
        }

        if( panel->PanelId.GetID() == panelId )
        {
            SetPreferencesPanel( panel );

            break;
        }
    }

    event.Skip();
}

void DIALOG_PREFERENCES::OnTreeSelectionChanging( wxTreeEvent& event )
{
    event.Skip();
}
