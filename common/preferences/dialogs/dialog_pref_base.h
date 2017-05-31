///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_PREF_BASE_H__
#define __DIALOG_PREF_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class DIALOG_SHIM;

#include "dialog_shim.h"
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/splitter.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_PREF_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_PREF_BASE : public DIALOG_SHIM
{
	private:
	
	protected:
		wxSplitterWindow* m_splitter3;
		wxPanel* m_treePanel;
		wxTreeCtrl* m_prefTree;
		wxPanel* m_rightPanel;
		wxStaticBoxSizer* m_prefBox;
		wxPanel* m_preferencePanel;
		wxStaticLine* m_staticline1;
		wxStdDialogButtonSizer* wx_okCancelButtonSizer;
		wxButton* wx_okCancelButtonSizerOK;
		wxButton* wx_okCancelButtonSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTreeSelectionChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnTreeSelectionChanging( wxTreeEvent& event ) { event.Skip(); }
		
	
	public:
		
		DIALOG_PREF_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("KiCAD Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,400 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~DIALOG_PREF_BASE();
		
		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 200 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( DIALOG_PREF_BASE::m_splitter3OnIdle ), NULL, this );
		}
	
};

#endif //__DIALOG_PREF_BASE_H__
