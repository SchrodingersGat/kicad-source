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

#include "dialog_preferences_global.h"

// Preference panels
#include "panels/panel_pref_general.h"
#include "panels/panel_pref_env_var.h"
#include "panels/panel_pref_libedit_base.h" //TODO - Subclass base
#include "panels/panel_pref_schematic_base.h" //TODO - Subclass these

DIALOG_PREFERENCES_GLOBAL::DIALOG_PREFERENCES_GLOBAL( wxWindow* aParent ) : DIALOG_PREFERENCES( aParent )
{
    InitializeTree();

    SetPreferencesPanel( PREF_FIRST );
}

void DIALOG_PREFERENCES_GLOBAL::AddItems( wxTreeItemId& aRoot )
{
    auto parent = m_preferencePanel;

    auto general = AddItem( aRoot,
                            _( "General" ),
                            PREF_GLOBAL_GENERAL,
                            new PANEL_PREF_GENERAL( parent ) );

    AddItem( general,
            _( "Hotkeys" ),
            PREF_GLOBAL_HOTKEYS,
            new PANEL_PREF( parent ) );


    auto paths = AddItem( aRoot,
                          _( "Paths" ),
                          PREF_ENV_VAR_EDITOR,
                          new PANEL_PREF_ENV_VAR( parent, Pgm().GetLocalEnvVariables() ) );


    /* Schematic editor preferences */
    auto schem = AddItem( aRoot,
                          _( "Schematic" ),
                          PREF_SCHEMATIC_TOP,
                          new PANEL_PREF( parent ) );

    //TODO
    AddItem( schem,
            _( "Display" ),
            PREF_SCHEMATIC_DISPLAY,
            new PANEL_PREF_SCHEMATIC_DISPLAY_BASE( parent ) );

    //TODO
    AddItem( schem,
            _( "Editing" ),
            PREF_SCHEMATIC_EDITING,
            new PANEL_PREF_SCHEMATIC_EDITING_BASE( parent ) );

    //TODO
    AddItem( schem,
            _( "Hotkeys" ),
            PREF_SCHEMATIC_HOTKEYS,
            new PANEL_PREF_SCHEMATIC_CONTROLS_BASE( parent ) );

    //TODO
    AddItem( schem,
            _( "Colors" ),
            PREF_SCHEMATIC_COLORS,
            new PANEL_PREF_SCHEMATIC_COLORS_BASE( parent ) );

    //TODO
    AddItem( schem,
            _( "Library editor" ),
            PREF_SCHEMATIC_LIBEDIT,
            new PANEL_PREF_LIBEDIT_BASE( parent ) );

    //TODO
    AddItem( schem,
            _( "Default fields" ),
            PREF_SCHEMATIC_DEFAULT_FIELDS,
            new PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS( parent ) );


    /* PCB editor preferences */
    auto pcb = AddItem( aRoot,
                        _( "PCB" ),
                        PREF_PCB_TOP,
                        new PANEL_PREF( parent ) );

    //TODO
    AddItem( pcb,
            _( "Dimensions" ),
            PREF_PCB_DIMENSIONS,
            new PANEL_PREF( parent ) );

    //TODO
    AddItem( pcb,
            _( "Display" ),
            PREF_PCB_DISPLAY,
            new PANEL_PREF( parent ) );

    //TODO
    AddItem( pcb,
            _( "Routing" ),
            PREF_PCB_ROUTING,
            new PANEL_PREF( parent ) );

    //TODO
    AddItem( pcb,
            _( "Hotkeys" ),
            PREF_PCB_HOTKEYS,
            new PANEL_PREF( parent ) );
}
