///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PANEL_PREF_ENV_VAR_BASE_H__
#define __PANEL_PREF_ENV_VAR_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class PANEL_PREF;

#include "panel_pref_base.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

#define ID_BUTTON_ADD_PATH 1000
#define ID_BUTTON_EDIT_PATH 1001
#define ID_BUTTON_DELETE_PATH 1002
#define ID_BUTTOM_HELP 1003

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_ENV_VAR_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_ENV_VAR_BASE : public PANEL_PREF
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_kiprjmod;
		wxListCtrl* m_pathList;
		wxButton* m_addPathButton;
		wxButton* m_editPathButton;
		wxButton* m_deletePathButton;
		wxButton* m_helpButon;
		wxStaticText* m_pathDescription;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPathSelected( wxListEvent& event ) { event.Skip(); }
		virtual void OnAddButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelpButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PANEL_PREF_ENV_VAR_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 818,480 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_ENV_VAR_BASE();
	
};

#endif //__PANEL_PREF_ENV_VAR_BASE_H__
