#pragma once
#include <wx/wx.h>
#include <wx/listbox.h>

class ImageSelectionDialog : public wxDialog
{
    wxListBox* m_listBox;
public:
    ImageSelectionDialog(wxWindow* parent, const wxArrayString& images);
    wxArrayInt GetSelectedImages() const;
};
