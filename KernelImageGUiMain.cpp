#include "KernelImageGUiMain.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(KernelImageGUiFrame)

#include <wx/log.h>
//*)

//(*InternalHeaders(KernelImageGUiFrame)//*)

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
const long KernelImageGUiFrame::ID_BUTTON2 = wxNewId();
const long KernelImageGUiFrame::ID_BUTTON3 = wxNewId();
const long KernelImageGUiFrame::ID_BUTTON4 = wxNewId();
const long KernelImageGUiFrame::ID_BUTTON5 = wxNewId();
const long KernelImageGUiFrame::ID_TEXTCTRL1 = wxNewId();
const long KernelImageGUiFrame::ID_TEXTCTRL2 = wxNewId();
const long KernelImageGUiFrame::ID_STATICTEXT1 = wxNewId();
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
    Button2 = new wxButton(this, ID_BUTTON2, _("Save"), wxPoint(112,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Blur"), wxPoint(162,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("Sharpen"), wxPoint(310,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(this, ID_BUTTON5, _("Edge Detection"), wxPoint(458,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("File Path"), wxPoint(260,64), wxSize(400,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("File Path"), wxPoint(260,320), wxSize(400,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Loaded path: None"), wxPoint(260,100), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
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
    Button3->Enable(false);
    Button4->Enable(false);
    Button5->Enable(false);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton2Click2);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KernelImageGUiFrame::OnButton5Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KernelImageGUiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KernelImageGUiFrame::OnAbout);
//    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&KernelImageGUiFrame::OnClose1);
    //*)
}






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
    //attiva il pulsante salva
    Button2->Enable(true);
    Button3->Enable(true);
    Button4->Enable(true);
    Button5->Enable(true);
    //prende il testo nella casella del percorso da caricare
    wxString s= TextCtrl1->GetValue();
    //converte in standard string
    std::string loadPath = s.ToStdString();

    TextCtrl2->Clear();
    TextCtrl2->AppendText(loadPath);


    //check del tipo
    string p=i->check(loadPath);
    if (p=="P1" || p=="P4")
        i=&i1;
    else if(p=="P2" || p=="P5")
        i=&i2;
    else if(p=="P3" || p=="P6")
        i=&i3;
    //carica l'immagine
    i->loadImage(loadPath);
    //aggiorna la label del percorso caricato
    StaticText1->SetLabel("Loaded path:  "+ s);


}

void KernelImageGUiFrame::OnButton2Click2(wxCommandEvent &event) {
    wxString s= TextCtrl2->GetValue();
    std::string savePath = s.ToStdString();
    i->saveImage(savePath);

}

void KernelImageGUiFrame::OnButton3Click(wxCommandEvent& event)
{

    i->effect(e.getBlur());
}

void KernelImageGUiFrame::OnButton4Click(wxCommandEvent& event)
{
    i->effect(e.getSharpen());
}

void KernelImageGUiFrame::OnButton5Click(wxCommandEvent& event)
{
    i->effect(e.getEdgedetection());
}