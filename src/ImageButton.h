#pragma once
#include "GUIMyFrame1.h"

class GUIMyFrame1;

class ImageButton : public wxBitmapButton
{
	GUIMyFrame1* frame;
	wxString path;

	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseDoubleDown(wxMouseEvent& event);
public:
	ImageButton(GUIMyFrame1* _frame, wxScrolledWindow* m_scrolledWindowPhotos, const wxBitmap& bitmap, wxString _path = wxEmptyString);

	friend class GUIMyFrame1;
	friend class BigDisplay;
};
