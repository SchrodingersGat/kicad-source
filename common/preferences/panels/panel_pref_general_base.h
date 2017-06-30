///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PANEL_PREF_GENERAL_BASE_H__
#define __PANEL_PREF_GENERAL_BASE_H__

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
#include <wx/bmpcbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

#define ID_BUTT_SELECT_TEXT_EDITOR 1000
#define ID_BUTT_SELECT_PDF_VIEWER 1001
#define ID_OPT_SHOW_ICONS_IN_MENUS 1002

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_GENERAL_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_GENERAL_BASE : public PANEL_PREF
{
	private:
	
	protected:
		wxStaticText* m_languageOptions;
		wxBitmapComboBox* m_comboSelectLanguage;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_buttonSelectTextEditor;
		wxStaticText* m_staticText3;
		wxChoice* m_pdfViewerChoice;
		wxTextCtrl* m_pdfViewerInput;
		wxButton* m_buttonSelectPdfViewer;
		wxCheckBox* m_optShowIconsInMenus;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectTextEditor( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPdfViewer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggleShowItems( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PANEL_PREF_GENERAL_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_GENERAL_BASE();
	
};

#endif //__PANEL_PREF_GENERAL_BASE_H__
