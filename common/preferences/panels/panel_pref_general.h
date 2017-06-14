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

#ifndef PANEL_PREF_GENERAL_H_
#define PANEL_PREF_GENERAL_H_

#include "panel_pref_general_base.h"

class PANEL_PREF_GENERAL : public PANEL_PREF_GENERAL_BASE
{
public:
    PANEL_PREF_GENERAL( wxWindow* aParent );
    virtual ~PANEL_PREF_GENERAL();

    virtual void TransferDataToPanel() override;

protected:
    // UI events
    virtual void OnSelectTextEditor( wxCommandEvent& event ) override;

};



#endif /* PANEL_PREF_GENERAL_H_ */