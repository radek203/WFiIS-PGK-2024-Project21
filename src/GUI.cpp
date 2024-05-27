///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(1300, 720), wxDefaultSize);
	this->SetBackgroundColour(wxColour(255, 229, 204));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	m_scrolledWindowPhotos = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_scrolledWindowPhotos->SetScrollRate(5, 5);
	bSizer2->Add(m_scrolledWindowPhotos, 1, wxEXPAND | wxALL, 5);

	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);
	m_panelFullDisplay = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panelFullDisplay->SetBackgroundColour(wxColour(255, 255, 255));
	m_panelFullDisplay->Layout();
	bSizer4->Add(m_panelFullDisplay, 1, wxALL | wxEXPAND, 5);
	m_panelFullDisplay->Hide();

	bSizer1->Add(bSizer4, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	bSizer3->SetMinSize(wxSize(400, -1));
	m_gridIPTC = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	m_gridIPTC->SetMaxClientSize(wxSize(400, -1));

	// Grid
	m_gridIPTC->CreateGrid(6, 1);
	m_gridIPTC->EnableEditing(true);
	m_gridIPTC->EnableGridLines(true);
	m_gridIPTC->SetGridLineColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	m_gridIPTC->EnableDragGridSize(false);
	m_gridIPTC->SetMargins(0, 0);

	// Columns
	m_gridIPTC->SetColSize(0, 300);
	m_gridIPTC->EnableDragColMove(false);
	m_gridIPTC->EnableDragColSize(true);
	m_gridIPTC->SetColLabelValue(0, wxT("Values"));
	m_gridIPTC->SetColLabelSize(1);
	m_gridIPTC->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	m_gridIPTC->SetRowSize(0, 25);
	m_gridIPTC->SetRowSize(1, 25);
	m_gridIPTC->SetRowSize(2, 25);
	m_gridIPTC->SetRowSize(3, 25);
	m_gridIPTC->SetRowSize(4, 25);
	m_gridIPTC->SetRowSize(5, 25);
	m_gridIPTC->EnableDragRowSize(true);
	m_gridIPTC->SetRowLabelValue(0, wxT("Title"));
	m_gridIPTC->SetRowLabelValue(1, wxT("Release Date"));
	m_gridIPTC->SetRowLabelValue(2, wxT("City"));
	m_gridIPTC->SetRowLabelValue(3, wxT("Country"));
	m_gridIPTC->SetRowLabelValue(4, wxT("Author"));
	m_gridIPTC->SetRowLabelValue(5, wxT("Keywords"));
	m_gridIPTC->SetRowLabelSize(100);
	m_gridIPTC->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance
	m_gridIPTC->SetLabelBackgroundColour(wxColour(255, 204, 153));
	m_gridIPTC->SetLabelFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));
	m_gridIPTC->SetLabelTextColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));

	// Cell Defaults
	m_gridIPTC->SetDefaultCellBackgroundColour(wxColour(255, 204, 153));
	m_gridIPTC->SetDefaultCellFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));
	m_gridIPTC->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	m_gridIPTC->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Calibri")));
	m_gridIPTC->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	m_gridIPTC->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	m_gridIPTC->SetMinSize(wxSize(400, -1));
	m_gridIPTC->SetMaxSize(wxSize(400, -1));

	bSizer3->Add(m_gridIPTC, 0, wxEXPAND | wxALL, 5);

	m_staticTextMain = new wxStaticText(this, wxID_ANY, wxT("EXIF INFO:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextMain->Wrap(-1);
	m_staticTextMain->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_staticTextMain, 0, wxBOTTOM | wxRIGHT | wxLEFT, 5);

	m_textCtrlInfo = new wxTextCtrl(this, wxID_ANY, wxT("Empty"), wxDefaultPosition, wxDefaultSize, 0 | wxBORDER_NONE | wxTE_MULTILINE);
	m_textCtrlInfo->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));
	m_textCtrlInfo->SetBackgroundColour(wxColour(255, 229, 204));

	bSizer3->Add(m_textCtrlInfo, 1, wxALL | wxEXPAND, 5);

	m_buttonLoadFile = new wxButton(this, wxID_ANY, wxT("Load file with texts (D)"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonLoadFile->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonLoadFile, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonSaveTextAll = new wxButton(this, wxID_ANY, wxT("Save text everywhere (C)"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonSaveTextAll->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonSaveTextAll, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonSaveText = new wxButton(this, wxID_ANY, wxT("Save text (B)"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonSaveText->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonSaveText, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonSaveData = new wxButton(this, wxID_ANY, wxT("Save data (A)"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonSaveData->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonSaveData, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonRotate = new wxButton(this, wxID_ANY, wxT("Rotate photo"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonRotate->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonRotate, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonSaveIPTC = new wxButton(this, wxID_ANY, wxT("Save IPTC Data"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonSaveIPTC->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonSaveIPTC, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_buttonLoad = new wxButton(this, wxID_ANY, wxT("Load photos"), wxDefaultPosition, wxSize(180, -1), 0);
	m_buttonLoad->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));

	bSizer3->Add(m_buttonLoad, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer1->Add(bSizer3, 0, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::MyFrame1OnSize));
	m_buttonLoadFile->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonLoadFileOnButtonClick), NULL, this);
	m_buttonSaveTextAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveTextAllOnButtonClick), NULL, this);
	m_buttonSaveText->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveTextOnButtonClick), NULL, this);
	m_buttonSaveData->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveDataOnButtonClick), NULL, this);
	m_buttonSaveIPTC->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveIPTCOnButtonClick), NULL, this);
	m_buttonRotate->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonRotateOnButtonClick), NULL, this);
	m_buttonLoad->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonLoadOnButtonClick), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::MyFrame1OnSize));
	m_buttonLoadFile->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonLoadFileOnButtonClick), NULL, this);
	m_buttonSaveTextAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveTextAllOnButtonClick), NULL, this);
	m_buttonSaveText->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveTextOnButtonClick), NULL, this);
	m_buttonSaveData->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveDataOnButtonClick), NULL, this);
	m_buttonSaveIPTC->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonSaveIPTCOnButtonClick), NULL, this);
	m_buttonRotate->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonRotateOnButtonClick), NULL, this);
	m_buttonLoad->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_buttonLoadOnButtonClick), NULL, this);

}
