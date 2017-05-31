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

#ifndef DIALOG_PREFERENCES_H_
#define DIALOG_PREFERENCES_H_

#include <wx/treectrl.h>
#include <vector>

#include "../panels/panel_pref_base.h"
#include "dialog_pref_base.h"

/**
 * Class DIALOG_PREFERENCES
 *
 * Presents a generic preferences dialog window, featuring two main elements:
 * a) Tree view, left of dialog
 * b) Panel view, right of dialog
 *
 * Preference panels are selected from the Tree,
 * and the corresponding preferences panel displayed on the right
 *
 * This class is purely virtual and must be subclassed appropriately
 */
class DIALOG_PREFERENCES : public DIALOG_PREF_BASE
{
public:
    DIALOG_PREFERENCES( wxWindow* parent = nullptr );
    virtual ~DIALOG_PREFERENCES();

    void SetPreferencesPanel( int aItemId );

protected:
    void InitializeTree();

    /**
     * Function AddItems
     * Add specific preference panels to the widget
     *
     * (must be overridden by subclassess of DIALOG_PREFERENCES
     */
    virtual void AddItems( wxTreeItemId& aRoot ) = 0;

    // Pointer to the currently visible panel
    PANEL_PREF* m_currentPanel = nullptr;
    wxBoxSizer* m_panelSizer = nullptr;

    // Other items
    std::vector<PANEL_PREF*> m_panels;

    wxTreeItemId AddItem( wxTreeItemId aParent, wxString aTitle, int aId, PANEL_PREF* aPanel );

    void SetPreferencesPanel( PANEL_PREF* aPanel );

    // Callbacks
    virtual void OnTreeSelectionChanged( wxTreeEvent& event ) override;
    virtual void OnTreeSelectionChanging( wxTreeEvent& event ) override;
};

#endif // DIALOG_PREFERENCES_H_
