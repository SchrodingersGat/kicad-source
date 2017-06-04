///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_pref_schematic_base.h"

///////////////////////////////////////////////////////////////////////////

PANEL_PREF_SCHEMATIC_DISPLAY_BASE::PANEL_PREF_SCHEMATIC_DISPLAY_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer32;
	fgSizer32 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer32->AddGrowableCol( 0 );
	fgSizer32->AddGrowableCol( 1 );
	fgSizer32->AddGrowableCol( 2 );
	fgSizer32->SetFlexibleDirection( wxBOTH );
	fgSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("&Grid size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer32->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	wxArrayString m_choiceGridSizeChoices;
	m_choiceGridSize = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceGridSizeChoices, 0 );
	m_choiceGridSize->SetSelection( 0 );
	fgSizer32->Add( m_choiceGridSize, 0, wxEXPAND|wxALL, 3 );
	
	m_staticGridUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticGridUnits->Wrap( -1 );
	fgSizer32->Add( m_staticGridUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("&Bus thickness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer32->Add( m_staticText51, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinBusWidth = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, 1, 100, 1 );
	fgSizer32->Add( m_spinBusWidth, 0, wxALL|wxEXPAND, 3 );
	
	m_staticBusWidthUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticBusWidthUnits->Wrap( -1 );
	fgSizer32->Add( m_staticBusWidthUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("&Line thickness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer32->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinLineWidth = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, 1, 100, 1 );
	fgSizer32->Add( m_spinLineWidth, 0, wxALL|wxEXPAND, 3 );
	
	m_staticLineWidthUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLineWidthUnits->Wrap( -1 );
	fgSizer32->Add( m_staticLineWidthUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("&Part ID notation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer32->Add( m_staticText26, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 3 );
	
	wxString m_choiceSeparatorRefIdChoices[] = { _("A"), _(".A"), _("-A"), _("_A"), _(".1"), _("-1"), _("_1") };
	int m_choiceSeparatorRefIdNChoices = sizeof( m_choiceSeparatorRefIdChoices ) / sizeof( wxString );
	m_choiceSeparatorRefId = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSeparatorRefIdNChoices, m_choiceSeparatorRefIdChoices, 0 );
	m_choiceSeparatorRefId->SetSelection( 0 );
	fgSizer32->Add( m_choiceSeparatorRefId, 0, wxALL|wxEXPAND, 3 );
	
	
	fgSizer32->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer82->Add( fgSizer32, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer92->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	m_checkShowGrid = new wxCheckBox( this, wxID_ANY, _("&Show grid"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( m_checkShowGrid, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 3 );
	
	m_checkHVOrientation = new wxCheckBox( this, wxID_ANY, _("&Restrict buses and wires to H and V orientation"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( m_checkHVOrientation, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 3 );
	
	m_checkShowHiddenPins = new wxCheckBox( this, wxID_ANY, _("S&how hidden pins"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( m_checkShowHiddenPins, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 3 );
	
	m_checkPageLimits = new wxCheckBox( this, wxID_ANY, _("Show page limi&ts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkPageLimits->SetValue(true); 
	bSizer92->Add( m_checkPageLimits, 0, wxEXPAND|wxLEFT|wxTOP|wxRIGHT, 3 );
	
	
	bSizer82->Add( bSizer92, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer82 );
	this->Layout();
}

PANEL_PREF_SCHEMATIC_DISPLAY_BASE::~PANEL_PREF_SCHEMATIC_DISPLAY_BASE()
{
}

BEGIN_EVENT_TABLE( PANEL_PREF_SCHEMATIC_EDITING_BASE, PANEL_PREF )
	EVT_CHOICE( wxID_ANY, PANEL_PREF_SCHEMATIC_EDITING_BASE::_wxFB_OnChooseUnits )
END_EVENT_TABLE()

PANEL_PREF_SCHEMATIC_EDITING_BASE::PANEL_PREF_SCHEMATIC_EDITING_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableCol( 2 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("&Measurement units:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer3->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	wxArrayString m_choiceUnitsChoices;
	m_choiceUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitsChoices, 0 );
	m_choiceUnits->SetSelection( 0 );
	fgSizer3->Add( m_choiceUnits, 0, wxALL|wxEXPAND, 3 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 3 );
	
	m_staticTextHpitch = new wxStaticText( this, wxID_ANY, _("&Horizontal pitch of repeated items:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHpitch->Wrap( -1 );
	fgSizer3->Add( m_staticTextHpitch, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinRepeatHorizontal = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, -5000, 5000, 0 );
	fgSizer3->Add( m_spinRepeatHorizontal, 0, wxALL|wxEXPAND, 3 );
	
	m_staticRepeatXUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRepeatXUnits->Wrap( -1 );
	fgSizer3->Add( m_staticRepeatXUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticTextVpitch = new wxStaticText( this, wxID_ANY, _("&Vertical pitch of repeated items:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextVpitch->Wrap( -1 );
	fgSizer3->Add( m_staticTextVpitch, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinRepeatVertical = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, -5000, 5000, 100 );
	fgSizer3->Add( m_spinRepeatVertical, 0, wxALL|wxEXPAND, 3 );
	
	m_staticRepeatYUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRepeatYUnits->Wrap( -1 );
	fgSizer3->Add( m_staticRepeatYUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("&Increment of repeated labels:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer3->Add( m_staticText16, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinRepeatLabel = new wxSpinCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, -10, 10, 1 );
	fgSizer3->Add( m_spinRepeatLabel, 0, wxALL|wxEXPAND, 3 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 3 );
	
	m_staticTextTsize = new wxStaticText( this, wxID_ANY, _("Def&ault text size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTsize->Wrap( -1 );
	fgSizer3->Add( m_staticTextTsize, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinTextSize = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, 0, 1000, 0 );
	fgSizer3->Add( m_spinTextSize, 0, wxALL|wxEXPAND, 3 );
	
	m_staticTextSizeUnits = new wxStaticText( this, wxID_ANY, _("mils"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSizeUnits->Wrap( -1 );
	fgSizer3->Add( m_staticTextSizeUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_staticTextTimeInterval = new wxStaticText( this, wxID_ANY, _("&Auto-save time interval"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTimeInterval->Wrap( -1 );
	fgSizer3->Add( m_staticTextTimeInterval, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	m_spinAutoSaveInterval = new wxSpinCtrl( this, ID_M_SPINAUTOSAVEINTERVAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 10 );
	m_spinAutoSaveInterval->SetToolTip( _("Delay after the first change to create a backup file of the board on disk.\nIf set to 0, auto backup is disabled") );
	
	fgSizer3->Add( m_spinAutoSaveInterval, 0, wxALL|wxEXPAND, 3 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 3 );
	
	
	bSizer8->Add( fgSizer3, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	m_checkAutoplaceFields = new wxCheckBox( this, wxID_ANY, _("A&utomatically place component fields"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_checkAutoplaceFields, 0, wxEXPAND|wxLEFT|wxTOP|wxRIGHT, 3 );
	
	m_checkAutoplaceJustify = new wxCheckBox( this, wxID_ANY, _("A&llow field autoplace to change justification"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_checkAutoplaceJustify, 0, wxEXPAND|wxLEFT|wxTOP|wxRIGHT, 3 );
	
	m_checkAutoplaceAlign = new wxCheckBox( this, wxID_ANY, _("Al&ways align autoplaced fields to the 50 mil grid"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_checkAutoplaceAlign, 0, wxEXPAND|wxLEFT|wxTOP|wxRIGHT, 3 );
	
	
	bSizer8->Add( bSizer9, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
}

PANEL_PREF_SCHEMATIC_EDITING_BASE::~PANEL_PREF_SCHEMATIC_EDITING_BASE()
{
}

PANEL_PREF_SCHEMATIC_CONTROLS_BASE::PANEL_PREF_SCHEMATIC_CONTROLS_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer31;
	fgSizer31 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer31->AddGrowableCol( 0 );
	fgSizer31->AddGrowableCol( 1 );
	fgSizer31->AddGrowableCol( 2 );
	fgSizer31->SetFlexibleDirection( wxBOTH );
	fgSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	bSizer81->Add( fgSizer31, 0, wxALL|wxEXPAND, 5 );
	
	m_controlsSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Hotkeys:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer13->Add( m_staticText20, 1, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Double-click to edit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer13->Add( m_staticText21, 0, wxALL, 5 );
	
	
	m_controlsSizer->Add( bSizer13, 0, wxEXPAND, 5 );
	
	m_panelHotkeys = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_controlsSizer->Add( m_panelHotkeys, 1, wxEXPAND | wxALL, 5 );
	
	m_checkEnableZoomCenter = new wxCheckBox( this, wxID_ANY, _("Cen&ter and warp cursor on zoom"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkEnableZoomCenter->SetToolTip( _("Keep the cursor at its current location when zooming") );
	
	m_controlsSizer->Add( m_checkEnableZoomCenter, 0, wxTOP|wxRIGHT|wxLEFT, 3 );
	
	m_checkEnableMousewheelPan = new wxCheckBox( this, xwID_ANY, _("Use touchpa&d to pan"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkEnableMousewheelPan->SetToolTip( _("Use touchpad to pan canvas") );
	
	m_controlsSizer->Add( m_checkEnableMousewheelPan, 0, wxLEFT|wxRIGHT|wxTOP, 3 );
	
	m_checkAutoPan = new wxCheckBox( this, wxID_ANY, _("&Pan while moving object"), wxDefaultPosition, wxDefaultSize, 0 );
	m_controlsSizer->Add( m_checkAutoPan, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 3 );
	
	
	bSizer81->Add( m_controlsSizer, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer81 );
	this->Layout();
}

PANEL_PREF_SCHEMATIC_CONTROLS_BASE::~PANEL_PREF_SCHEMATIC_CONTROLS_BASE()
{
}

PANEL_PREF_SCHEMATIC_COLORS_BASE::PANEL_PREF_SCHEMATIC_COLORS_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_panelColors = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer14->Add( m_panelColors, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer14 );
	this->Layout();
}

PANEL_PREF_SCHEMATIC_COLORS_BASE::~PANEL_PREF_SCHEMATIC_COLORS_BASE()
{
}

BEGIN_EVENT_TABLE( PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS, PANEL_PREF )
	EVT_BUTTON( wxID_ADD_FIELD, PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS::_wxFB_OnAddButtonClick )
	EVT_BUTTON( wxID_DELETE_FIELD, PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS::_wxFB_OnDeleteButtonClick )
END_EVENT_TABLE()

PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS::PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_fieldGrid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_fieldGrid->CreateGrid( 0, 3 );
	m_fieldGrid->EnableEditing( true );
	m_fieldGrid->EnableGridLines( true );
	m_fieldGrid->EnableDragGridSize( false );
	m_fieldGrid->SetMargins( 0, 0 );
	
	// Columns
	m_fieldGrid->SetColSize( 0, 150 );
	m_fieldGrid->SetColSize( 1, 150 );
	m_fieldGrid->SetColSize( 2, 75 );
	m_fieldGrid->EnableDragColMove( false );
	m_fieldGrid->EnableDragColSize( true );
	m_fieldGrid->SetColLabelSize( 30 );
	m_fieldGrid->SetColLabelValue( 0, _("Name") );
	m_fieldGrid->SetColLabelValue( 1, _("Default Value") );
	m_fieldGrid->SetColLabelValue( 2, _("Visible") );
	m_fieldGrid->SetColLabelValue( 3, _("Name") );
	m_fieldGrid->SetColLabelValue( 4, wxEmptyString );
	m_fieldGrid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_fieldGrid->EnableDragRowSize( true );
	m_fieldGrid->SetRowLabelSize( 80 );
	m_fieldGrid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_fieldGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_fieldGrid, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer6->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	addFieldButton = new wxButton( this, wxID_ADD_FIELD, _("&Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( addFieldButton, 0, wxALL|wxEXPAND, 5 );
	
	deleteFieldButton = new wxButton( this, wxID_DELETE_FIELD, _("De&lete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( deleteFieldButton, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer6->Add( bSizer10, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer6 );
	this->Layout();
}

PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS::~PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS()
{
}
