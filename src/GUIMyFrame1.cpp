#include "GUIMyFrame1.h"
#include "ImageSelectionDialog.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent)
{
	fileCount = 0;
	buttonsSizer = new wxFlexGridSizer(1, 0, 0, 0);

	windowWidth = 1300 - 400;
}

void GUIMyFrame1::MyFrame1OnSize(wxSizeEvent& event) // WORKS CORRECTLY
{
	windowWidth = GetSize().x - 400;
	if (currentBigDisplay) {
		DisplayFolder();
	}
	Repaint(false);

	event.Skip();
}

void GUIMyFrame1::m_buttonSaveIPTCOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY
{
	if (!currentImgPath.empty()) {
		FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, currentImgPath, JPEG_DEFAULT);

		std::vector<const char*> IPTCLabels = { "By-lineTitle", "DateCreated", "City", "Country-PrimaryLocationName", "By-line", "Keywords" };

		for (int i = 0; i < 6; i++) {
			wxString tag = m_gridIPTC->GetCellValue(i, 0);
			FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap, IPTCLabels[i], tag);
		}
		FreeImage_Save(FIF_JPEG, bitmap, currentImgPath, 0);

		wxMessageBox(_("Successfully saved the data"));
	}
	else {
		wxMessageBox(_("No image selected!"));
	}

	event.Skip();
}

void GUIMyFrame1::m_buttonLoadFileOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY (D)
{
	wxString loadFilePath = wxFileSelector(wxT("Load Data File"), wxEmptyString, wxEmptyString, wxEmptyString, wxT("Text files (*.txt)|*.txt"), wxFD_OPEN, this);
	std::ifstream inFile(loadFilePath.ToStdString());

	if (inFile.is_open()) {
		if (currentBigDisplay) {
			DisplayFolder();
		}
		std::string fileName;
		std::string textToDraw;

		while (std::getline(inFile, fileName)) {
			std::getline(inFile, textToDraw);

			for (int i = 0; i < fileCount; i++) {
				if (pathArray[i].AfterLast('\\') == fileName) {
					AddText(wxImage(pathArray[i], wxBITMAP_TYPE_ANY, -1), textToDraw, pathArray[i]);
				}
			}
		}

		wxMessageBox(_("File loaded and images saved to new files!"));
	}
	else {
		wxMessageBox(_("File loaded and images saved to new files!"));
	}

	event.Skip();
}

void GUIMyFrame1::m_buttonSaveTextAllOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY (C)
{
	if (fileCount > 0) {
		if (currentBigDisplay) {
			DisplayFolder();
		}

		ImageSelectionDialog* imageDialog = new ImageSelectionDialog(this, pathArray);
		if (imageDialog->ShowModal() == wxID_OK) {
			wxArrayInt selectedImages = imageDialog->GetSelectedImages();

			IPTCCheckboxDialog* dialog = new IPTCCheckboxDialog(this);
			if (dialog->ShowModal() == wxID_OK) {

				std::vector<int> checkedItems = dialog->GetCheckedItems();

				for (int i = 0; i < selectedImages.GetCount(); i++) {
					int imageIndex = selectedImages[i];
					FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, pathArray[imageIndex], JPEG_DEFAULT);

					wxString IPTCData;
					for (auto id : checkedItems) {
						switch (id) {
							case ID_IPTC_TITLE:
								IPTCData += "Title: " + getImageIPTCData(bitmap, "By-lineTitle") + "\n";
								break;
							case ID_IPTC_DATE:
								IPTCData += "Date: " + getImageIPTCData(bitmap, "DateCreated") + "\n";
								break;
							case ID_IPTC_CITY:
								IPTCData += "City: " + getImageIPTCData(bitmap, "City") + "\n";
								break;
							case ID_IPTC_COUNTRY:
								IPTCData += "Copyright: " + getImageIPTCData(bitmap, "Country-PrimaryLocationName") + "\n";
								break;
							case ID_IPTC_AUTHOR:
								IPTCData += "Author: " + getImageIPTCData(bitmap, "By-line") + "\n";
								break;
							case ID_IPTC_KEYWORDS:
								IPTCData += "Keywords: " + getImageIPTCData(bitmap, "Keywords") + "\n";
								break;
							case ID_EXIF:
								IPTCData += getImageExifData(bitmap) + "\n";
								break;
						}
					}

					AddText(wxImage(pathArray[imageIndex], wxBITMAP_TYPE_ANY, -1), IPTCData, pathArray[imageIndex]);
					FreeImage_Unload(bitmap);
				}

				wxMessageBox(_("Images successfully saved to new files!"));
			}
			delete dialog;
		}
		else {
			wxMessageBox(_("No images selected!"));
		}
		delete imageDialog;
	}
	else {
		wxMessageBox(_("There are no images!"));
	}

	event.Skip();
}

void GUIMyFrame1::m_buttonSaveTextOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY (B)
 {
	if (!currentImgPath.empty()) {
		if (currentBigDisplay) {
			DisplayFolder();
		}

		IPTCCheckboxDialog* dialog = new IPTCCheckboxDialog(this);
		if (dialog->ShowModal() == wxID_OK) {
			std::vector<int> checkedItems = dialog->GetCheckedItems();

			FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, currentImgPath, JPEG_DEFAULT);

			wxString IPTCData;
			for (auto id : checkedItems) {
				switch (id) {
					case ID_IPTC_TITLE:
						IPTCData += "Title: " + getImageIPTCData(bitmap, "By-lineTitle") + "\n";
						break;
					case ID_IPTC_DATE:
						IPTCData += "Date: " + getImageIPTCData(bitmap, "DateCreated") + "\n";
						break;
					case ID_IPTC_CITY:
						IPTCData += "City: " + getImageIPTCData(bitmap, "City") + "\n";
						break;
					case ID_IPTC_COUNTRY:
						IPTCData += "Copyright: " + getImageIPTCData(bitmap, "Country-PrimaryLocationName") + "\n";
						break;
					case ID_IPTC_AUTHOR:
						IPTCData += "Author: " + getImageIPTCData(bitmap, "By-line") + "\n";
						break;
					case ID_IPTC_KEYWORDS:
						IPTCData += "Keywords: " + getImageIPTCData(bitmap, "Keywords") + "\n";
						break;
					case ID_EXIF:
						IPTCData += getImageExifData(bitmap) + "\n";
						break;
				}
			}

			AddText(wxImage(currentImgPath, wxBITMAP_TYPE_ANY, -1), IPTCData, currentImgPath);
			FreeImage_Unload(bitmap);

			wxMessageBox(_("Text saved on the image!"));
		}
		else {
			wxMessageBox(_("No image is displayed!"));
		}
		delete dialog;
	}
	else {
		wxMessageBox(_("No image selected!"));
	}

	event.Skip();
}



void GUIMyFrame1::m_buttonSaveDataOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY (A)
{
	if (fileCount > 0) {
		wxString saveFilePath = wxFileSelector(wxT("Save Data File"), wxEmptyString, wxEmptyString, wxEmptyString, wxT("Text files (*.txt)|*.txt"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, this);
		std::ofstream outFile(saveFilePath.ToStdString());

		if (outFile.is_open()) {
			for (int i = 0; i < fileCount; i++) {
				wxString imagePath = pathArray[i];

				if (!saveFilePath.empty()) {

					FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, imagePath, JPEG_DEFAULT);

					outFile << "Path: " << imagePath.AfterLast('/') << "\n\n";

					outFile << "IPTC data: \n";

					outFile << getImageIPTCData(bitmap) << "\n";

					outFile << "EXIF data: \n";

					outFile << getImageExifData(bitmap) << "\n";

					outFile << "-----------------------------------\n\n";

					FreeImage_Unload(bitmap);
				}
			}
			outFile.close();

			wxMessageBox(_("Saved data!"));
		}
		else {
			wxMessageBox(_("Failed to open the file!"));
		}
	}
	else {
		wxMessageBox(_("There are no images!"));
	}
		
	event.Skip();
}

void GUIMyFrame1::m_buttonRotateOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY
{
	if (currentBigDisplay) {
		currentBigDisplay->RotateImage();
		currentBigDisplay->Refresh(false);
	}
	else {
		wxMessageBox(_("No image is displayed!"));
	}

	event.Skip();
}

void GUIMyFrame1::m_buttonLoadOnButtonClick(wxCommandEvent& event) // WORKS CORRECTLY
{
	wxString defaultPath = wxT("/");
	wxDirDialog dialog(this, wxT("Choose directory"), defaultPath, wxDD_NEW_DIR_BUTTON);
	if (dialog.ShowModal() == wxID_OK) {
		pathArray.Clear();
		if (buttonsSizer) buttonsSizer->Clear(true);
		buttonsSizer = nullptr;
		bitmapVector.clear();

		wxString path = dialog.GetPath();
		wxDir dir(dialog.GetPath());

		wxArrayString files;
		dir.GetAllFiles(dialog.GetPath(), &files, "*.jpg", wxDIR_FILES);

		for (const auto& file : files) {
			if (!file.EndsWith("_modified.jpg")) { 
				pathArray.Add(file);
			}
		}

		fileCount = pathArray.GetCount();
		Repaint();
	}
	else {
		wxMessageBox(_("Unable to open the folder."));
	}

	event.Skip();
}

void GUIMyFrame1::Repaint(bool loading) // WORKS CORRECTLY
{
	wxClientDC dc(m_scrolledWindowPhotos);

	if (fileCount > 0)
	{
		if (loading) {
			wxString text = "LOADING IMAGES...";
			dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));
			wxCoord width, height;
			dc.GetTextExtent(text, &width, &height);
			dc.DrawText(text, wxPoint((dc.GetSize().GetWidth() / 2) - (width / 2), (dc.GetSize().GetHeight()) / 2 - (height / 2)));

			for (int i = 0; i < fileCount; i++) {

				wxImage img = wxImage(pathArray[i], wxBITMAP_TYPE_ANY, -1);
				img.Rescale(240, 180, wxIMAGE_QUALITY_NEAREST);

				wxBitmap bitmap(img, -1);
				bitmapVector.push_back(bitmap);
			}
		}
		dc.SetBackground(wxColour(255, 229, 204));
		dc.Clear();
		printBitmapButtons();
	}
}


void GUIMyFrame1::printBitmapButtons() // WORKS CORRECTLY
{
	if (fileCount > 0) {
		int rows = 1;
		int cols = (windowWidth - 40) / 260;
		if (cols != 0) rows = fileCount / cols + 1;
		if (buttonsSizer) buttonsSizer->Clear(true);
		buttonsSizer = new wxFlexGridSizer(rows, cols, 0, 10);
		buttonsSizer->SetFlexibleDirection(wxBOTH);

		for (int i = 0; i < fileCount; i++) {
			wxBitmapButton* button = new ImageButton(this, m_scrolledWindowPhotos, bitmapVector[i], pathArray[i]);
			buttonsSizer->Add(button);
		}

		m_scrolledWindowPhotos->SetSizer(buttonsSizer);
		m_scrolledWindowPhotos->FitInside();
		m_scrolledWindowPhotos->SetScrollRate(25, 25);
	}
}

void GUIMyFrame1::DisplayBigImg(const wxString& path) // WORKS CORRECTLY
{
	m_scrolledWindowPhotos->Hide();

	int w = m_scrolledWindowPhotos->GetSize().GetWidth();
	int h = m_scrolledWindowPhotos->GetSize().GetHeight();
	m_panelFullDisplay->SetSize(w, h);

	currentBigDisplay = new BigDisplay(this, path, m_panelFullDisplay, wxSize(w, h));
}

void DisplayOneIPTCData(wxGrid* IPTC, FIBITMAP* bitmap_free, const char* tagName, int i) // WORKS CORRECTLY
{
	FITAG* tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, tagName, &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		IPTC->SetCellValue(i, 0, value);
	}
	else {
		IPTC->SetCellValue(i, 0, "");
	}
}

void GUIMyFrame1::DisplayMetaData(const wxString& path) // WORKS CORRECTLY
{
	currentImgPath = path;
	FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, path, JPEG_DEFAULT);
	m_textCtrlInfo->Clear();
	m_textCtrlInfo->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway")));
	m_textCtrlInfo->AppendText(getImageExifData(bitmap));

	std::vector<const char*> IPTCLabels = { "By-lineTitle", "DateCreated", "City", "Country-PrimaryLocationName", "By-line", "Keywords" };

	for (int i = 0; i < 6; i++) {
		DisplayOneIPTCData(m_gridIPTC, bitmap, IPTCLabels[i], i);
	}

	FreeImage_Unload(bitmap);
}

void GUIMyFrame1::DisplayFolder() // WORKS CORRECTLY
{
	if (currentBigDisplay) {
		currentBigDisplay->Hide();
		currentBigDisplay->Destroy();
		currentBigDisplay = nullptr;
	}
	m_panelFullDisplay->Hide();
	m_scrolledWindowPhotos->Show();
}

wxString GUIMyFrame1::getImageExifData(FIBITMAP* bitmap) // WORKS CORRECTLY
{
	FITAG* tag = NULL;
	FIMETADATA* handle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap, &tag);

	wxString imgData = "";

	if (handle) {
		do {
			const char* value = FreeImage_TagToString(FIMD_EXIF_MAIN, tag);

			if (FreeImage_GetTagValue(tag)) {
				imgData = imgData + FreeImage_GetTagKey(tag) + ": " + value + "\n";
			}

		} while (FreeImage_FindNextMetadata(handle, &tag));

		FreeImage_FindCloseMetadata(handle);
	}
	return imgData;
}

wxString GUIMyFrame1::getImageIPTCData(FIBITMAP* bitmap) // WORKS CORRECTLY
{
	std::vector<const char*> IPTCFields = { "Title", "Creation Date", "City", "Country", "Author", "Keywords" };

	std::vector<const char*> IPTCLabels = { "By-lineTitle", "DateCreated", "City", "Country-PrimaryLocationName", "By-line", "Keywords" };

	wxString IPTCData = "";

	for (int i = 0; i < 6; i++) {
		FITAG* tag = NULL;
		FreeImage_GetMetadata(FIMD_IPTC, bitmap, IPTCLabels[i], &tag);
		if (tag != NULL) {
			const char* entry = (char*)FreeImage_GetTagValue(tag);
			IPTCData = IPTCData + IPTCFields[i] + ": " + entry + "\n";
		}
	}

	return IPTCData;
}

wxString GUIMyFrame1::getImageIPTCData(FIBITMAP* bitmap, const char* tagName) // WORKS CORRECTLY
{
	FITAG* tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap, tagName, &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		return wxString(value);
	}
	return wxEmptyString;
}

void GUIMyFrame1::DrawTextOnWxImage(wxImage& image, const wxString& text, int x, int y, const wxFont& font, const wxColour& textColor) // WORKS
{
	wxBitmap bitmap(image);

	wxMemoryDC dc;
	dc.SelectObject(bitmap);

	dc.SetFont(font);
	dc.SetTextForeground(textColor);

	dc.DrawText(text, x, y);

	dc.SelectObject(wxNullBitmap);

	image = bitmap.ConvertToImage();
}


void GUIMyFrame1::AddText(wxImage image, const wxString& text, const wxString& path)  // WORKS, BUT REMOVES METADATA (POTENTIALLY TO FIX?)
{
	int font_size = (image.GetWidth() > image.GetHeight() ? image.GetWidth() : image.GetHeight()) * 0.018;
	wxFont font(font_size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Raleway"));
	int x = image.GetWidth() * 0.04;
	int y = image.GetHeight() * 0.04;

	DrawTextOnWxImage(image, text, x, y, font, wxColour(255, 255, 255));
	image.SaveFile(path.BeforeLast('.') + "_modified.jpg", wxBITMAP_TYPE_JPEG);
}