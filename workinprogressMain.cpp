/***************************************************************
 * Name:      workinprogressMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Patrick Sébastien (patrick@11h11.com)
 * Created:   2010-10-11
 * Copyright: Patrick Sébastien (www.workinprogress.ca)
 * License:
 **************************************************************/

 /*******
 TODO--------------------------------------------------------

avrdude.conf for windows...

 new feature: ADD a project (create makefile, basic .c etc..)
 add SUCCESS big RED or whatever (wxMessagebox?)
 arduino share code and compile?
  bring all string to 1 place...
 no winavr env. var then disable make, clean
 clean code and comment
 progress thread
 welcome: maybe a dynamic count of project
 maybe using http://www.makehackvoid.com/group-projects/mhvavrtools instead of winavr


 gtk - if usb operation not permitted (show a message)
 is it a problem for windows: g_application_dir+DS+_T("firmware")+DS sans +DS apres _dir
 wxSetWorkingDirectory in edit source a problem without on windows?

 on release be sure to clean the dep folder of bootler fimrware

(linux only) usb todo documentation about:
ATTATTRS{idVendor}=="16c0",ATTRS{idProduct}=="05df", MODE="0666"
RS{idVendor}=="16c0",ATTRS{idProduct}=="05df", MODE="0666"
usbasp:
ATTRS{idVendor}=="16c0",ATTRS{idProduct}=="05dc", MODE="0666"

but edit source empty when : open custom fimrware, then open availabel firmware...

infrared bootloader?

 ********/

#include "wx_pch.h"
#include "workinprogressMain.h"

//(*InternalHeaders(workinprogressFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#if defined(__WXMSW__)
    wxString DS = _T("\\");
#elif defined(__WXGTK__)
    wxString DS = _T("/");
#elif defined(__WXMAC__)
#endif


//(*IdInit(workinprogressFrame)
const long workinprogressFrame::ID_STATICTEXT37 = wxNewId();
const long workinprogressFrame::ID_STATICBITMAP1 = wxNewId();
const long workinprogressFrame::ID_HTMLWINDOW3 = wxNewId();
const long workinprogressFrame::ID_PANEL8 = wxNewId();
const long workinprogressFrame::ID_PANEL2 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL10 = wxNewId();
const long workinprogressFrame::ID_BUTTON13 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL11 = wxNewId();
const long workinprogressFrame::ID_BUTTON14 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT27 = wxNewId();
const long workinprogressFrame::ID_CHOICE6 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT28 = wxNewId();
const long workinprogressFrame::ID_CHOICE7 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT29 = wxNewId();
const long workinprogressFrame::ID_CHOICE8 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT30 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL12 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT31 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL13 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT32 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL14 = wxNewId();
const long workinprogressFrame::ID_BUTTON17 = wxNewId();
const long workinprogressFrame::ID_BUTTON18 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX3 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX4 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX5 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT33 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL15 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT34 = wxNewId();
const long workinprogressFrame::ID_LISTBOX3 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT36 = wxNewId();
const long workinprogressFrame::ID_BUTTON16 = wxNewId();
const long workinprogressFrame::ID_BUTTON15 = wxNewId();
const long workinprogressFrame::ID_PANEL16 = wxNewId();
const long workinprogressFrame::ID_PANEL3 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT2 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL1 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT3 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL2 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT4 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL3 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT5 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL4 = wxNewId();
const long workinprogressFrame::ID_PANEL11 = wxNewId();
const long workinprogressFrame::ID_PANEL5 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT15 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL6 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT16 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL7 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT17 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL8 = wxNewId();
const long workinprogressFrame::ID_PANEL12 = wxNewId();
const long workinprogressFrame::ID_PANEL10 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT35 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX6 = wxNewId();
const long workinprogressFrame::ID_PANEL14 = wxNewId();
const long workinprogressFrame::ID_PANEL13 = wxNewId();
const long workinprogressFrame::ID_NOTEBOOK_FIRM = wxNewId();
const long workinprogressFrame::ID_STATICTEXT6 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL5 = wxNewId();
const long workinprogressFrame::ID_BUTTON2 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT7 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT8 = wxNewId();
const long workinprogressFrame::ID_CHOICE1 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT9 = wxNewId();
const long workinprogressFrame::ID_CHOICE2 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT10 = wxNewId();
const long workinprogressFrame::ID_CHOICE3 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT11 = wxNewId();
const long workinprogressFrame::ID_HTMLWINDOW1 = wxNewId();
const long workinprogressFrame::ID_BUTTON1 = wxNewId();
const long workinprogressFrame::ID_BUTTON4 = wxNewId();
const long workinprogressFrame::ID_BUTTON6 = wxNewId();
const long workinprogressFrame::ID_BUTTON5 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT12 = wxNewId();
const long workinprogressFrame::ID_LISTBOX1 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX2 = wxNewId();
const long workinprogressFrame::ID_CHECKBOX1 = wxNewId();
const long workinprogressFrame::ID_BUTTON3 = wxNewId();
const long workinprogressFrame::ID_PANEL7 = wxNewId();
const long workinprogressFrame::ID_PANEL4 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT24 = wxNewId();
const long workinprogressFrame::ID_TEXTCTRL9 = wxNewId();
const long workinprogressFrame::ID_BUTTON7 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT23 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT21 = wxNewId();
const long workinprogressFrame::ID_CHOICE4 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT22 = wxNewId();
const long workinprogressFrame::ID_CHOICE5 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT25 = wxNewId();
const long workinprogressFrame::ID_HTMLWINDOW2 = wxNewId();
const long workinprogressFrame::ID_STATICTEXT26 = wxNewId();
const long workinprogressFrame::ID_LISTBOX2 = wxNewId();
const long workinprogressFrame::ID_BUTTON8 = wxNewId();
const long workinprogressFrame::ID_BUTTON9 = wxNewId();
const long workinprogressFrame::ID_BUTTON10 = wxNewId();
const long workinprogressFrame::ID_BUTTON11 = wxNewId();
const long workinprogressFrame::ID_BUTTON12 = wxNewId();
const long workinprogressFrame::ID_PANEL15 = wxNewId();
const long workinprogressFrame::ID_PANEL6 = wxNewId();
const long workinprogressFrame::ID_NOTEBOOK1 = wxNewId();
const long workinprogressFrame::ID_PANEL1 = wxNewId();
const long workinprogressFrame::tb_submit = wxNewId();
const long workinprogressFrame::tb_update = wxNewId();
const long workinprogressFrame::tb_help = wxNewId();
const long workinprogressFrame::tb_quit = wxNewId();
const long workinprogressFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(workinprogressFrame,wxFrame)
    //(*EventTable(workinprogressFrame)
    //*)
END_EVENT_TABLE()

//get the executable path
wxString workinprogressFrame::GetCurrentWorkingDirectory()
{
    wxString wxstrCurrentWorkingDirectory = wxStandardPaths::Get().GetExecutablePath() ;
    //std::wstring wstrReturnValue = wxstrCurrentWorkingDirectory.wc_str() ;
    wxString wstrReturnValue = wxstrCurrentWorkingDirectory;
    wstrReturnValue = wstrReturnValue.erase(wstrReturnValue.find_last_of (DS)+1 , wstrReturnValue.length() - ( wstrReturnValue.find_last_of(DS)+1)) ;
    return wstrReturnValue;
}

workinprogressFrame::workinprogressFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(workinprogressFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer29;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer39;
    wxBoxSizer* BoxSizer21;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxBoxSizer* BoxSizer36;
    wxBoxSizer* BoxSizer41;
    wxBoxSizer* BoxSizer37;
    wxBoxSizer* BoxSizer42;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer16;
    wxBoxSizer* BoxSizer30;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer28;
    wxBoxSizer* BoxSizer38;
    wxBoxSizer* BoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer27;
    wxBoxSizer* BoxSizer31;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer26;
    wxBoxSizer* BoxSizer32;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer34;
    wxBoxSizer* BoxSizer33;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer35;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxBoxSizer* BoxSizer25;
    wxBoxSizer* BoxSizer40;

    Create(parent, wxID_ANY, _("Yaku"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxCLIP_CHILDREN, _T("wxID_ANY"));
    SetClientSize(wxSize(760,694));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("icon.png"))));
    	SetIcon(FrameIcon);
    }
    fm_panel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(752,744), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    nb_main = new wxNotebook(fm_panel, ID_NOTEBOOK1, wxDefaultPosition, wxSize(752,624), wxNB_BOTTOM, _T("ID_NOTEBOOK1"));
    pl_welcome = new wxPanel(nb_main, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2 = new wxPanel(pl_welcome, ID_PANEL8, wxDefaultPosition, wxSize(736,592), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    StaticText36 = new wxStaticText(Panel2, ID_STATICTEXT37, _("Welcome to Yaku"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    wxFont StaticText36Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText36->SetFont(StaticText36Font);
    StaticBitmap1 = new wxStaticBitmap(Panel2, ID_STATICBITMAP1, wxBitmap(wxImage(_T("yaku.jpg"))), wxPoint(16,120), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    HtmlWindow1 = new wxHtmlWindow(Panel2, ID_HTMLWINDOW3, wxPoint(16,48), wxSize(712,88), wxHW_SCROLLBAR_NEVER|wxSIMPLE_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HTMLWINDOW3"));
    HtmlWindow1->SetPage(_("<p>Yaku is a software for burning firmware or bootloader on AVR. It is also a gui for AVRDUDE. Hopefully, people like you will use it to share their work (firmware or bootloader). For now, there\'s 2 bootloader (USB, Ethernet) and 2 firmware (USB template, Ethernet WWW Server) for ATMEGA644P. To begin, select a panel below.</p>"));
    pl_avrdude = new wxPanel(nb_main, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel7 = new wxPanel(pl_avrdude, ID_PANEL16, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    BoxSizer35 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("Flash"));
    tc_ad_flash = new wxTextCtrl(Panel7, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(638,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    StaticBoxSizer1->Add(tc_ad_flash, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_ad_flash = new wxButton(Panel7, ID_BUTTON13, _("..."), wxDefaultPosition, wxSize(35,23), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    StaticBoxSizer1->Add(b_ad_flash, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("EEPROM"));
    tc_ad_eeprom = new wxTextCtrl(Panel7, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxSize(638,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    StaticBoxSizer2->Add(tc_ad_eeprom, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_ad_eeprom = new wxButton(Panel7, ID_BUTTON14, _("..."), wxDefaultPosition, wxSize(35,23), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    StaticBoxSizer2->Add(b_ad_eeprom, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer37 = new wxBoxSizer(wxVERTICAL);
    StaticText27 = new wxStaticText(Panel7, ID_STATICTEXT27, _("Device (-p):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    BoxSizer37->Add(StaticText27, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    c_ad_device = new wxChoice(Panel7, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE6"));
    BoxSizer37->Add(c_ad_device, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer36->Add(BoxSizer37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer38 = new wxBoxSizer(wxVERTICAL);
    StaticText28 = new wxStaticText(Panel7, ID_STATICTEXT28, _("Programmer (-c):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    BoxSizer38->Add(StaticText28, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    c_ad_programmer = new wxChoice(Panel7, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE7"));
    BoxSizer38->Add(c_ad_programmer, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer36->Add(BoxSizer38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer39 = new wxBoxSizer(wxVERTICAL);
    StaticText29 = new wxStaticText(Panel7, ID_STATICTEXT29, _("Port (-P):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    BoxSizer39->Add(StaticText29, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    c_ad_port = new wxChoice(Panel7, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    c_ad_port->Append(_("usb"));
    c_ad_port->Append(_("lpt1"));
    c_ad_port->Append(_("lpt2"));
    c_ad_port->Append(_("lpt3"));
    c_ad_port->Append(_("com1"));
    c_ad_port->Append(_("com2"));
    c_ad_port->Append(_("com3"));
    c_ad_port->Append(_("com4"));
    c_ad_port->Append(_("com5"));
    c_ad_port->Append(_("com6"));
    c_ad_port->Append(_("com7"));
    c_ad_port->Append(_("com8"));
    c_ad_port->Append(_("com9"));
    c_ad_port->Append(_("com10"));
    BoxSizer39->Add(c_ad_port, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer36->Add(BoxSizer39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(BoxSizer36, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer40 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("Low Fuse"));
    StaticText30 = new wxStaticText(Panel7, ID_STATICTEXT30, _("0x"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    StaticBoxSizer3->Add(StaticText30, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 1);
    tc_low = new wxTextCtrl(Panel7, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxSize(31,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    tc_low->SetMaxLength(2);
    StaticBoxSizer3->Add(tc_low, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    StaticBoxSizer3->Add(28,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer40->Add(StaticBoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("High Fuse"));
    StaticText31 = new wxStaticText(Panel7, ID_STATICTEXT31, _("0x"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    StaticBoxSizer4->Add(StaticText31, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 1);
    tc_high = new wxTextCtrl(Panel7, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxSize(31,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    StaticBoxSizer4->Add(tc_high, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    StaticBoxSizer4->Add(29,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer40->Add(StaticBoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("Extended Fuse"));
    StaticText32 = new wxStaticText(Panel7, ID_STATICTEXT32, _("0x"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    StaticBoxSizer5->Add(StaticText32, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 1);
    tc_extended = new wxTextCtrl(Panel7, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxSize(31,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    tc_extended->SetMaxLength(2);
    StaticBoxSizer5->Add(tc_extended, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    StaticBoxSizer5->Add(48,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer40->Add(StaticBoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_fuses = new wxButton(Panel7, ID_BUTTON17, _("Read fuses"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    BoxSizer40->Add(b_fuses, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_fuse_calculator = new wxButton(Panel7, ID_BUTTON18, _("Fuse Calculator"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
    BoxSizer40->Add(b_fuse_calculator, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(BoxSizer40, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel7, _("Options"));
    cb_d = new wxCheckBox(Panel7, ID_CHECKBOX3, _("Disable auto erase for flash (-D)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    cb_d->SetValue(false);
    StaticBoxSizer6->Add(cb_d, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    cb_e = new wxCheckBox(Panel7, ID_CHECKBOX4, _("Perform a chip erase (-e)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    cb_e->SetValue(false);
    StaticBoxSizer6->Add(cb_e, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    cb_v = new wxCheckBox(Panel7, ID_CHECKBOX5, _("Disable verify check (-V)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    cb_v->SetValue(false);
    StaticBoxSizer6->Add(cb_v, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(StaticBoxSizer6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(Panel7, ID_STATICTEXT33, _("Command line:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    BoxSizer35->Add(StaticText33, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer41 = new wxBoxSizer(wxHORIZONTAL);
    tc_ad_command = new wxTextCtrl(Panel7, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxSize(714,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    BoxSizer41->Add(tc_ad_command, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(BoxSizer41, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    StaticText34 = new wxStaticText(Panel7, ID_STATICTEXT34, _("Log"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    BoxSizer35->Add(StaticText34, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_lbox_ad = new wxListBox(Panel7, ID_LISTBOX3, wxDefaultPosition, wxSize(715,109), 0, 0, wxLB_HSCROLL, wxDefaultValidator, _T("ID_LISTBOX3"));
    BoxSizer35->Add(m_lbox_ad, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
    st_note = new wxStaticText(Panel7, ID_STATICTEXT36, wxEmptyString, wxDefaultPosition, wxSize(455,13), 0, _T("ID_STATICTEXT36"));
    wxFont st_noteFont(9,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    st_note->SetFont(st_noteFont);
    BoxSizer42->Add(st_note, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_fetch = new wxButton(Panel7, ID_BUTTON16, _("Hardware information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    BoxSizer42->Add(b_fetch, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_ad_execute = new wxButton(Panel7, ID_BUTTON15, _("Execute"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    BoxSizer42->Add(b_ad_execute, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(BoxSizer42, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    Panel7->SetSizer(BoxSizer35);
    BoxSizer35->Fit(Panel7);
    BoxSizer35->SetSizeHints(Panel7);
    pl_firmware = new wxPanel(nb_main, ID_PANEL4, wxDefaultPosition, wxSize(632,732), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel6 = new wxPanel(pl_firmware, ID_PANEL7, wxDefaultPosition, wxSize(640,410), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    nb_via = new wxNotebook(Panel6, ID_NOTEBOOK_FIRM, wxDefaultPosition, wxSize(449,191), wxNB_BOTTOM, _T("ID_NOTEBOOK_FIRM"));
    pn_usb = new wxPanel(nb_via, ID_PANEL5, wxDefaultPosition, wxSize(366,156), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel4 = new wxPanel(pn_usb, ID_PANEL11, wxDefaultPosition, wxSize(488,168), wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    BoxSizer18 = new wxBoxSizer(wxVERTICAL);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel4, ID_STATICTEXT2, _("Vendor ID:"), wxDefaultPosition, wxSize(100,13), 0, _T("ID_STATICTEXT2"));
    BoxSizer19->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_vendor_id = new wxTextCtrl(Panel4, ID_TEXTCTRL1, _("0x16c0"), wxDefaultPosition, wxSize(63,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer19->Add(tc_vendor_id, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer19, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel4, ID_STATICTEXT3, _("Vendor string:"), wxDefaultPosition, wxSize(100,16), 0, _T("ID_STATICTEXT3"));
    BoxSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_vendor_string = new wxTextCtrl(Panel4, ID_TEXTCTRL2, _("workinprogress"), wxDefaultPosition, wxSize(128,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer4->Add(tc_vendor_string, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer4, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(Panel4, ID_STATICTEXT4, _("Product ID:"), wxDefaultPosition, wxSize(100,-1), 0, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_product_id = new wxTextCtrl(Panel4, ID_TEXTCTRL3, _("0x05df"), wxDefaultPosition, wxSize(63,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer5->Add(tc_product_id, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer5, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(Panel4, ID_STATICTEXT5, _("Product string:"), wxDefaultPosition, wxSize(100,-1), 0, _T("ID_STATICTEXT5"));
    BoxSizer6->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_product_string = new wxTextCtrl(Panel4, ID_TEXTCTRL4, _("yaku"), wxDefaultPosition, wxSize(128,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    BoxSizer6->Add(tc_product_string, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer6, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    Panel4->SetSizer(BoxSizer18);
    BoxSizer18->SetSizeHints(Panel4);
    pn_ethernet = new wxPanel(nb_via, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    Panel1 = new wxPanel(pn_ethernet, ID_PANEL12, wxDefaultPosition, wxSize(488,168), wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT15, _("Device IP:"), wxDefaultPosition, wxSize(115,13), 0, _T("ID_STATICTEXT15"));
    BoxSizer20->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_ip = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("192.168.1.253"), wxDefaultPosition, wxSize(115,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    BoxSizer20->Add(tc_ip, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer20, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
    StaticText16 = new wxStaticText(Panel1, ID_STATICTEXT16, _("Device UDP Port:"), wxDefaultPosition, wxSize(115,13), 0, _T("ID_STATICTEXT16"));
    BoxSizer21->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_device_port = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("3000"), wxDefaultPosition, wxSize(55,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    BoxSizer21->Add(tc_device_port, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer21, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT17, _("Local UDP Port:"), wxDefaultPosition, wxSize(115,-1), 0, _T("ID_STATICTEXT17"));
    BoxSizer22->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_local_port = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("3001"), wxDefaultPosition, wxSize(55,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    BoxSizer22->Add(tc_local_port, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer22, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(BoxSizer3);
    BoxSizer3->SetSizeHints(Panel1);
    pn_avrdude = new wxPanel(nb_via, ID_PANEL13, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL13"));
    Panel5 = new wxPanel(pn_avrdude, ID_PANEL14, wxDefaultPosition, wxSize(440,152), wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    StaticText35 = new wxStaticText(Panel5, ID_STATICTEXT35, _("Will use the AVRDUDE panel when you click Program"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    cb_asp = new wxCheckBox(Panel5, ID_CHECKBOX6, _("using USBASP bootloader"), wxPoint(8,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    cb_asp->SetValue(false);
    nb_via->AddPage(pn_usb, _("   via USB   "), false);
    nb_via->AddPage(pn_ethernet, _("   via ETHERNET   "), false);
    nb_via->AddPage(pn_avrdude, _("   via AVRDUDE   "), false);
    BoxSizer1->Add(nb_via, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    BoxSizer8->Add(20,1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel6, ID_STATICTEXT6, _("Your firmware:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    BoxSizer8->Add(StaticText6, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    tc_file = new wxTextCtrl(Panel6, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(632,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    BoxSizer9->Add(tc_file, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    b_open = new wxButton(Panel6, ID_BUTTON2, _("Open .hex"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer9->Add(b_open, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer8->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer8->Add(20,1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer8, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    StaticText7 = new wxStaticText(Panel6, ID_STATICTEXT7, _("Available firmware:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    BoxSizer10->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    StaticText8 = new wxStaticText(Panel6, ID_STATICTEXT8, _("Microcontroller: "), wxDefaultPosition, wxSize(100,13), 0, _T("ID_STATICTEXT8"));
    BoxSizer11->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    c_microcontroller = new wxChoice(Panel6, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE1"));
    BoxSizer11->Add(c_microcontroller, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel6, ID_STATICTEXT9, _("  Category:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer11->Add(StaticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    c_category = new wxChoice(Panel6, ID_CHOICE2, wxDefaultPosition, wxSize(140,29), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE2"));
    c_category->Disable();
    BoxSizer11->Add(c_category, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel6, ID_STATICTEXT10, _("  Firmware:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer11->Add(StaticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    c_firmware = new wxChoice(Panel6, ID_CHOICE3, wxDefaultPosition, wxSize(140,29), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE3"));
    c_firmware->Disable();
    BoxSizer11->Add(c_firmware, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(BoxSizer11, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(BoxSizer10, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    StaticText11 = new wxStaticText(Panel6, ID_STATICTEXT11, _("Description:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont StaticText11Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText11->SetFont(StaticText11Font);
    BoxSizer14->Add(StaticText11, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    html_description = new wxHtmlWindow(Panel6, ID_HTMLWINDOW1, wxDefaultPosition, wxSize(382,155), wxHW_SCROLLBAR_AUTO|wxSIMPLE_BORDER, _T("ID_HTMLWINDOW1"));
    html_description->SetBorders(1);
    html_description->SetPage(_("avr usb"));
    BoxSizer14->Add(html_description, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    b_source = new wxButton(Panel6, ID_BUTTON1, _("Edit source"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    b_source->Disable();
    BoxSizer17->Add(b_source, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_make = new wxButton(Panel6, ID_BUTTON4, _("Make"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    b_make->Disable();
    BoxSizer17->Add(b_make, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_clean = new wxButton(Panel6, ID_BUTTON6, _("Clean"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    b_clean->Disable();
    BoxSizer17->Add(b_clean, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_info = new wxButton(Panel6, ID_BUTTON5, _("More information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer17->Add(b_info, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer14->Add(BoxSizer17, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer7->Add(BoxSizer14, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    StaticText12 = new wxStaticText(Panel6, ID_STATICTEXT12, _("Log:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    wxFont StaticText12Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText12->SetFont(StaticText12Font);
    BoxSizer15->Add(StaticText12, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_lbox = new wxListBox(Panel6, ID_LISTBOX1, wxDefaultPosition, wxSize(331,155), 0, 0, wxLB_HSCROLL, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer15->Add(m_lbox, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
    cb_bootloader = new wxCheckBox(Panel6, ID_CHECKBOX2, _("Enter Bootloader [\?]"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    cb_bootloader->SetValue(true);
    cb_bootloader->SetToolTip(_("If your firmware support it, will try to enter bootloader from the firmware"));
    cb_bootloader->SetHelpText(_("If your firmware support it, will try to enter bootloader from the firmware"));
    BoxSizer16->Add(cb_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    cb_restart = new wxCheckBox(Panel6, ID_CHECKBOX1, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    cb_restart->SetValue(true);
    BoxSizer16->Add(cb_restart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_program = new wxButton(Panel6, ID_BUTTON3, _("Program"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    b_program->Disable();
    BoxSizer16->Add(b_program, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer15->Add(BoxSizer16, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer7->Add(BoxSizer15, 0, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 0);
    BoxSizer2->Add(BoxSizer7, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    Panel6->SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(Panel6);
    pl_bootloader = new wxPanel(nb_main, ID_PANEL6, wxDefaultPosition, wxSize(746,596), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Panel3 = new wxPanel(pl_bootloader, ID_PANEL15, wxDefaultPosition, wxSize(640,410), wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    BoxSizer25 = new wxBoxSizer(wxVERTICAL);
    BoxSizer28 = new wxBoxSizer(wxVERTICAL);
    StaticText24 = new wxStaticText(Panel3, ID_STATICTEXT24, _("Your bootloader:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    wxFont StaticText24Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText24->SetFont(StaticText24Font);
    BoxSizer28->Add(StaticText24, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
    tc_file_bootloader = new wxTextCtrl(Panel3, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(648,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    BoxSizer29->Add(tc_file_bootloader, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    b_open_bootloader = new wxButton(Panel3, ID_BUTTON7, _("Open .hex"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer29->Add(b_open_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer28->Add(BoxSizer29, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer28->Add(20,1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(Panel3, ID_STATICTEXT23, _("Available bootloader:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    wxFont StaticText23Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText23->SetFont(StaticText23Font);
    BoxSizer28->Add(StaticText23, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
    StaticText21 = new wxStaticText(Panel3, ID_STATICTEXT21, _("Microcontroller:"), wxDefaultPosition, wxSize(115,17), 0, _T("ID_STATICTEXT21"));
    BoxSizer26->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    c_microcontroller_bootloader = new wxChoice(Panel3, ID_CHOICE4, wxDefaultPosition, wxSize(154,29), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE4"));
    BoxSizer26->Add(c_microcontroller_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer28->Add(BoxSizer26, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    StaticText22 = new wxStaticText(Panel3, ID_STATICTEXT22, _("Bootloader:"), wxDefaultPosition, wxSize(115,-1), 0, _T("ID_STATICTEXT22"));
    BoxSizer27->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    c_bootloader = new wxChoice(Panel3, ID_CHOICE5, wxDefaultPosition, wxSize(154,29), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE5"));
    c_bootloader->Disable();
    BoxSizer27->Add(c_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer28->Add(BoxSizer27, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer25->Add(BoxSizer28, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer30 = new wxBoxSizer(wxVERTICAL);
    BoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer33 = new wxBoxSizer(wxVERTICAL);
    StaticText25 = new wxStaticText(Panel3, ID_STATICTEXT25, _("Description:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    wxFont StaticText25Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText25->SetFont(StaticText25Font);
    BoxSizer33->Add(StaticText25, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    html_description_bootloader = new wxHtmlWindow(Panel3, ID_HTMLWINDOW2, wxDefaultPosition, wxSize(360,328), wxHW_SCROLLBAR_AUTO|wxSIMPLE_BORDER, _T("ID_HTMLWINDOW2"));
    html_description_bootloader->SetBorders(1);
    html_description_bootloader->SetPage(_("Bootloader description"));
    BoxSizer33->Add(html_description_bootloader, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer32->Add(BoxSizer33, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer34 = new wxBoxSizer(wxVERTICAL);
    StaticText26 = new wxStaticText(Panel3, ID_STATICTEXT26, _("Log:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    wxFont StaticText26Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText26->SetFont(StaticText26Font);
    BoxSizer34->Add(StaticText26, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_lbox_bootloader = new wxListBox(Panel3, ID_LISTBOX2, wxDefaultPosition, wxSize(360,328), 0, 0, wxLB_HSCROLL, wxDefaultValidator, _T("ID_LISTBOX2"));
    BoxSizer34->Add(m_lbox_bootloader, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer32->Add(BoxSizer34, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer30->Add(BoxSizer32, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    b_source_bootloader = new wxButton(Panel3, ID_BUTTON8, _("Edit source"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    b_source_bootloader->Disable();
    BoxSizer31->Add(b_source_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_make_bootloader = new wxButton(Panel3, ID_BUTTON9, _("Make"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    b_make_bootloader->Disable();
    BoxSizer31->Add(b_make_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_clean_bootloader = new wxButton(Panel3, ID_BUTTON10, _("Clean"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    b_clean_bootloader->Disable();
    BoxSizer31->Add(b_clean_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    b_info_bootloader = new wxButton(Panel3, ID_BUTTON11, _("More information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    BoxSizer31->Add(b_info_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer31->Add(239,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_program_bootloader = new wxButton(Panel3, ID_BUTTON12, _("Program"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    b_program_bootloader->Disable();
    b_program_bootloader->SetToolTip(_("will take you to avrdude panel"));
    b_program_bootloader->SetHelpText(_("will take you to avrdude panel"));
    BoxSizer31->Add(b_program_bootloader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer30->Add(BoxSizer31, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer25->Add(BoxSizer30, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    Panel3->SetSizer(BoxSizer25);
    BoxSizer25->SetSizeHints(Panel3);
    nb_main->AddPage(pl_welcome, _("   welcome   "), false);
    nb_main->AddPage(pl_avrdude, _("   avrdude   "), false);
    nb_main->AddPage(pl_firmware, _("   firmware   "), false);
    nb_main->AddPage(pl_bootloader, _("   bootloader   "), false);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBar1->SetToolBitmapSize(wxSize(32,32));
    ToolBarItem1 = ToolBar1->AddTool(tb_submit, _("Share your project"), wxBitmap(wxImage(_T("new.png"))), wxBitmap(wxImage(_T("new.png"))), wxITEM_NORMAL, _("Share your project"), wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(tb_update, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Check for update"), wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(tb_help, _("Help"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Help (www)"), wxEmptyString);
    ToolBarItem4 = ToolBar1->AddTool(tb_quit, _("Quit"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Cheers"), wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Center();

    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_ad_flashClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_ad_eepromClick);
    Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_ad_deviceSelect);
    Connect(ID_CHOICE7,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_ad_programmerSelect);
    Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_ad_portSelect);
    Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&workinprogressFrame::Ontc_lowText);
    Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&workinprogressFrame::Ontc_highText);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&workinprogressFrame::Ontc_extendedText);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_fusesClick);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_fuse_calculatorClick);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Oncb_dClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Oncb_eClick);
    Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Oncb_vClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_fetchClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_ad_executeClick);
    Connect(ID_NOTEBOOK_FIRM,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&workinprogressFrame::Onnb_viaPageChanged);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_openClick);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_microcontrollerSelect);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_categorySelect);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_firmwareSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_sourceClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_makeClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_cleanClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_infoClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::usb_program);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_open_bootloaderClick);
    Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_microcontroller_bootloaderSelect);
    Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&workinprogressFrame::Onc_bootloaderSelect);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_source_bootloaderClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_make_bootloaderClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_clean_bootloaderClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_infoClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Onb_program_bootloaderClick);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&workinprogressFrame::Onnb_mainPageChanged);
    Connect(tb_submit,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Ontb_shareClicked);
    Connect(tb_update,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Ontb_updateClicked);
    Connect(tb_help,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&workinprogressFrame::Ontb_helpClicked);
    Connect(tb_quit,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&workinprogressFrame::OnQuit);
    //*)

    //CUSTOM
    g_application_dir = GetCurrentWorkingDirectory();
    wxDir dir(g_application_dir+_T("firmware")+DS);
    wxString filename;
    bool cont = dir.GetFirst(&filename, _T(""), wxDIR_DIRS);
    c_microcontroller->Append(_T(""));
    while ( cont ) {
        c_microcontroller->Append(filename.c_str());
        cont = dir.GetNext(&filename);
    }

    wxDir dir_bootloader(g_application_dir+_T("bootloader")+DS);
    wxString filename_bootloader;
    bool cont_bootloader = dir_bootloader.GetFirst(&filename_bootloader, _T(""), wxDIR_DIRS);
    c_microcontroller_bootloader->Append(_T(""));
    while ( cont_bootloader ) {
        c_microcontroller_bootloader->Append(filename_bootloader.c_str());
        cont_bootloader = dir_bootloader.GetNext(&filename_bootloader);
    }

    //avrdude.conf fetch programmer / device
    #if defined(__WXMSW__)
        wxGetEnv(_T("AVR32_HOME"), &avrdudepath);
        if(avrdudepath == _T("")) {
            wxMessageBox(_T("You don't have WinAVR installed (or you removed the environment variable).\nYou will not be able to use AVRDUDE or compiling program.\nYou can still use the USB or Ethernet bootloader (if your chip has been bootloaded with it)."));
            wxLaunchDefaultBrowser(_T("http://winavr.sourceforge.net/"));
        } else {
            wxFileInputStream input(avrdudepath+_T("\\bin\\avrdude.conf"));
            wxTextInputStream text( input );
            wxString line;
            size_t part_ix_start = 11;
            size_t device_ix_start = 24;
            size_t remove = 3;
            bool put = 0;
            wxString device_string;
            wxString device_id;
            while(input.IsOk() && !input.Eof() )
            {
                wxString line=text.ReadLine();
                if(line.Find(wxT("  id    = \"")) >= 0) {
                    c_ad_programmer->Append(line.SubString(part_ix_start, line.Length() - remove));
                }
                if(line.Find(wxT("    id               = \""))) {
                    device_id = line.SubString(device_ix_start, line.Length() - remove);
                    put = false;
                }
                if(line.Find(wxT("    desc             = \""))) {
                    device_string = line.SubString(device_ix_start, line.Length() - remove);
                    c_ad_device->Append(device_string);
                    put = true;
                }
                if(put) {
                    device[device_string] = device_id;
                }
            }
        }
    #elif defined(__WXGTK__)
        wxString avrgcc;
        wxArrayString output, errors;
        int code = wxExecute(_T("which avr-gcc"), output, errors);
        if ( code != -1 )
        {
            if(!output.IsEmpty()) {
                avrgcc = output[0];
            }
        }
        if(avrgcc == _T("")) {
            wxMessageBox(_T("GCC-AVR is not installed. You will not be able to compile program.\n\nsudo aptitude install gcc-avr"));
        }
        output.Empty();
        errors.Empty();
        code = wxExecute(_T("which avrdude"), output, errors);
        if ( code != -1 )
        {
            if(!output.IsEmpty()) {
                avrdudepath = output[0];
            }
        }
        if(avrdudepath == _T("")) {
            wxMessageBox(_T("You don't have AVRDUDE installed.\nYou will not be able to use AVRDUDE.\nYou can still use the USB or Ethernet bootloader (if your chip has been bootloaded with it).\n\nsudo aptitude install avrdude"));
        } else {
            wxFileInputStream input(_T("/etc/avrdude.conf"));
            wxTextInputStream text( input );
            wxString line;
            size_t remove = 3;
            bool programmerdef = 0;
            bool partdef = 0;

            bool programmerid = 0;
            bool programmerdesc = 0;

            bool partid = 0;
            bool partdesc = 0;
            bool put = 0;

            wxString device_string;
            wxString device_id;
            while(input.IsOk() && !input.Eof() )
            {

                wxString line=text.ReadLine();


                if(line.Find(wxT("PROGRAMMER DEFINITIONS")) >= 0) {
                    programmerdef = 1;
                }

                if(programmerdef) {

                    if(programmerdesc) {
                            //wxMessageBox(_T(line));
                            programmerdesc = 0;
                    }

                    if(programmerid) {
                            //wxMessageBox(_T(line));
                            c_ad_programmer->Append(line.SubString(line.Find(_T("\"")) + 1, line.Length() - remove));
                            programmerid = 0;
                            programmerdesc = 1;
                    }

                    if(line.Find(wxT("programmer")) >= 0 && line.Length() == 10) {
                        programmerid = 1;
                    }

                }



                if(line.Find(wxT("PART DEFINITIONS")) >= 0) {
                    programmerdef = 0;
                    partdef = 1;
                }

                if(partdef) {

                    if(partdesc) {
                            if(line.Find(wxT("desc")) >= 0) {
                                device_string = line.SubString(line.Find(_T("\"")) + 1, line.Length() - remove);
                                c_ad_device->Append(device_string);
                            }
                            partdesc = 0;
                            put = true;
                    }

                    if(partid) {
                            device_id = line.SubString(line.Find(_T("\"")) + 1, line.Length() - remove);
                            partid = 0;
                            partdesc = 1;
                            put = false;
                    }

                    if(line.Find(wxT("part")) >= 0 && line.Length() == 4) {
                        partid = 1;
                    }

                    if(put) {
                        device[device_string] = device_id;
                        put = false;
                    }

                }


                /*

                if(line.Find(wxT("  id    = \"")) >= 0) {
                    c_ad_programmer->Append(line.SubString(part_ix_start, line.Length() - remove));
                }



                if(line.Find(wxT("    id               = \"")) >= 0) {
                    device_id = line.SubString(device_ix_start, line.Length() - remove);
                    put = false;

                }
                if(line.Find(wxT("    desc             = \"")) >= 0) {
                    device_string = line.SubString(device_ix_start, line.Length() - remove);
                    c_ad_device->Append(device_string);

                    put = true;
                }

                put = false;
                */
            }
        }
    #endif
}

workinprogressFrame::~workinprogressFrame()
{
    //(*Destroy(workinprogressFrame)
    //*)
}

/*
* TOOLBAR ------------------------------------------------------------------
*/
void workinprogressFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void workinprogressFrame::Ontb_helpClicked(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://www.workinprogress.ca/yaku/help.php"));
}

void workinprogressFrame::Ontb_updateClicked(wxCommandEvent& event)
{
	wxString opts;
    opts += wxT(" --savelog");
    opts += wxT(" --restart");
    opts += wxT(" --xrc=webupdatedlg.xrc");
    opts += wxT(" --res=wxWebUpdateSimpleDlg");
    #ifdef __WXMSW__
        wxExecute(wxT("webupdater.exe") + opts);
    #else
        wxExecute(wxT("./webupdater") + opts);
    #endif
	Close(true);
}

void workinprogressFrame::Ontb_shareClicked(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://www.workinprogress.ca/yaku/share.php"));
}

/*
* USB ------------------------------------------------------------------
*/
void workinprogressFrame::usb_program(wxCommandEvent& event)
{
    //Get NoteBook current page
    unsigned int nb_current_page = nb_via->GetSelection();

    //clear log
    m_lbox->Clear();

    if(nb_current_page == 0) {
        //usb
        wxString restart = _T("");
        if(cb_restart->GetValue()) {
            restart = _T("-r");
        }
        if(tc_file->GetValue() == _T("")) {
            wxMessageBox(_T("You need to select your fimware or an available firmware before programming the device."));
        } else {
            if(cb_bootloader->GetValue()) {
                wxMessageBox(_T("Need to be implemented in USB"));
            }
            #if defined(__WXMSW__)
                wxString cmd = _T("bootloadHID ")+restart+_T(" \"")+tc_file->GetValue()+_T("\" ")+tc_vendor_id->GetValue()+_T(" ")+tc_vendor_string->GetValue()+_T(" ")+tc_product_id->GetValue()+_T(" ")+tc_product_string->GetValue();
            #elif defined(__WXGTK__)
                wxString cmd = PathGTK(g_application_dir)+_T("bootloadHID ")+restart+_T(" ")+PathGTK(tc_file->GetValue())+_T(" ")+tc_vendor_id->GetValue()+_T(" ")+tc_vendor_string->GetValue()+_T(" ")+tc_product_id->GetValue()+_T(" ")+tc_product_string->GetValue();
            #endif
            wxMessageBox(cmd);
            wxArrayString output, errors;
            int code = wxExecute(cmd, output, errors);

            if ( code != -1 )
            {
                ShowOutput(cmd, output, _T("Output"), m_lbox);
                ShowOutput(cmd, errors, _T("Errors"), m_lbox);
            }
        }

    } else if(nb_current_page == 1) {
        //ETHERNET

        wxProgressDialog dialog(wxT("Be patient"), wxT("Programming the device"), 10, this, wxPD_APP_MODAL);

        if(!local_port) {
            wxIPV4address addr;
            addr.Service(tc_local_port->GetValue());
            addr.Hostname(addr.IPAddress());
            pSocket = new wxDatagramSocket(addr,wxSOCKET_NOWAIT);
            pSocket->SetTimeout(500);
            pSocket->GetLocal(addr);
            if (! pSocket->Ok())
            {
                m_lbox->Append(wxString::Format(_T("Cannot use Local UDP port : %i\n"),addr.Service()));
            }
            else
            {
                m_lbox->Append(wxString::Format(_T("Open Local UDP port %i OK\n"),addr.Service()));
            }

            pSocket->SetEventHandler(*this, 0);
            pSocket->SetNotify(wxSOCKET_INPUT_FLAG);
            pSocket->Notify(true);
            local_port = 1;
        }
//        dialog.Pulse();
        //ethernet
        wxIPV4address avrAdr;
        avrAdr.AnyAddress();
        wxString s;
        wxUint32 i, j, len, blocksize;
        wxChar *buf = new wxChar[256];
        wxChar *verify_buf = new wxChar[61440];
        memset(buf, 0, 256);
        // check open hex file *********************************************************
        if(tc_file->GetValue() == _T("")) {
            wxMessageBox(_T("Please open new firmware!"));
            return;
        }
        avrAdr.Service(tc_device_port->GetValue());
        avrAdr.Hostname(tc_ip->GetValue());

        if(cb_bootloader->GetValue()) {
            // reset ****************************************************************
            m_lbox->Append(_T("Resetting...\n"));
            pSocket->SendTo(avrAdr, _T("RS\r\n"), 4);
            for(i=0;i<1000;i++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
                if ( i % 10 == 0 ) {
//                    dialog.Pulse();
                }
            }
            if(buf[0]=='Y')
            {
                m_lbox->Append(_T("Entering bootloader..."));
                ::wxMilliSleep(1000);
            }
            else
            {
                m_lbox->Append(_T("Cannot reset the device:"));
                m_lbox->Append(_T("Do you have the reset code in your firmware?"));
            }
        }
//        dialog.Pulse();
        // enter to bootloader *********************************************************
        pSocket->SendTo(avrAdr, _T("P"), 1); // enter to bootloader
        memset(buf, 0, 256);
        for(i=0;i<1000;i++)
        {
            len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
            if(len!=0)
                break;
            ::wxMilliSleep(1);
            if ( i % 10 == 0 ) {
                dialog.Pulse();
            }
        }
        if(buf[0] != '\r')
        {
            s = _T("Cannot find bootloader @ ")+tc_ip->GetValue();
            m_lbox->Append(s);
            m_lbox->Append(_T("Upgrade fail"));
            return;
        } else {
            s = _T("Found the bootloader @ ")+tc_ip->GetValue();
            m_lbox->Append(s);
        }
//        dialog.Pulse();
        // get block size **************************************************************
        m_lbox->Append(_T("Getting blocksize..."));
        pSocket->SendTo(avrAdr, "b", 1);
        memset(buf, 0, 256);
        for(i=0;i<1000;i++)
        {
            len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
            if(len!=0)
                break;
            ::wxMilliSleep(1);
            if ( i % 10 == 0 ) {
                dialog.Pulse();
            }
        }
        blocksize = (((buf[1]&0xff)<<8)|(buf[2]&0xff))&0xffff;
        m_lbox->Append(_T("Blocksize=")+s.Format(_T("%d"), blocksize)+_T("-Bytes\n"));
//        dialog.Pulse();
        // erase chip ***************************************************************
        m_lbox->Append(_T("Erasing chip...")); //
        pSocket->SendTo(avrAdr, "e", 1);
        memset(buf, 0, 256);
        for(i=0;i<1000;i++)
        {
            len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
            if(len!=0)
                break;
            ::wxMilliSleep(1);
            if ( i % 2 == 0 ) {
//                dialog.Pulse();
            }
        }
        if(buf[0] != '\r')
        {
            m_lbox->Append(_T("Fail!\n"));
            wxMessageBox(s.Format(_T("%s"),buf));
            return;
        }
//        dialog.Pulse();
        // program chip ***************************************************************
        m_lbox->Append(_T("Pass"));
        m_lbox->Append(_T("Programming flash..."));
        // set address
        buf[0] = 'A'; buf[1] = 0; buf[2] = 0;
        pSocket->SendTo(avrAdr, buf, 3);
        memset(buf, 0, 256);
        for(i=0;i<1000;i++)
        {
            len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
            if(len!=0)
                break;
            ::wxMilliSleep(1);
            if ( i % 2 == 0 ) {
                dialog.Pulse();
            }
        }
        if(buf[0] != '\r')
        {
            wxMessageBox(_T("Set address fail!"));
            return;
        }
        memset(buf, 0, 256);
        for(i=0;i<progaddr;i+=blocksize)
        {
            if((progaddr-i)<blocksize)
            {
                break;
            }
            buf[0] = 'B'; // send block load command
            buf[1] = (blocksize>>8)&0xff;
            buf[2] = blocksize&0xff;
            buf[3] = 'F'; // memory type is flash
            for(j=0;j<blocksize;j++)
            {
                buf[4+j] = progmem[i+j];
            }
            pSocket->SendTo(avrAdr, buf, 4+blocksize);
            memset(buf, 0, 256);
            for(j=0;j<200;j++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
                if ( j % 2 == 0 ) {
//                dialog.Pulse();
                }
            }
        }
        if(i<progaddr)
        {
            buf[0] = 'B';
            buf[1] = ((progaddr-i)>>8)&0xff;
            buf[2] = (progaddr-i)&0xff;
            buf[3] = 'F';
            for(j=0;j<(progaddr-i);j++)
            {
                buf[4+j] = progmem[i+j];
            }
            pSocket->SendTo(avrAdr, buf, 4+(progaddr-i));
            for(j=0;j<200;j++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
                if ( j % 2 == 0 ) {
//                    dialog.Pulse();
                }
            }
        }
//        dialog.Pulse();
        // verify chip ***************************************************************
        m_lbox->Append(_T("Verifying..."));
        buf[0] = 'A'; buf[1] = 0; buf[2] = 0; // set address
        pSocket->SendTo(avrAdr, buf, 3);
        memset(buf, 0, 256);
        for(i=0;i<200;i++)
        {
            len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
            if(len!=0)
                break;
            ::wxMilliSleep(1);
            if ( i % 2 == 0 ) {
//                dialog.Pulse();
            }
        }
        if(buf[0] != '\r')
        {
            wxMessageBox(_T("Set address fail!"));
            return;
        }
        for(i=0;i<progaddr;i+=blocksize)
        {
            memset(buf, 0, 256);
            if((progaddr-i)<blocksize)
            {
                break;
            }
            buf[0] = 'g'; // send block read command
            buf[1] = (blocksize>>8)&0xff;
            buf[2] = blocksize&0xff;
            buf[3] = 'F'; // memory type is flash
            pSocket->SendTo(avrAdr, buf, 4);
            memset(buf, 0, 256);
            for(j=0;j<200;j++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
            }
            for(j=0;j<blocksize;j++)
            {
                verify_buf[i+j] = buf[j];
            }
        }
        if(i<progaddr)
        {
            buf[0] = 'g';
            buf[1] = ((progaddr-i)>>8)&0xff;
            buf[2] = (progaddr-i)&0xff;
            buf[3] = 'F';
            for(j=0;j<(progaddr-i);j++)
            {
                buf[4+j] = progmem[i+j];
            }
            pSocket->SendTo(avrAdr, buf, 4+(progaddr-i));
            memset(buf, 0, 256);
            for(j=0;j<200;j++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
            }
            for(j=0;j<blocksize;j++)
            {
                verify_buf[i+j] = buf[j];
            }
        }
        for(i=0;i<progaddr;i++)
        {
            if(verify_buf[i] != progmem[i])
            {
                m_lbox->Append(_T("Fail!\n"));
                s = _T("Programming fail!\nAddress ");
                s += s.Format(_T("0x%04X is 0x%02X [should be 0x%02X]"), i, verify_buf[i], progmem[i]);
                wxMessageBox(s);
                m_lbox->Append(s);
                return;
            }
        }

        m_lbox->Append(_T("Pass"));
        m_lbox->Append(_T("Upgrade complete"));
//        dialog.Pulse();
        // reset mcu ***************************************************************
        if(cb_restart->GetValue()) {
            pSocket->SendTo(avrAdr, "E", 1);
            for(j=0;j<200;j++)
            {
                len = pSocket->RecvFrom(avrAdr, buf, 256 * sizeof(wxChar)).LastCount();
                if(len!=0)
                    break;
                ::wxMilliSleep(1);
                if ( j % 2 == 0 ) {
//                    dialog.Pulse();
                }
            }
            m_lbox->Append(_T("Resetting..."));
        }

    } else if(nb_current_page == 2) {
        //avrdude
        tc_ad_flash->SetValue(tc_file->GetValue());
        c_ad_device->SetStringSelection(c_microcontroller->GetStringSelection().MakeUpper());
        if(cb_asp->GetValue()) {
            c_ad_programmer->SetStringSelection("usbasp");
            c_ad_port->SetStringSelection("usb");
        }
        cb_d->SetValue(1);
        nb_main->ChangeSelection(1);
        buildcommand();
    }

}

//VARIOUS FUNCTION
void workinprogressFrame::Onb_openClick(wxCommandEvent& event)
{

    wxString filename = wxFileSelector(_T("Choose a file to open"), _T(""), _T(""), _T(""), _T("HEX files (*.hex)|*.hex"));
    wxFile hFile;
    unsigned char buff[PROGMEM_SIZE];
    wxString str;

    if ( !filename.empty() )
    {
        // work with the file
        tc_file->SetValue(filename);
        hFile.Open(filename);
        hFile.Read(&buff, hFile.Length());
        memset(progmem, 0xff, PROGMEM_SIZE);
        progaddr = HexConverter((unsigned char*)&buff, (unsigned char*)&progmem);
        m_lbox->Clear();
        m_lbox->Append(_T("Program memory size : ") + str.Format(_T("%d"), progaddr) + _T("-Bytes\n") );
    }

	b_program->Enable();
	c_microcontroller->Select(0);

    c_category->Clear();
    c_firmware->Clear();

    b_info->Enable(0);
    html_description->SetPage(_T(""));
    b_source->Enable(0);
    b_make->Enable(0);
    b_clean->Enable(0);

}


unsigned int workinprogressFrame::HexConverter(unsigned char *hex, unsigned char *buff) {
    unsigned int address, tlen=0;
    unsigned char dlen, ck, type;
    for(;;)
    {
        // ':' start of record
        if((*hex) == ':')
            hex++;
        // data length in record
        dlen = (Ascii2Hex(hex[0])<<4)|Ascii2Hex(hex[1]);
        hex += 2;
        ck = dlen;
        // start address in record
        address = (Ascii2Hex(hex[0])<<12)|(Ascii2Hex(hex[1])<<8)|(Ascii2Hex(hex[2])<<4)|(Ascii2Hex(hex[3]));
        hex += 4;
        // record type
        type = (Ascii2Hex(hex[0])<<4)|Ascii2Hex(hex[1]);
        hex += 2;
        if(type==0x01)
            break;
        // record data
        while(dlen--)
        {
            buff[address] = (Ascii2Hex(hex[0])<<4)|Ascii2Hex(hex[1]);
            hex += 2;
            ck += buff[address];
            address++;
            tlen++;
        }
        hex += 2;
        // end of record
        if(*hex == '\r')
            hex++;
        if(*hex == '\n')
            hex++;
    }
    return tlen;
}

unsigned char workinprogressFrame::Ascii2Hex(unsigned char ascii)
{
    if(ascii>='0' && ascii <= '9')
    {
        return (ascii-'0');
    }
    else if(ascii>='a' && ascii <= 'f')
    {
        return ((ascii-'a')+0x0a);
    }
    else if(ascii>='A' && ascii <= 'F')
    {
        return ((ascii-'A')+0x0a);
    }
    else
    {
        return 0;
    }
}

void workinprogressFrame::ShowOutput(const wxString& cmd, const wxArrayString& output, const wxString& title, wxListBox* box)
{
    size_t count = output.GetCount();
    if ( !count )
        return;

    //m_lbox->Append(wxString::Format(_T("--- %s of '%s' ---"), title.c_str(), cmd.c_str()));

    for ( size_t n = 0; n < count; n++ )
    {
        box->Append(output[n]);
    }

    //m_lbox->Append(wxString::Format(_T("--- End of %s ---"), title.Lower().c_str()));
}


void workinprogressFrame::Onb_infoClick(wxCommandEvent& event)
{
    unsigned int nb_current_page = nb_main->GetSelection();
    if(g_help == _T("")) {
        if(nb_current_page == 2) {
            wxLaunchDefaultBrowser(_T("http://www.workinprogress.ca/yaku/description.php?page=firmware"));
        } else if(nb_current_page == 3) {
            wxLaunchDefaultBrowser(_T("http://www.workinprogress.ca/yaku/description.php?page=bootloader"));
        }
    } else {
        wxLaunchDefaultBrowser(_T("http://www.workinprogress.ca/yaku/description.php?page=")+g_help);
    }

}



void workinprogressFrame::Onc_microcontrollerSelect(wxCommandEvent& event)
{
    g_microcontroller = event.GetString();

    c_category->Clear();
    c_firmware->Clear();

    b_info->Enable(0);
    html_description->SetPage(_T(""));
    b_source->Enable(0);
    b_make->Enable(0);
    b_clean->Enable(0);
    b_program->Enable(0);

    if(g_microcontroller != _T("")) {

        wxDir dir(g_application_dir+_T("firmware")+DS+g_microcontroller+DS);
        wxString filename;
        bool cont = dir.GetFirst(&filename, _T(""), wxDIR_DIRS);
        while ( cont ) {
            c_category->Append(filename.c_str());
            cont = dir.GetNext(&filename);
        }
        c_category->Enable(1);
    } else {
        c_category->Enable(0);
        c_firmware->Enable(0);
    }
}

void workinprogressFrame::Onc_categorySelect(wxCommandEvent& event)
{
    g_category = event.GetString();
    c_firmware->Clear();

    wxDir dir(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+event.GetString()+DS);
    wxString filename;
    bool cont = dir.GetFirst(&filename, _T(""), wxDIR_DIRS);
    while ( cont ) {
        c_firmware->Append(filename.c_str());
        cont = dir.GetNext(&filename);
    }
    c_firmware->Enable(1);
}

void workinprogressFrame::Onc_firmwareSelect(wxCommandEvent& event)
{
    g_firmware = event.GetString();
    g_help = g_firmware;
    b_program->Enable();
    tc_file->SetValue(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS+g_firmware+_T(".hex"));

    wxFile hFile;
    unsigned char buff[PROGMEM_SIZE];
    wxString str;
    hFile.Open(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS+g_firmware+_T(".hex"));
    hFile.Read(&buff, hFile.Length());
    memset(progmem, 0xff, PROGMEM_SIZE);
    progaddr = HexConverter((unsigned char*)&buff, (unsigned char*)&progmem);
    m_lbox->Clear();
    m_lbox->Append(_T("Program memory size : ") + str.Format(_T("%d"), progaddr) + _T("-Bytes\n") );


    b_info->Enable(1);
    html_description->LoadFile(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS+g_firmware+_T(".html"));
    b_source->Enable(1);
    b_make->Enable(1);
    b_clean->Enable(1);
}

void workinprogressFrame::Onb_sourceClick(wxCommandEvent& event)
{
    /*
    TO DUPLICATE TO DIRECTORY... v.02 maybe
    bool docopy;
    switch ( wxMessageBox(_T("Copy the folder in a new location to avoid losing your work in case of an upgrade?"),
                          _T("Exec question"),
                          wxYES_NO | wxCANCEL | wxICON_QUESTION, this) )
    {
        case wxYES:
            docopy = true;
            break;

        case wxNO:
            docopy = false;
            break;

        default:
            return;
    }

    if(docopy) {
        wxString u_folder = wxGetTextFromUser(_T("Enter the command: "), _T("Name of folder without space and any special chars"));
        wxSetWorkingDirectory(wxGetCwd()+"\\firmware\\"+g_microcontroller+"\\"+g_category+"\\");
        wxArrayString output;
        wxArrayString errors;
        wxExecute("mkdir "+u_folder, output, errors, wxEXEC_SYNC);
        wxSetWorkingDirectory(wxGetCwd()+"\\"+u_folder);
        wxExecute("xcopy \""+g_application_dir+"\\firmware\\"+g_microcontroller+"\\"+g_category+"\\"+g_firmware+"\"", output, errors, wxEXEC_SYNC);

        c_firmware->Clear();

        wxDir dir(g_application_dir+"\\firmware\\"+g_microcontroller+"\\"+g_category+"\\");
        wxString filename;
        bool cont = dir.GetFirst(&filename, "", wxDIR_DIRS);
        while ( cont ) {
            c_firmware->Append(filename.c_str());
            cont = dir.GetNext(&filename);
        }

        c_firmware->FindString(u_folder);

    } else {
        wxSetWorkingDirectory(wxGetCwd()+"\\firmware\\"+g_microcontroller+"\\"+g_category+"\\"+g_firmware+"\\");
    }
    */
    //might not work in windows...
    wxMessageBox(_T("Becareful if you change the files an upgrade might overwrite your change"));
    wxString opts;
    wxArrayString csource;
    wxDir::GetAllFiles(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS, &csource, _("*.c"), wxDIR_FILES|wxDIR_DIRS);
    unsigned int i;
    for(i = 0; i < csource.GetCount(); i++) {
        opts.Append(_T("\"")+csource[i]+_T("\" "));
    }
    wxArrayString hsource;
    wxDir::GetAllFiles(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS, &hsource, _("*.h"), wxDIR_FILES|wxDIR_DIRS);
    for(i = 0; i < hsource.GetCount(); i++) {
        opts.Append(_T("\"")+hsource[i]+_T("\" "));
    }
    #if defined(__WXMSW__)
        wxExecute(avrdudepath+_T("\\pn\\pn.exe ")+opts);
    #elif defined(__WXGTK__)
        wxExecute(_T("gedit ")+opts);
    #endif
}

void workinprogressFrame::Onb_makeClick(wxCommandEvent& event)
{
    wxProgressDialog dialog(wxT("Be patient"), wxT("Compiling the bootloader"), 10, this, wxPD_APP_MODAL);
    //clear log
    m_lbox->Clear();
    dialog.Pulse();
    wxSetWorkingDirectory(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS);
    dialog.Pulse();
    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+_T("\\utils\\bin\\make.exe");
    #elif defined(__WXGTK__)
        wxString cmd = _T("make");
    #endif
    dialog.Pulse();

    wxArrayString output, errors;
    int code = wxExecute(cmd, output, errors);

    if ( code != -1 )
    {
        ShowOutput(cmd, output, _T("Output"), m_lbox);
        dialog.Pulse();
        ShowOutput(cmd, errors, _T("Errors"), m_lbox);
        dialog.Pulse();
    }

    wxSetWorkingDirectory(g_application_dir);
    dialog.Pulse();
}

void workinprogressFrame::Onb_cleanClick(wxCommandEvent& event)
{
    //clear log
    m_lbox->Clear();
    wxSetWorkingDirectory(g_application_dir+_T("firmware")+DS+g_microcontroller+DS+g_category+DS+g_firmware+DS);
    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+_T("\\utils\\bin\\make.exe clean");
    #elif defined(__WXGTK__)
        wxString cmd = _T("make clean");
    #endif

    wxArrayString output, errors;
    int code = wxExecute(cmd, output, errors);

    if ( code != -1 )
    {
        ShowOutput(cmd, output, _T("Output"), m_lbox);
        ShowOutput(cmd, errors, _T("Errors"), m_lbox);
    }

    wxSetWorkingDirectory(g_application_dir);
}

void workinprogressFrame::Onb_open_bootloaderClick(wxCommandEvent& event)
{
    wxString filename = wxFileSelector(_T("Choose a file to open"), _T(""), _T(""), _T(""), _T("HEX files (*.hex)|*.hex"));
    wxFile hFile;
    unsigned char buff[PROGMEM_SIZE];
    wxString str;

    if ( !filename.empty() )
    {
        // work with the file
        tc_file_bootloader->SetValue(filename);
        hFile.Open(filename);
        hFile.Read(&buff, hFile.Length());
        memset(progmem, 0xff, PROGMEM_SIZE);
        progaddr = HexConverter((unsigned char*)&buff, (unsigned char*)&progmem);
    }

	b_program_bootloader->Enable();
	c_microcontroller_bootloader->Select(0);
    c_bootloader->Clear();

    b_info_bootloader->Enable(0);
    m_lbox_bootloader->Append(_T("Program memory size : ") + str.Format(_T("%d"), progaddr) + _T("-Bytes\n"));
    b_source_bootloader->Enable(0);
    b_make_bootloader->Enable(0);
    b_clean_bootloader->Enable(0);
}

void workinprogressFrame::Onb_program_bootloaderClick(wxCommandEvent& event)
{
    tc_ad_flash->SetValue(tc_file_bootloader->GetValue());
    c_ad_device->SetStringSelection(c_microcontroller_bootloader->GetStringSelection().MakeUpper());
    nb_main->ChangeSelection(1);
    buildcommand();
}

void workinprogressFrame::Onc_bootloaderSelect(wxCommandEvent& event)
{
    g_bootloader = event.GetString();
    g_help = g_bootloader;
    b_program_bootloader->Enable();
    tc_file_bootloader->SetValue(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS+g_bootloader+_T(".hex"));
    b_info_bootloader->Enable(1);
    html_description_bootloader->LoadFile(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS+g_bootloader+_T(".html"));
    b_source_bootloader->Enable(1);
    b_make_bootloader->Enable(1);
    b_clean_bootloader->Enable(1);
}

void workinprogressFrame::Onc_microcontroller_bootloaderSelect(wxCommandEvent& event)
{

    g_microcontroller_bootloader = event.GetString();
    c_bootloader->Clear();
    b_info_bootloader->Enable(0);
    html_description_bootloader->SetPage(_T(""));
    b_source_bootloader->Enable(0);
    b_make_bootloader->Enable(0);
    b_clean_bootloader->Enable(0);
    b_program_bootloader->Enable(0);

    if(g_microcontroller_bootloader != _T("")) {
        wxDir dir(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS);
        wxString filename;
        bool cont = dir.GetFirst(&filename, _T(""), wxDIR_DIRS);
        while ( cont ) {
            c_bootloader->Append(filename.c_str());
            cont = dir.GetNext(&filename);
        }
        c_bootloader->Enable(1);
    } else {
     c_bootloader->Enable(0);
    }
}

void workinprogressFrame::Onb_clean_bootloaderClick(wxCommandEvent& event)
{
    //clear log
    m_lbox_bootloader->Clear();
    wxSetWorkingDirectory(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS);
    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+_T("\\utils\\bin\\make.exe clean");
    #elif defined(__WXGTK__)
        wxString cmd = _T("make clean");
    #endif

    wxArrayString output, errors;
    int code = wxExecute(cmd, output, errors);

    if ( code != -1 )
    {
        ShowOutput(cmd, output, _T("Output"), m_lbox_bootloader);
        ShowOutput(cmd, errors, _T("Errors"), m_lbox_bootloader);
    }

    wxSetWorkingDirectory(g_application_dir);
}

void workinprogressFrame::Onb_make_bootloaderClick(wxCommandEvent& event)
{
    wxProgressDialog dialog(wxT("Be patient"), wxT("Compiling the bootloader"), 10, this, wxPD_APP_MODAL);
    //clear log
    m_lbox_bootloader->Clear();
    dialog.Pulse();
    wxSetWorkingDirectory(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS);
    dialog.Pulse();
    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+_T("\\utils\\bin\\make.exe");
    #elif defined(__WXGTK__)
        wxString cmd = _T("make");
    #endif
    dialog.Pulse();

    wxArrayString output, errors;
    int code = wxExecute(cmd, output, errors);

    if ( code != -1 )
    {
        ShowOutput(cmd, output, _T("Output"), m_lbox_bootloader);
        dialog.Pulse();
        ShowOutput(cmd, errors, _T("Errors"), m_lbox_bootloader);
        dialog.Pulse();
    }

    wxSetWorkingDirectory(g_application_dir);
    dialog.Pulse();
}

void workinprogressFrame::Onb_source_bootloaderClick(wxCommandEvent& event)
{
    //might not work in windows...
    wxMessageBox(_T("Becareful if you change the files an upgrade might overwrite your change"));
    wxString opts;
    wxArrayString csource;
    wxDir::GetAllFiles(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS, &csource, _("*.c"), wxDIR_FILES|wxDIR_DIRS);
    unsigned int i;
    for(i = 0; i < csource.GetCount(); i++) {
        opts.Append(_T("\"")+csource[i]+_T("\""));
    }
    wxArrayString hsource;
    wxDir::GetAllFiles(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS, &hsource, _("*.h"), wxDIR_FILES|wxDIR_DIRS);
    for(i = 0; i < hsource.GetCount(); i++) {
        opts.Append(_T("\"")+hsource[i]+_T("\""));
    }
    wxArrayString makefile;
    wxDir::GetAllFiles(g_application_dir+_T("bootloader")+DS+g_microcontroller_bootloader+DS+g_bootloader+DS, &makefile, _("Makefile"), wxDIR_FILES);
    for(i = 0; i < makefile.GetCount(); i++) {
        opts.Append(_T("\"")+makefile[i]+_T("\""));
    }
    #if defined(__WXMSW__)
        wxExecute(_T("Sc221.exe ")+opts);
    #elif defined(__WXGTK__)
        wxExecute(_T("gedit ")+opts);
    #endif
}

void workinprogressFrame::Onb_ad_flashClick(wxCommandEvent& event)
{
    wxString filename = wxFileSelector(_T("Choose a file to open"), _T(""), _T(""), _T(""), _T("HEX files (*.hex)|*.hex"));
    wxFile hFile;
    unsigned char buff[PROGMEM_SIZE];
    wxString str;

    if ( !filename.empty() )
    {
        // work with the file
        tc_ad_flash->SetValue(filename);
        hFile.Open(filename);
        hFile.Read(&buff, hFile.Length());
        memset(progmem, 0xff, PROGMEM_SIZE);
        progaddr = HexConverter((unsigned char*)&buff, (unsigned char*)&progmem);
        m_lbox_ad->Append( _T("Program memory size : ") + str.Format(_T("%d"), progaddr) + _T("-Bytes\n"));
        buildcommand();
    }

}

void workinprogressFrame::Onb_ad_eepromClick(wxCommandEvent& event)
{
    wxString filename = wxFileSelector(_T("Choose a file to open"), _T(""), _T(""), _T(""), _T("EEPROM files (*.eep)|*.eep"));
    wxFile hFile;
    unsigned char buff[PROGMEM_SIZE];
    wxString str;

    if ( !filename.empty() )
    {
        // work with the file
        tc_ad_eeprom->SetValue(filename);
        hFile.Open(filename);
        hFile.Read(&buff, hFile.Length());
        memset(progmem, 0xff, PROGMEM_SIZE);
        progaddr = HexConverter((unsigned char*)&buff, (unsigned char*)&progmem);
        m_lbox_ad->Append( _T("EEPROM size : ") + str.Format(_T("%d"), progaddr) + _T("-Bytes\n"));
        buildcommand();
    }

}

void workinprogressFrame::Onb_ad_executeClick(wxCommandEvent& event)
{
    if(c_ad_device->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a device"));
        return;
    }
    if(c_ad_programmer->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a programmer"));
        return;
    }
    if(c_ad_port->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a port"));
        return;
    }

    wxProgressDialog dialog(wxT("Be patient"), wxT("Programming the device"), 10, this, wxPD_APP_MODAL);
    //clear log
    m_lbox_ad->Clear();
    dialog.Pulse();

    wxArrayString output, errors;
    dialog.Pulse();
    int code = wxExecute(tc_ad_command->GetValue(), output, errors);
    dialog.Pulse();
    if ( code != -1 )
    {
        ShowOutput(tc_ad_command->GetValue(), output, _T("Output"), m_lbox_ad);
        dialog.Pulse();
        ShowOutput(tc_ad_command->GetValue(), errors, _T("Errors"), m_lbox_ad);
        dialog.Pulse();
    }

    //TODO -----------------------------------------------------
    //AVR ISP mkII
    //http://docs.wxwidgets.org/2.9/group__group__funcmacro__string.html#ga77e8bb770f70b5e94aff5b6c7804c44
    //etc/udev/rules.d/75-permissions.rules:
    //ATTRS{idVendor}=="03eb",ATTRS{idProduct}=="2104", MODE="0666"

    dialog.Pulse();
}

void workinprogressFrame::Onb_fetchClick(wxCommandEvent& event)
{
        //clear log
    m_lbox_ad->Clear();
    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+_T("\\bin\\avrdude.exe -p ")+ device[c_ad_device->GetStringSelection()] + _T(" -c ") + c_ad_programmer->GetStringSelection() + _T(" -P ") + c_ad_port->GetStringSelection() + _T(" -v");
    #elif defined(__WXGTK__)
        wxString cmd = avrdudepath+_T(" -p ")+ device[c_ad_device->GetStringSelection()] + _T(" -c ") + c_ad_programmer->GetStringSelection() + _T(" -P ") + c_ad_port->GetStringSelection() + _T(" -v");
    #endif

    wxArrayString output, errors;
    int code = wxExecute(cmd, output, errors);

    if ( code != -1 )
    {
        ShowOutput(cmd, output, _T("Output"), m_lbox_ad);
        ShowOutput(cmd, errors, _T("Errors"), m_lbox_ad);
    }
}

void workinprogressFrame::buildcommand()
{
    tc_ad_command->Clear();
    #if defined(__WXMSW__)
        tc_ad_command->AppendText(avrdudepath+_T("\\bin\\avrdude.exe"));
    #elif defined(__WXGTK__)
        tc_ad_command->AppendText(avrdudepath);
    #endif

    if(cb_v->GetValue()) {
        tc_ad_command->AppendText(_T(" -V"));
    }

    tc_ad_command->AppendText(_T(" -p ") + device[c_ad_device->GetStringSelection()]);
    tc_ad_command->AppendText(_T(" -c ") + c_ad_programmer->GetStringSelection());
    tc_ad_command->AppendText(_T(" -P ") + c_ad_port->GetStringSelection());


    if(tc_low->GetValue().Length() > 1) {
        tc_ad_command->AppendText(_T(" -U lfuse:w:0x") + tc_low->GetValue() + _T(":m"));
    }
    if(tc_high->GetValue().Length() > 1) {
        tc_ad_command->AppendText(_T(" -U hfuse:w:0x") + tc_high->GetValue() + _T(":m"));
    }
    if(tc_extended->GetValue().Length() > 1) {
        tc_ad_command->AppendText(_T(" -U efuse:w:0x") + tc_extended->GetValue() + _T(":m"));
    }

    if(tc_ad_flash->GetValue() != _T("")) {
        #if defined(__WXMSW__)
            tc_ad_command->AppendText(_T(" -U flash:w:\"")+tc_ad_flash->GetValue()+_T("\":a"));
        #elif defined(__WXGTK__)
            tc_ad_command->AppendText(_T(" -U flash:w:")+PathGTK(tc_ad_flash->GetValue())+_T(":a"));
        #endif
    }
    if(tc_ad_eeprom->GetValue() != _T("")) {
        #if defined(__WXMSW__)
            tc_ad_command->AppendText(_T(" -U eeprom:w:\"")+tc_ad_eeprom->GetValue()+_T("\":a"));
        #elif defined(__WXGTK__)
            tc_ad_command->AppendText(_T(" -U eeprom:w:")+PathGTK(tc_ad_eeprom->GetValue())+_T(":a"));
        #endif
    }

    if(cb_d->GetValue()) {
        tc_ad_command->AppendText(_T(" -D"));
    }
    if(cb_e->GetValue()) {
        tc_ad_command->AppendText(_T(" -e"));
    }
}

wxString workinprogressFrame::PathGTK(wxString thepath) {
    wxString randr;
    randr = thepath;
    randr.Replace(_T(" "), _T("\\ "), true);
    return randr;
}

void workinprogressFrame::Onc_ad_deviceSelect(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Onc_ad_programmerSelect(wxCommandEvent& event)
{
    #if defined(__WXMSW__)
        if(c_ad_programmer->GetStringSelection() == _T("avrispmkII")) {
            st_note->SetLabel(_T("If AVRDUDE report that it doesn't find usb, install libusb-win32-devel-filter"));
        } else {
            st_note->SetLabel(_T(""));
        }
    #endif

    buildcommand();
}

void workinprogressFrame::Onc_ad_portSelect(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Onb_fusesClick(wxCommandEvent& event)
{
    if(c_ad_device->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a device"));
        return;
    }
    if(c_ad_programmer->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a programmer"));
        return;
    }
    if(c_ad_port->GetStringSelection() == _T("")) {
        wxMessageBox(_T("You need to select a port"));
        return;
    }
    m_lbox_ad->Clear();

    #if defined(__WXMSW__)
        wxString cmd = avrdudepath+"\\bin\\avrdude.exe"+_T(" -p ")+device[c_ad_device->GetStringSelection()] + _T(" -c ") + c_ad_programmer->GetStringSelection() + _T(" -P ") + c_ad_port->GetStringSelection() + _T(" -U hfuse:r:\""+g_application_dir+"\\fuseh.txt\":h -U lfuse:r:\""+g_application_dir+"\\fusel.txt\":h -U efuse:r:\""+g_application_dir+"\\fusee.txt\":h");
    #elif defined(__WXGTK__)
        wxString cmd = avrdudepath +_T(" -p ")+device[c_ad_device->GetStringSelection()] + _T(" -c ") + c_ad_programmer->GetStringSelection() + _T(" -P ") + c_ad_port->GetStringSelection() + _T(" -U hfuse:r:fuseh.txt:h -U lfuse:r:fusel.txt:h -U efuse:r:fusee.txt:h");
    #endif

    wxArrayString output, errors;
    wxExecute(cmd, output, errors);

    //wxString line;
    wxFileInputStream inputh(g_application_dir+_T("/fuseh.txt"));
    wxTextInputStream texth( inputh );
    tc_high->SetValue(texth.ReadLine().SubString(2,0));

    wxFileInputStream inputl(g_application_dir+_T("/fusel.txt"));
    wxTextInputStream textl( inputl );
    tc_low->SetValue(textl.ReadLine().SubString(2,0));

    wxFileInputStream inpute(g_application_dir+_T("/fusee.txt"));
    wxTextInputStream texte( inpute );
    tc_extended->SetValue(texte.ReadLine().SubString(2,0));

    //delete file
    #if defined(__WXMSW__)
        wxRemoveFile("\""+g_application_dir+_T("\\fuseh.txt")+"\"");
        wxRemoveFile("\""+g_application_dir+_T("\\fusel.txt")+"\"");
        wxRemoveFile("\""+g_application_dir+_T("\\fusee.txt")+"\"");
    #elif defined(__WXGTK__)
        wxRemoveFile(g_application_dir+_T("/fuseh.txt"));
        wxRemoveFile(g_application_dir+_T("/fusel.txt"));
        wxRemoveFile(g_application_dir+_T("/fusee.txt"));
    #endif

}

void workinprogressFrame::Ontc_lowText(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Ontc_highText(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Ontc_extendedText(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Onb_fuse_calculatorClick(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://www.engbedded.com/fusecalc/"));
}

void workinprogressFrame::Oncb_dClick(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Oncb_eClick(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Oncb_vClick(wxCommandEvent& event)
{
    buildcommand();
}

void workinprogressFrame::Onnb_viaPageChanged(wxNotebookEvent& event)
{
    if(nb_via->GetSelection() == 2) {
        cb_bootloader->Enable(0);
        cb_restart->Enable(0);
    } else {
        cb_bootloader->Enable(1);
        cb_restart->Enable(1);
    }
}

void workinprogressFrame::Onnb_mainPageChanged(wxNotebookEvent& event)
{
    if(nb_main->GetSelection() == 1 && !c_ad_programmer->GetCount()) {
        wxMessageBox(_T("Install WinAVR to use AVRDUDE"));
        nb_main->SetSelection(0);
    }
}
