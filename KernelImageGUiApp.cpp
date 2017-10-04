//
// Created by iacopo on 19/10/16.
//

#include "KernelImageGUiApp.h"

//(*AppHeaders
#include "KernelImageGUiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(KernelImageGUiApp);

bool KernelImageGUiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        KernelImageGUiFrame* Frame = new KernelImageGUiFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}