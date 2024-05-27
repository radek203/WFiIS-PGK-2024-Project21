#include "ImageButton.h"

ImageButton::ImageButton(GUIMyFrame1* _frame, wxScrolledWindow* m_scrolledWindowPhotos, const wxBitmap& bitmap, wxString _path) : wxBitmapButton(m_scrolledWindowPhotos, -1, bitmap)
{
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(ImageButton::OnMouseLeftDown));
	Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(ImageButton::OnMouseDoubleDown));
	frame = _frame;
	path = _path;
}

void ImageButton::OnMouseLeftDown(wxMouseEvent& event)
{
	frame->DisplayMetaData(path);
}

void ImageButton::OnMouseDoubleDown(wxMouseEvent& event)
{
	frame->DisplayBigImg(path);
}
