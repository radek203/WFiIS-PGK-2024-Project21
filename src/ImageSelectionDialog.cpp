#include "ImageSelectionDialog.h"

ImageSelectionDialog::ImageSelectionDialog(wxWindow* parent, const wxArrayString& images) : wxDialog(parent, wxID_ANY, "Select Images", wxDefaultPosition, wxSize(400, 300))
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    m_listBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, images, wxLB_MULTIPLE);
    sizer->Add(m_listBox, 1, wxALL | wxEXPAND, 5);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(new wxButton(this, wxID_OK, "OK"), 0, wxALL, 5);
    buttonSizer->Add(new wxButton(this, wxID_CANCEL, "Cancel"), 0, wxALL, 5);
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER);

    SetSizerAndFit(sizer);
}

wxArrayInt ImageSelectionDialog::GetSelectedImages() const
{
    wxArrayInt selections;
    m_listBox->GetSelections(selections);

    return selections;
}
