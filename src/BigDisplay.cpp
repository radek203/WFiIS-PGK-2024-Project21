#include "BigDisplay.h"

BigDisplay::BigDisplay(GUIMyFrame1* _frame, wxString _path, wxPanel* m_panelFullDisplay, const wxSize& pos) : wxPanel(m_panelFullDisplay, -1, wxPoint(0, 0), pos), frame(_frame), path(_path)
{
	Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(BigDisplay::OnPanelDoubleDown));
	img = wxImage(path, wxBITMAP_TYPE_ANY, -1);
	m_panelFullDisplay->Show();
	PaintBigDisplay();
}

wxString BigDisplay::getPath() const
{
	return path;
}

void BigDisplay::OnPanelDoubleDown(wxMouseEvent& event)
{
	frame->DisplayFolder();
}

void BigDisplay::PaintBigDisplay()
{
	int w = GetSize().GetWidth();
	int h = GetSize().GetHeight();
	int img_w = img.GetWidth();
	int img_h = img.GetHeight();
	double scale_h = (double)h / img_h;
	double scale_x = (double)w / img_w;
	if (img_w > w || img_h > h) {
		if (scale_h < scale_x) {
			img.Rescale(floor(scale_h * img_w), floor(img_h * scale_h), wxIMAGE_QUALITY_NEAREST);
		}
		else {
			img.Rescale(floor(img_w * scale_x), floor(img_h * scale_x), wxIMAGE_QUALITY_NEAREST);
		}
	}
	wxBitmap bitmap(img, -1);
	wxClientDC dc(this);
	dc.SetBackground(wxColour(255, 229, 204));
	dc.Clear();
	dc.DrawBitmap(bitmap, (w - img.GetWidth()) / 2, (h - img.GetHeight()) / 2);
}

void BigDisplay::RotateImage()
{
	img = img.Copy().Rotate90(true);

	PaintBigDisplay();
}
