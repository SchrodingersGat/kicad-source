/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2007 G. Harland
 * Copyright (C) 2017 O. Walters
 * Copyright (C) 2017 KiCad Developers, see CHANGELOG.TXT for contributors.
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

#ifndef PANEL_PREF_EESCHEMA_COLOR_CONFIG_H_
#define PANEL_PREF_EESCHEMA_COLOR_CONFIG_H_

#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/colordlg.h>
#include <wx/clrpicker.h>

#include "panel_pref_base.h"

class PANEL_PREF_EESCHEMA_COLOR_CONFIG : public PANEL_PREF
{
private:
    wxColourPickerCtrl* m_SelBgColor;
    wxBoxSizer*         m_mainBoxSizer;

    void CreateColorButtons();

public:
    PANEL_PREF_EESCHEMA_COLOR_CONFIG( wxWindow* aParent );

    virtual void TransferDataFromPanel() override;
    virtual void TransferDataToPanel() override;

};



#endif /* PANEL_PREF_EESCHEMA_COLOR_CONFIG_H_ */
