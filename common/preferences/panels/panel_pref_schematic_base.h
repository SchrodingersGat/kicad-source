///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PANEL_PREF_SCHEMATIC_BASE_H__
#define __PANEL_PREF_SCHEMATIC_BASE_H__

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
#include <wx/grid.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_SCHEMATIC_DISPLAY_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_SCHEMATIC_DISPLAY_BASE : public PANEL_PREF
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxChoice* m_choiceGridSize;
		wxStaticText* m_staticGridUnits;
		wxStaticText* m_staticText51;
		wxSpinCtrl* m_spinBusWidth;
		wxStaticText* m_staticBusWidthUnits;
		wxStaticText* m_staticText5;
		wxSpinCtrl* m_spinLineWidth;
		wxStaticText* m_staticLineWidthUnits;
		wxStaticText* m_staticText26;
		wxChoice* m_choiceSeparatorRefId;
		wxStaticLine* m_staticline3;
		wxCheckBox* m_checkShowGrid;
		wxCheckBox* m_checkHVOrientation;
		wxCheckBox* m_checkShowHiddenPins;
		wxCheckBox* m_checkPageLimits;
	
	public:
		
		PANEL_PREF_SCHEMATIC_DISPLAY_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_SCHEMATIC_DISPLAY_BASE();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_SCHEMATIC_EDITING_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_SCHEMATIC_EDITING_BASE : public PANEL_PREF
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnChooseUnits( wxCommandEvent& event ){ OnChooseUnits( event ); }
		
	
	protected:
		enum
		{
			ID_M_SPINAUTOSAVEINTERVAL = 1000
		};
		
		wxStaticText* m_staticText2;
		wxChoice* m_choiceUnits;
		wxStaticText* m_staticTextHpitch;
		wxSpinCtrl* m_spinRepeatHorizontal;
		wxStaticText* m_staticRepeatXUnits;
		wxStaticText* m_staticTextVpitch;
		wxSpinCtrl* m_spinRepeatVertical;
		wxStaticText* m_staticRepeatYUnits;
		wxStaticText* m_staticText16;
		wxSpinCtrl* m_spinRepeatLabel;
		wxStaticText* m_staticTextTsize;
		wxSpinCtrl* m_spinTextSize;
		wxStaticText* m_staticTextSizeUnits;
		wxStaticText* m_staticTextTimeInterval;
		wxSpinCtrl* m_spinAutoSaveInterval;
		wxStaticText* m_staticText23;
		wxStaticLine* m_staticline2;
		wxCheckBox* m_checkAutoplaceFields;
		wxCheckBox* m_checkAutoplaceJustify;
		wxCheckBox* m_checkAutoplaceAlign;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChooseUnits( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PANEL_PREF_SCHEMATIC_EDITING_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,342 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_SCHEMATIC_EDITING_BASE();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_SCHEMATIC_CONTROLS_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_SCHEMATIC_CONTROLS_BASE : public PANEL_PREF
{
	private:
	
	protected:
		enum
		{
			xwID_ANY = 1000
		};
		
		wxBoxSizer* m_controlsSizer;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText21;
		wxPanel* m_panelHotkeys;
		wxCheckBox* m_checkEnableZoomCenter;
		wxCheckBox* m_checkEnableMousewheelPan;
		wxCheckBox* m_checkAutoPan;
	
	public:
		
		PANEL_PREF_SCHEMATIC_CONTROLS_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_SCHEMATIC_CONTROLS_BASE();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_SCHEMATIC_COLORS_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_SCHEMATIC_COLORS_BASE : public PANEL_PREF
{
	private:
	
	protected:
		wxPanel* m_panelColors;
	
	public:
		
		PANEL_PREF_SCHEMATIC_COLORS_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_SCHEMATIC_COLORS_BASE();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS
///////////////////////////////////////////////////////////////////////////////
class PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS : public PANEL_PREF
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddButtonClick( wxCommandEvent& event ){ OnAddButtonClick( event ); }
		void _wxFB_OnDeleteButtonClick( wxCommandEvent& event ){ OnDeleteButtonClick( event ); }
		
	
	protected:
		enum
		{
			wxID_ADD_FIELD = 1000,
			wxID_DELETE_FIELD
		};
		
		wxGrid* m_fieldGrid;
		wxButton* addFieldButton;
		wxButton* deleteFieldButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_PREF_SCHEMATIC_DEFAULT_FIELDS();
	
};

#endif //__PANEL_PREF_SCHEMATIC_BASE_H__
