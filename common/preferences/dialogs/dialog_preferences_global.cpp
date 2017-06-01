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

DIALOG_PREFERENCES_GLOBAL::DIALOG_PREFERENCES_GLOBAL( wxWindow* aParent ) : DIALOG_PREFERENCES( aParent )
{
    InitializeTree();

    SetPreferencesPanel( PREF_FIRST );
}

void DIALOG_PREFERENCES_GLOBAL::AddItems( wxTreeItemId& aRoot )
{
    auto parent = m_preferencePanel;

    printf( "Adding items\n");

    auto general = AddItem( aRoot,
                            _( "General" ),
                            PREF_GLOBAL_GENERAL,
                            new PANEL_PREF_GENERAL( parent ) );



    AddItem( general,
            _( "Paths" ),
            PREF_ENV_VAR_EDITOR,
            new PANEL_PREF_ENV_VAR( parent, Pgm().GetLocalEnvVariables() ) );

}
