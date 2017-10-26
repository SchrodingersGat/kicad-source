///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_KEEPOUT_AREA_PROPERTIES_BASE_H__
#define __DIALOG_KEEPOUT_AREA_PROPERTIES_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class DIALOG_SHIM;

#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/dataview.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_KEEPOUT_AREA_PROPERTIES_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_KEEPOUT_AREA_PROPERTIES_BASE : public DIALOG_SHIM
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnLayerSelection( wxDataViewEvent& event ){ OnLayerSelection( event ); }
		
	
	protected:
		wxBoxSizer* m_layersListSizer;
		wxStaticText* m_staticTextLayerSelection;
		wxDataViewListCtrl* m_layers;
		wxStaticText* m_staticTextprops;
		wxRadioBox* m_OrientEdgesOpt;
		wxRadioBox* m_OutlineAppearanceCtrl;
		wxCheckBox* m_cbTracksCtrl;
		wxCheckBox* m_cbViasCtrl;
		wxCheckBox* m_cbCopperPourCtrl;
		wxStaticLine* m_staticline1;
		wxStdDialogButtonSizer* m_sdbSizerButtons;
		wxButton* m_sdbSizerButtonsOK;
		wxButton* m_sdbSizerButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLayerSelection( wxDataViewEvent& event ) { event.Skip(); }
		
	
	public:
		
		DIALOG_KEEPOUT_AREA_PROPERTIES_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Keepout Area Properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 650,402 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxFULL_REPAINT_ON_RESIZE|wxSUNKEN_BORDER ); 
		~DIALOG_KEEPOUT_AREA_PROPERTIES_BASE();
	
};

#endif //__DIALOG_KEEPOUT_AREA_PROPERTIES_BASE_H__
