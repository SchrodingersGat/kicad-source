///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_pref_env_var_base.h"

///////////////////////////////////////////////////////////////////////////

PANEL_PREF_ENV_VAR_BASE::PANEL_PREF_ENV_VAR_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PANEL_PREF( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_pathList = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer7->Add( m_pathList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_addPathButton = new wxButton( this, ID_BUTTON_ADD_PATH, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addPathButton->SetToolTip( wxT("Add path prefix") );
	
	bSizer6->Add( m_addPathButton, 0, wxALL, 5 );
	
	m_editPathButton = new wxButton( this, ID_BUTTON_EDIT_PATH, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_editPathButton->SetToolTip( wxT("Edit selected path prefix") );
	
	bSizer6->Add( m_editPathButton, 0, wxALL, 5 );
	
	m_deletePathButton = new wxButton( this, ID_BUTTON_DELETE_PATH, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	m_deletePathButton->SetToolTip( wxT("Remove selected path prefix") );
	
	bSizer6->Add( m_deletePathButton, 0, wxALL, 5 );
	
	
	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_helpButon = new wxButton( this, ID_BUTTOM_HELP, wxT("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helpButon->SetToolTip( wxT("Path prefix help") );
	
	bSizer6->Add( m_helpButon, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer6, 0, wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	m_pathDescription = new wxStaticText( this, wxID_ANY, wxT("<Path description goes here>"), wxDefaultPosition, wxDefaultSize, 0 );
	m_pathDescription->Wrap( -1 );
	bSizer5->Add( m_pathDescription, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	// Connect Events
	m_addPathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnAddButton ), NULL, this );
	m_editPathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnEditButton ), NULL, this );
	m_deletePathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnRemoveButton ), NULL, this );
	m_helpButon->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnHelpButton ), NULL, this );
}

PANEL_PREF_ENV_VAR_BASE::~PANEL_PREF_ENV_VAR_BASE()
{
	// Disconnect Events
	m_addPathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnAddButton ), NULL, this );
	m_editPathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnEditButton ), NULL, this );
	m_deletePathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnRemoveButton ), NULL, this );
	m_helpButon->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnHelpButton ), NULL, this );
	
}
