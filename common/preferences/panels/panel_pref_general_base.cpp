///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_pref_general_base.h"

///////////////////////////////////////////////////////////////////////////

PANEL_PREF_GENERAL_BASE::PANEL_PREF_GENERAL_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_languageOptions = new wxStaticText( this, wxID_ANY, wxT("Language"), wxDefaultPosition, wxDefaultSize, 0 );
	m_languageOptions->Wrap( -1 );
	fgSizer2->Add( m_languageOptions, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboSelectLanguage = new wxBitmapComboBox( this, wxID_ANY, wxT("Language"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	fgSizer2->Add( m_comboSelectLanguage, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("<language warning here>"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer2->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Text editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer2->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonSelectTextEditor = new wxButton( this, ID_BUTT_SELECT_TEXT_EDITOR, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_buttonSelectTextEditor, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("PDF viewer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer2->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_pdfViewerChoiceChoices;
	m_pdfViewerChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_pdfViewerChoiceChoices, 0 );
	m_pdfViewerChoice->SetSelection( 0 );
	fgSizer2->Add( m_pdfViewerChoice, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_pdfViewerInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_pdfViewerInput, 0, wxALL|wxEXPAND, 5 );
	
	m_buttonSelectPdfViewer = new wxButton( this, ID_BUTT_SELECT_PDF_VIEWER, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_buttonSelectPdfViewer, 0, wxALL, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_optShowIconsInMenus = new wxCheckBox( this, ID_OPT_SHOW_ICONS_IN_MENUS, wxT("Show icons in menus"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_optShowIconsInMenus, 0, wxALL, 5 );
	
	
	bSizer1->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_buttonSelectTextEditor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnSelectTextEditor ), NULL, this );
	m_buttonSelectPdfViewer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnSelectPdfViewer ), NULL, this );
	m_optShowIconsInMenus->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnToggleShowItems ), NULL, this );
}

PANEL_PREF_GENERAL_BASE::~PANEL_PREF_GENERAL_BASE()
{
	// Disconnect Events
	m_buttonSelectTextEditor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnSelectTextEditor ), NULL, this );
	m_buttonSelectPdfViewer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnSelectPdfViewer ), NULL, this );
	m_optShowIconsInMenus->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PANEL_PREF_GENERAL_BASE::OnToggleShowItems ), NULL, this );
	
}
