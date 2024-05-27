#pragma once

#include "GUIMyFrame1.h"

class GUIMyFrame1;

class BigDisplay : public wxPanel {
	GUIMyFrame1* frame;
	wxImage img;
	wxString path;

	wxString getPath() const;
	void OnPanelDoubleDown(wxMouseEvent& event);
	void PaintBigDisplay();
	void RotateImage();
public:
	BigDisplay(GUIMyFrame1* _frame, wxString _path, wxPanel* m_panelFullDisplay, const wxSize& pos = wxDefaultSize);

	friend class ImageButton;
	friend class GUIMyFrame1;
};
