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

#ifndef DIALOG_PREF_SINGLE_H_
#define DIALOG_PREF_SINGLE_H_

#include "../panels/panel_pref_base.h"
#include "dialog_pref_single_base.h"

/**
 * Class DIALOG_PREF_SINGLE
 *
 * Presents a simple dialog window displaying a single PREF_PANEL item
 * Use this class to display a single preferences panel view
 */
class DIALOG_PREF_SINGLE : public DIALOG_PREF_SINGLE_BASE
{
public:
    DIALOG_PREF_SINGLE( wxWindow* parent, const wxString aTitle );
    virtual ~DIALOG_PREF_SINGLE();

    void SetPanel( PANEL_PREF* aPanel );

    virtual bool TransferDataToWindow() override;
    virtual bool TransferDataFromWindow() override;

protected:
    PANEL_PREF* m_panel = nullptr;
};


#endif /* DIALOG_PREF_SINGLE_H_ */
