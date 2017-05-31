///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_pref_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_PREF_BASE::DIALOG_PREF_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter3 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( DIALOG_PREF_BASE::m_splitter3OnIdle ), NULL, this );
	
	m_treePanel = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_prefTree = new wxTreeCtrl( m_treePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_HIDE_ROOT|wxTR_NO_LINES );
	bSizer12->Add( m_prefTree, 1, wxALL|wxEXPAND, 5 );
	
	
	m_treePanel->SetSizer( bSizer12 );
	m_treePanel->Layout();
	bSizer12->Fit( m_treePanel );
	m_rightPanel = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_prefBox = new wxStaticBoxSizer( new wxStaticBox( m_rightPanel, wxID_ANY, wxT("Preference Panel") ), wxVERTICAL );
	
	m_preferencePanel = new wxPanel( m_prefBox->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_prefBox->Add( m_preferencePanel, 1, wxEXPAND | wxALL, 5 );
	
	
	m_rightPanel->SetSizer( m_prefBox );
	m_rightPanel->Layout();
	m_prefBox->Fit( m_rightPanel );
	m_splitter3->SplitVertically( m_treePanel, m_rightPanel, 200 );
	bSizer10->Add( m_splitter3, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer10->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wx_okCancelButtonSizer = new wxStdDialogButtonSizer();
	wx_okCancelButtonSizerOK = new wxButton( this, wxID_OK );
	wx_okCancelButtonSizer->AddButton( wx_okCancelButtonSizerOK );
	wx_okCancelButtonSizerCancel = new wxButton( this, wxID_CANCEL );
	wx_okCancelButtonSizer->AddButton( wx_okCancelButtonSizerCancel );
	wx_okCancelButtonSizer->Realize();
	
	bSizer10->Add( wx_okCancelButtonSizer, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_prefTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( DIALOG_PREF_BASE::OnTreeSelectionChanged ), NULL, this );
	m_prefTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( DIALOG_PREF_BASE::OnTreeSelectionChanging ), NULL, this );
}

DIALOG_PREF_BASE::~DIALOG_PREF_BASE()
{
	// Disconnect Events
	m_prefTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( DIALOG_PREF_BASE::OnTreeSelectionChanged ), NULL, this );
	m_prefTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( DIALOG_PREF_BASE::OnTreeSelectionChanging ), NULL, this );
	
}
