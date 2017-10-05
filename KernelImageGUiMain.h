//
// Created by iacopo on 19/10/16.
//

#ifndef KERNELIMAGEPROCESSING_KERNELIMAGEGUIMAIN_H
#define KERNELIMAGEPROCESSING_KERNELIMAGEGUIMAIN_H

//(*Headers(KernelImageGUiFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
//*)

class KernelImageGUiFrame: public wxFrame
{
public:

    KernelImageGUiFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~KernelImageGUiFrame();

private:

    //(*Handlers(KernelImageGUiFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
//        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
    void OnClose(wxCloseEvent& event);
//        void OnFilePickerCtrl1FileChanged1(wxFileDirPickerEvent& event);
//        void OnFilePickerCtrl1FileChanged2(wxFileDirPickerEvent& event);
    void OnClose1(wxCloseEvent& event);
//        void OnDirPickerCtrl1DirChanged(wxFileDirPickerEvent& event);
    void OnButton2Click2(wxCommandEvent& event);
    void OnButton1Click1(wxCommandEvent& event);
    //*)

    //(*Identifiers(KernelImageGUiFrame)
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_TEXTCTRL1;
    static const long ID_TEXTCTRL2;
    static const long ID_STATICTEXT1;
    static const long ID_MENUITEM1;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(KernelImageGUiFrame)
    wxStatusBar* StatusBar1;
    wxButton* Button1;
    wxButton* Button2;
    wxTextCtrl* TextCtrl1;
    wxTextCtrl* TextCtrl2;
    wxStaticText* StaticText1;
    //*)

DECLARE_EVENT_TABLE()
};


#endif //KERNELIMAGEPROCESSING_KERNELIMAGEGUIMAIN_H
