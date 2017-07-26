///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_ENV_VAR_SINGLE_BASE_H__
#define __DIALOG_ENV_VAR_SINGLE_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class DIALOG_SHIM;

#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_ENV_VAR_SINGLE_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_ENV_VAR_SINGLE_BASE : public DIALOG_SHIM
{
	private:
	
	protected:
		wxStaticText* m_envVarNameLabel;
		wxTextCtrl* m_envVarName;
		wxStaticText* m_envVarPathLabel;
		wxTextCtrl* m_envVarPath;
		wxBitmapButton* m_selectPathButton;
		wxStaticLine* m_staticline1;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectPath( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DIALOG_ENV_VAR_SINGLE_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Set Environment Path"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 431,176 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DIALOG_ENV_VAR_SINGLE_BASE();
	
};

#endif //__DIALOG_ENV_VAR_SINGLE_BASE_H__
