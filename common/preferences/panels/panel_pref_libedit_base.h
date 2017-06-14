///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PANEL_PREF_LIBEDIT_BASE_H__
#define __PANEL_PREF_LIBEDIT_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class PANEL_PREF;

#include "panel_pref_base.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/checkbox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_LIBEDIT_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_LIBEDIT_BASE : public PANEL_PREF
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxChoice* m_choiceGridSize;
		wxStaticText* m_staticGridUnits;
		wxStaticText* m_staticText5;
		wxSpinCtrl* m_spinLineWidth;
		wxStaticText* m_staticLineWidthUnits;
		wxStaticText* m_staticText52;
		wxSpinCtrl* m_spinPinLength;
		wxStaticText* m_staticPinLengthUnits;
		wxStaticText* m_staticText7;
		wxSpinCtrl* m_spinPinNumSize;
		wxStaticText* m_staticTextSizeUnits;
		wxStaticText* m_staticText9;
		wxSpinCtrl* m_spinPinNameSize;
		wxStaticText* m_staticRepeatXUnits;
		wxStaticText* m_staticText11;
		wxSpinCtrl* m_spinRepeatHorizontal;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxSpinCtrl* m_spinRepeatVertical;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxChoice* m_choicePinDisplacement;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxSpinCtrl* m_spinRepeatLabel;
		wxStaticLine* m_staticline3;
		wxCheckBox* m_checkShowGrid;
		wxCheckBox* m_checkShowPinElectricalType;
	
	public:
		
		PANEL_PREF_LIBEDIT_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 632,510 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_LIBEDIT_BASE();
	
};

#endif //__PANEL_PREF_LIBEDIT_BASE_H__