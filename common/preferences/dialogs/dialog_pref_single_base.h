///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_PREF_SINGLE_BASE_H__
#define __DIALOG_PREF_SINGLE_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class DIALOG_SHIM;

#include "dialog_shim.h"
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/statline.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_PREF_SINGLE_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_PREF_SINGLE_BASE : public DIALOG_SHIM
{
	private:
	
	protected:
		wxBoxSizer* m_panelSizer;
		wxStaticLine* m_staticline1;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		
		DIALOG_PREF_SINGLE_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 559,157 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~DIALOG_PREF_SINGLE_BASE();
	
};

#endif //__DIALOG_PREF_SINGLE_BASE_H__
