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

#ifndef PREFERENCE_EDITOR_H_
#define PREFERENCE_EDITOR_H_

#include <wxstruct.h>

#include "dialogs/dialog_preferences_global.h"

/**
 * @Function InvokeDialogPreferencesGlobal
 *
 * Launch the global preferences editor window
 * @param aCaller is the frame where this is called from
 * @param aPreferenceId is the ID of the preference item to display
 */
int InvokeDialogPreferencesGlobal( EDA_BASE_FRAME* aCaller, int aPreferenceId = PREF_MOST_RECENT );

#endif /* PREFERENCE_EDITOR_H_ */