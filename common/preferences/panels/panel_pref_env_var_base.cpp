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
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Project paths") ), wxVERTICAL );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("KIPRJMOD"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer51->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_kiprjmod = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_kiprjmod->Enable( false );
	m_kiprjmod->SetToolTip( wxT("Path to the current project") );
	
	bSizer51->Add( m_kiprjmod, 1, wxALL, 5 );
	
	
	sbSizer1->Add( bSizer51, 1, wxEXPAND, 5 );
	
	
	bSizer5->Add( sbSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Global paths") ), wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_pathList = new wxListCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VRULES );
	bSizer7->Add( m_pathList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_addPathButton = new wxButton( sbSizer2->GetStaticBox(), ID_BUTTON_ADD_PATH, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addPathButton->SetToolTip( wxT("Add path prefix") );
	
	bSizer6->Add( m_addPathButton, 0, wxALL, 5 );
	
	m_editPathButton = new wxButton( sbSizer2->GetStaticBox(), ID_BUTTON_EDIT_PATH, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_editPathButton->SetToolTip( wxT("Edit selected path prefix") );
	
	bSizer6->Add( m_editPathButton, 0, wxALL, 5 );
	
	m_deletePathButton = new wxButton( sbSizer2->GetStaticBox(), ID_BUTTON_DELETE_PATH, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	m_deletePathButton->SetToolTip( wxT("Remove selected path prefix") );
	
	bSizer6->Add( m_deletePathButton, 0, wxALL, 5 );
	
	
	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_helpButon = new wxButton( sbSizer2->GetStaticBox(), ID_BUTTOM_HELP, wxT("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helpButon->SetToolTip( wxT("Path prefix help") );
	
	bSizer6->Add( m_helpButon, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer6, 0, wxEXPAND, 5 );
	
	
	sbSizer2->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	bSizer5->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	// Connect Events
	m_pathList->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( PANEL_PREF_ENV_VAR_BASE::OnPathActivated ), NULL, this );
	m_pathList->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( PANEL_PREF_ENV_VAR_BASE::OnPathSelected ), NULL, this );
	m_addPathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnAddButton ), NULL, this );
	m_editPathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnEditButton ), NULL, this );
	m_deletePathButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnRemoveButton ), NULL, this );
	m_helpButon->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnHelpButton ), NULL, this );
}

PANEL_PREF_ENV_VAR_BASE::~PANEL_PREF_ENV_VAR_BASE()
{
	// Disconnect Events
	m_pathList->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( PANEL_PREF_ENV_VAR_BASE::OnPathActivated ), NULL, this );
	m_pathList->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( PANEL_PREF_ENV_VAR_BASE::OnPathSelected ), NULL, this );
	m_addPathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnAddButton ), NULL, this );
	m_editPathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnEditButton ), NULL, this );
	m_deletePathButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnRemoveButton ), NULL, this );
	m_helpButon->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PANEL_PREF_ENV_VAR_BASE::OnHelpButton ), NULL, this );
	
}
