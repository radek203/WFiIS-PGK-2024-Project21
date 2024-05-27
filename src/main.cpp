#include <wx/wxprec.h>
#include "GUIMyFrame1.h"

#define FREEIMAGE_LIB

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit() { FreeImage_DeInitialise(); return 0; }
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	FreeImage_Initialise();
	wxInitAllImageHandlers();

	SetProcessDPIAware();
	wxFont::AddPrivateFont("Raleway-Regular.ttf");
	GUIMyFrame1* mainFrame = new GUIMyFrame1(NULL);
	mainFrame->Show(true);
	return true;
}
