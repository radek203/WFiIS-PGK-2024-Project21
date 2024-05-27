///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>

#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <map>
#include <wx/scrolbar.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxScrolledWindow* m_scrolledWindowPhotos;
	wxPanel* m_panelFullDisplay;

	wxGrid* m_gridIPTC;
	wxStaticText* m_staticTextMain;
	wxTextCtrl* m_textCtrlInfo;
	wxButton* m_buttonLoadFile;
	wxButton* m_buttonSaveTextAll;
	wxButton* m_buttonSaveText;
	wxButton* m_buttonSaveData;
	wxButton* m_buttonRotate;
	wxButton* m_buttonSaveIPTC;
	wxButton* m_buttonLoad;

	// Virtual event handlers, override them in your derived class
	virtual void MyFrame1OnSize(wxSizeEvent& event) { event.Skip(); }
	virtual void m_buttonLoadFileOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonSaveTextAllOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonSaveTextOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonSaveDataOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonRotateOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonSaveIPTCOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void m_buttonLoadOnButtonClick(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PGK-2024-Projekt21"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1300, 720), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};
