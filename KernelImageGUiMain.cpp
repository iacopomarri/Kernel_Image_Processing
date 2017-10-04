//
// Created by iacopo on 19/10/16.
//

#include "KernelImageGUiMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(KernelImageGUiFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/log.h>
//*)
#include "Image.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(KernelImageGUiFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(KernelImageGUiFrame)
const long KernelImageGUiFrame::ID_BUTTON1 = wxNewId();
const long KernelImageGUiFrame::ID_TEXTCTRL1 = wxNewId();
const long KernelImageGUiFrame::ID_BUTTON2 = wxNewId();
const long KernelImageGUiFrame::ID_MENUITEM1 = wxNewId();
const long KernelImageGUiFrame::idMenuAbout = wxNewId();
const long KernelImageGUiFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KernelImageGUiFrame,wxFrame)
                //(*EventTable(KernelImageGUiFrame)
                //*)
END_EVENT_TABLE()

KernelImageGUiFrame::KernelImageGUiFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(KernelImageGUiFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(737,463));
    Button1 = new wxButton(this, ID_BUTTON1, _("Load"), wxPoint(112,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("File Path"), wxPoint(352,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Save"), wxPoint(144,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Button2->Enable(false);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton2Click2);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KernelImageGUiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KernelImageGUiFrame::OnAbout);
//    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&KernelImageGUiFrame::OnClose1);
    //*)
}

Image immagine;



KernelImageGUiFrame::~KernelImageGUiFrame()
{
    //(*Destroy(KernelImageGUiFrame)
    //*)
}

void KernelImageGUiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void KernelImageGUiFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void KernelImageGUiFrame::OnButton1Click1(wxCommandEvent& event)

{
    Button2->Enable(true);
   // wxString s= TextCtrl1->GetToolTipText();
    //std::string path = s.ToStdString();
   // immagine.loadImage(path);

    immagine->loadImage("/home/iacopo/Desktop/part1pairs/Test/emir.ppm", &immagine);         //IL VECCHIO SCAZZA DALLA RIGA 150 HEX. infatti alla riga 107 pos 2 dec c'e' un hashtag
}                                                                                        //QUANDO ILPROGRAMMA LEGGE IL BYTE 00100000 CIOE 32, CIOE SPAZIO IN ASCII, LO SALTA.

void KernelImageGUiFrame::OnButton2Click2(wxCommandEvent &event) {
    Button2->Enable(false);
    immagine->saveImage("/home/iacopo/Desktop/part1pairs/Test/cavia.ppm");
}



//PODERE MONTE LODOLI
//VIA MONTORSOLI 4 SAN CASCIANO
//FIRENZE SIENA E USCIRE A TAVARNELLE
