#include "IPTCCheckboxDialog.h"

IPTCCheckboxDialog::IPTCCheckboxDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("Select IPTC Fields"), wxDefaultPosition, wxDefaultSize)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    m_checkTitle = new wxCheckBox(this, ID_IPTC_TITLE, wxT("Title"));
    m_checkDate = new wxCheckBox(this, ID_IPTC_DATE, wxT("Date Created"));
    m_checkCity = new wxCheckBox(this, ID_IPTC_CITY, wxT("City"));
    m_checkCountry = new wxCheckBox(this, ID_IPTC_COUNTRY, wxT("Country"));
    m_checkAuthor = new wxCheckBox(this, ID_IPTC_AUTHOR, wxT("Author"));
    m_checkKeywords = new wxCheckBox(this, ID_IPTC_KEYWORDS, wxT("Keywords"));
    m_checkEXIF = new wxCheckBox(this, ID_EXIF, wxT("EXIF"));

    mainSizer->Add(m_checkTitle, 0, wxALL, 5);
    mainSizer->Add(m_checkDate, 0, wxALL, 5);
    mainSizer->Add(m_checkCity, 0, wxALL, 5);
    mainSizer->Add(m_checkCountry, 0, wxALL, 5);
    mainSizer->Add(m_checkAuthor, 0, wxALL, 5);
    mainSizer->Add(m_checkKeywords, 0, wxALL, 5);
    mainSizer->Add(m_checkEXIF, 0, wxALL, 5);

    mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL | wxALIGN_CENTER, 10);

    SetSizerAndFit(mainSizer);
}

std::vector<int> IPTCCheckboxDialog::GetCheckedItems() const
{
    std::vector<int> checkedItems;
    if (m_checkTitle->IsChecked())
        checkedItems.push_back(ID_IPTC_TITLE);
    if (m_checkDate->IsChecked())
        checkedItems.push_back(ID_IPTC_DATE);
    if (m_checkCity->IsChecked())
        checkedItems.push_back(ID_IPTC_CITY);
    if (m_checkCountry->IsChecked())
        checkedItems.push_back(ID_IPTC_COUNTRY);
    if (m_checkAuthor->IsChecked())
        checkedItems.push_back(ID_IPTC_AUTHOR);
    if (m_checkKeywords->IsChecked())
        checkedItems.push_back(ID_IPTC_KEYWORDS);
    if (m_checkEXIF->IsChecked())
        checkedItems.push_back(ID_EXIF);

    return checkedItems;
}
