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

#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>

#include <fctsys.h>
#include <draw_frame.h>
#include <class_drawpanel.h>

//#include <../../../eeschema/general.h>

#include "panel_pref_eeschema_color_config.h"

// Specify the width and height of every (color-displaying / bitmap) button
const int BUTT_SIZE_X = 16;
const int BUTT_SIZE_Y = 16;

/********************/
/* Layer menu list. */
/********************/

struct LAYERCOLOR
{
    wxString        m_Name;
    int             m_Layer;
};

struct COLORGROUP
{
    wxString        m_Name;
    LAYERCOLOR*     m_Colors;
};

static LAYERCOLOR generalColors[] = {
    { _( "Wire" ),              LAYER_WIRE },
    { _( "Bus" ),               LAYER_BUS },
    { _( "Junction" ),          LAYER_JUNCTION },
    { _( "Label" ),             LAYER_LOCLABEL },
    { _( "Global label" ),      LAYER_GLOBLABEL },
    { _( "Net name" ),          LAYER_NETNAM },
    { _( "Notes" ),             LAYER_NOTES },
    { _( "No connect symbol" ), LAYER_NOCONNECT },
    { wxT( "" ), -1 }                           // Sentinel marking end of list.
};

static LAYERCOLOR componentColors[] = {
    { _( "Body" ),              LAYER_DEVICE },
    { _( "Body background" ),   LAYER_DEVICE_BACKGROUND },
    { _( "Pin" ),               LAYER_PIN },
    { _( "Pin number" ),        LAYER_PINNUM },
    { _( "Pin name" ),          LAYER_PINNAM },
    { _( "Reference" ),         LAYER_REFERENCEPART },
    { _( "Value" ),             LAYER_VALUEPART },
    { _( "Fields" ),            LAYER_FIELDS },
    { wxT( "" ), -1 }                           // Sentinel marking end of list.
};

static LAYERCOLOR sheetColors[] = {
    { _( "Sheet fill" ),        LAYER_SHEET },
    { _( "Sheet file name" ),   LAYER_SHEETFILENAME },
    { _( "Sheet name" ),        LAYER_SHEETNAME },
    { _( "Sheet label" ),       LAYER_SHEETLABEL },
    { _( "Hierarchical label" ),LAYER_HIERLABEL },
    { wxT( "" ), -1 }                           // Sentinel marking end of list.
};

static LAYERCOLOR miscColors[] = {
    { _( "Background" ),        LAYER_SCHEMATIC_BACKGROUND },
    { _( "ERC warning" ),       LAYER_ERC_WARN },
    { _( "ERC error" ),         LAYER_ERC_ERR },
    { _( "Grid" ),              LAYER_SCHEMATIC_GRID },
    { _( "Brightened" ),        LAYER_BRIGHTENED },
    { wxT( "" ), -1 }                           // Sentinel marking end of list.
};


static COLORGROUP colorGroups[] = {
    { _( "General" ),           generalColors },
    { _( "Component" ),         componentColors },
    { _( "Sheet" ),             sheetColors },
    { _( "Miscellaneous" ),     miscColors },
    { wxT( "" ), NULL }
};

static COLOR4D currentColors[ SCH_LAYER_ID_COUNT ];

PANEL_PREF_EESCHEMA_COLOR_CONFIG::PANEL_PREF_EESCHEMA_COLOR_CONFIG( wxWindow* aParent ) :
    PANEL_PREF( aParent )
{
    CreateColorButtons();
}

void PANEL_PREF_EESCHEMA_COLOR_CONFIG::CreateColorButtons()
{
    m_mainBoxSizer = new wxBoxSizer( wxVERTICAL);

    SetSizer( m_mainBoxSizer );

    COLORGROUP* groups = colorGroups;
    wxBoxSizer* columnBoxSizer = NULL;

    wxPropertyGrid* colorGrid = new wxPropertyGrid( this, wxID_ANY );

    m_mainBoxSizer->Add( colorGrid, 1, wxALL | wxEXPAND, 5 );



    while( groups->m_Colors != NULL )
    {
        LAYERCOLOR* colors = groups->m_Colors;

        /*
        columnBoxSizer = new wxBoxSizer( wxVERTICAL );
        m_mainBoxSizer->Add( columnBoxSizer, 1, wxALIGN_TOP | wxLEFT | wxTOP, 5 );
        wxBoxSizer* rowBoxSizer = new wxBoxSizer( wxHORIZONTAL );
        columnBoxSizer->Add( rowBoxSizer, 0, wxGROW | wxLEFT | wxRIGHT | wxBOTTOM, 5 );

        // Add a text string to identify the column of color select buttons.
        label = new wxStaticText( this, wxID_ANY, groups->m_Name );
        */

        wxPGProperty* propCat = new wxPropertyCategory( groups->m_Name );

        colorGrid->Append( propCat );

        /*
        // Make the column label font bold.
        wxFont font( label->GetFont() );
        font.SetWeight( wxFONTWEIGHT_BOLD );
        label->SetFont( font );

        rowBoxSizer->Add( label, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5 );
        */

        while( colors->m_Layer >= 0 )
        {

            wxColourProperty* colorProp = new wxColourProperty( colors->m_Name );

            colorGrid->AppendIn( propCat, colorProp );

            colors++;

            /*
            rowBoxSizer = new wxBoxSizer( wxHORIZONTAL );
            columnBoxSizer->Add( rowBoxSizer, 0, wxGROW | wxALL, 0 );

            //TODO - Link to GetLayerColor. Damn code being hard and stuff.
            COLOR4D color = { 1.0, 0.0f, 0.0f, 1.0f }; //= GetLayerColor( SCH_LAYER_ID( buttons->m_Layer ) );
            currentColors[ SCH_LAYER_INDEX( buttons->m_Layer ) ] = color;

            wxMemoryDC iconDC;
            wxBitmap   bitmap( BUTT_SIZE_X, BUTT_SIZE_Y );

            iconDC.SelectObject( bitmap );
            iconDC.SetPen( *wxBLACK_PEN );

            wxBrush brush;
            brush.SetColour( color.ToColour() );
            brush.SetStyle( wxBRUSHSTYLE_SOLID );
            iconDC.SetBrush( brush );
            iconDC.DrawRectangle( 0, 0, BUTT_SIZE_X, BUTT_SIZE_Y );

            wxBitmapButton* bitmapButton = new wxBitmapButton(
                                    this, buttonId, bitmap, wxDefaultPosition,
                                    wxSize( BUTT_SIZE_X+8, BUTT_SIZE_Y+6 ) );
            bitmapButton->SetClientData( (void*) buttons );

            rowBoxSizer->Add( bitmapButton, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT | wxBOTTOM, 5 );

            label = new wxStaticText( this, wxID_ANY, wxGetTranslation( buttons->m_Name ) );
            rowBoxSizer->Add( label, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT | wxBOTTOM, 5 );
            buttonId += 1;
            buttons++;
            */
        }

        groups++;
    }

    //TODO - Link to EDA_DRAW_FRAME

    /*
    COLOR4D bgColor = GetDrawFrame()->GetDrawBgColor();
    wxMemoryDC iconDC;
    wxBitmap   bitmap( BUTT_SIZE_X, BUTT_SIZE_Y );

    iconDC.SelectObject( bitmap );
    iconDC.SetPen( *wxBLACK_PEN );

    wxBrush brush;
    brush.SetColour( bgColor.ToColour() );
    brush.SetStyle( wxBRUSHSTYLE_SOLID );
    iconDC.SetBrush( brush );
    iconDC.DrawRectangle( 0, 0, BUTT_SIZE_X, BUTT_SIZE_Y );

    buttonId++;
    wxBitmapButton* selBgColorBtn = new wxBitmapButton(
                            this, buttonId, bitmap, wxDefaultPosition,
                            wxSize( BUTT_SIZE_X + 8, BUTT_SIZE_Y + 6 ) );
    selBgColorBtn->SetClientData( (void*) &bgColorButton );

    Connect( 1800, buttonId, wxEVT_COMMAND_BUTTON_CLICKED,
             wxCommandEventHandler( WIDGET_EESCHEMA_COLOR_CONFIG::SetColor ) );



    wxStaticText* bgColorLabel = new wxStaticText( this, wxID_ANY, _( "Background Color" ) );
    wxFont font( bgColorLabel->GetFont() );
    font.SetWeight( wxFONTWEIGHT_BOLD );
    bgColorLabel->SetFont( font );


    if( columnBoxSizer )
    {
        // Add a spacer to improve appearance.
        columnBoxSizer->AddSpacer( 5 );
        columnBoxSizer->Add( bgColorLabel, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5 );
        columnBoxSizer->Add( selBgColorBtn, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT | wxBOTTOM, 5 );
    }

    currentColors[ SCH_LAYER_INDEX( LAYER_SCHEMATIC_BACKGROUND ) ] = bgColor;

    */
}

void PANEL_PREF_EESCHEMA_COLOR_CONFIG::TransferDataToPanel()
{

}

void PANEL_PREF_EESCHEMA_COLOR_CONFIG::TransferDataFromPanel()
{

}
