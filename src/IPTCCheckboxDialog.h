#pragma once
#include <wx/wx.h>
#include <wx/dialog.h>
#include <vector>

enum
{
    ID_IPTC_TITLE = wxID_HIGHEST + 1,
    ID_IPTC_DATE,
    ID_IPTC_CITY,
    ID_IPTC_COUNTRY,
    ID_IPTC_AUTHOR,
    ID_IPTC_KEYWORDS,
    ID_EXIF
};

class IPTCCheckboxDialog : public wxDialog
{
    wxCheckBox* m_checkTitle;
    wxCheckBox* m_checkDate;
    wxCheckBox* m_checkCity;
    wxCheckBox* m_checkCountry;
    wxCheckBox* m_checkAuthor;
    wxCheckBox* m_checkKeywords;
    wxCheckBox* m_checkEXIF;
public:
    IPTCCheckboxDialog(wxWindow* parent);
    std::vector<int> GetCheckedItems() const;
};
