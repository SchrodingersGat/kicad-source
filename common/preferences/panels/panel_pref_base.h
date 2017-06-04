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

#ifndef PANEL_PREF_BASE_H_
#define PANEL_PREF_BASE_H_

#include <wx/panel.h>
#include <wx/treectrl.h>

enum PreferencePanelIds
{
    PREF_INVALID = -1,

    // Show the 'most recent' panel
    PREF_MOST_RECENT = 0,

    // Show the 'first' panel in the list
    PREF_FIRST = 10,
    PREF_LAST,

    // Global preference panels
    PREF_GLOBAL_GENERAL = 100,

    PREF_ENV_VAR_EDITOR,

    // Schematic options
    PREF_SCHEMATIC_TOP,
    PREF_SCHEMATIC_DISPLAY,
    PREF_SCHEMATIC_EDITING,
    PREF_SCHEMATIC_HOTKEYS,
    PREF_SCHEMATIC_COLORS,
    PREF_SCHEMATIC_LIBEDIT,
    PREF_SCHEMATIC_DEFAULT_FIELDS,

    // PCB options
    PREF_PCB_TOP,
};

/**
 * Class PANEL_PREF_BASE
 *
 * Provides base-level behaviour for a preference panel.
 * Multiple preference panels are displayed in a preference dialog window.
 * When a preference dialog is created,
 * data is passed to each contained preference panel.
 * When the dialog is closed, data is retrieved from each panel.
 */
class PANEL_PREF : public wxPanel
{
public:
    PANEL_PREF( wxWindow* aParent,
                wxWindowID aId = wxID_ANY,
                const wxPoint& aPoint = wxDefaultPosition,
                const wxSize& aSize = wxDefaultSize,
                long aStyle = wxTAB_TRAVERSAL );

    virtual ~PANEL_PREF();

    // Panel title, displayed in list view and at top of panel
    wxString Title;

    // Panel ID, used for panel lookup
    int      Id = -1;

    // wxTreeItem ID values associate a panel with a specific item in the tree
    wxTreeItemId ParentId;
    wxTreeItemId PanelId;

    // Data transfer functions
    virtual void TransferDataToPanel() {}
    virtual void TransferDataFromPanel() {}
};

#endif /* PANEL_PREF_BASE_H_ */
