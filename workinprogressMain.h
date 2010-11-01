/***************************************************************
 * Name:      workinprogressMain.h
 * Purpose:   Defines Application Frame
 * Author:    Patrick Sébastien (patrick@11h11.com)
 * Created:   2010-10-11
 * Copyright: Patrick Sébastien (www.workinprogress.ca)
 * License:
 **************************************************************/

#ifndef WORKINPROGRESSMAIN_H
#define WORKINPROGRESSMAIN_H

//(*Headers(workinprogressFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/html/htmlwin.h>
//*)

//CUSTOM
#include <wx/socket.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include <wx/dir.h>
#include <wx/file.h>
#include <wx/progdlg.h>
#include <wx/textfile.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/regex.h>
#include <wx/stdpaths.h>

//ETHERNET
#define PROGMEM_SIZE    61440 // 4096-bytes reserve for bootloader
WX_DECLARE_STRING_HASH_MAP( wxString, DeviceHash );

class wxDirTraverserSimple : public wxDirTraverser
{
public:
    wxDirTraverserSimple(wxArrayString& files) : m_files(files) { }

    virtual wxDirTraverseResult OnFile(const wxString& filename)
    {
        m_files.Add(filename);
        return wxDIR_CONTINUE;
    }

    virtual wxDirTraverseResult OnDir(const wxString& WXUNUSED(dirname))
    {
        return wxDIR_CONTINUE;
    }

private:
    wxArrayString& m_files;
};


class workinprogressFrame: public wxFrame
{
    public:

        workinprogressFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~workinprogressFrame();

    private:

        //(*Handlers(workinprogressFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Ontb_helpClicked(wxCommandEvent& event);
        void Ontb_updateClicked(wxCommandEvent& event);
        void Ontb_shareClicked(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void usb_program(wxCommandEvent& event);
        void Onb_openClick(wxCommandEvent& event);
        void Onb_infoClick(wxCommandEvent& event);
        void Onc_microcontrollerSelect(wxCommandEvent& event);
        void Onc_categorySelect(wxCommandEvent& event);
        void Onc_firmwareSelect(wxCommandEvent& event);
        void Onb_sourceClick(wxCommandEvent& event);
        void Onb_makeClick(wxCommandEvent& event);
        void Onb_cleanClick(wxCommandEvent& event);
        void Onb_open_bootloaderClick(wxCommandEvent& event);
        void Onb_program_bootloaderClick(wxCommandEvent& event);
        void Onc_bootloaderSelect(wxCommandEvent& event);
        void Onc_microcontroller_bootloaderSelect(wxCommandEvent& event);
        void Onb_clean_bootloaderClick(wxCommandEvent& event);
        void Onb_make_bootloaderClick(wxCommandEvent& event);
        void Onb_source_bootloaderClick(wxCommandEvent& event);
        void Onb_ad_flashClick(wxCommandEvent& event);
        void Onb_ad_eepromClick(wxCommandEvent& event);
        void Onb_ad_executeClick(wxCommandEvent& event);
        void Onb_fetchClick(wxCommandEvent& event);
        void Onc_ad_deviceSelect(wxCommandEvent& event);
        void Onc_ad_programmerSelect(wxCommandEvent& event);
        void Onc_ad_portSelect(wxCommandEvent& event);
        void Onb_fusesClick(wxCommandEvent& event);
        void Ontc_lowText(wxCommandEvent& event);
        void Ontc_highText(wxCommandEvent& event);
        void Ontc_extendedText(wxCommandEvent& event);
        void Onb_fuse_calculatorClick(wxCommandEvent& event);
        void Oncb_dClick(wxCommandEvent& event);
        void Oncb_eClick(wxCommandEvent& event);
        void Oncb_vClick(wxCommandEvent& event);
        void Onnb_viaPageChanged(wxNotebookEvent& event);
        void Onnb_mainPageChanged(wxNotebookEvent& event);
        //*)

        //(*Identifiers(workinprogressFrame)
        static const long ID_STATICTEXT37;
        static const long ID_STATICBITMAP1;
        static const long ID_HTMLWINDOW3;
        static const long ID_PANEL8;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL10;
        static const long ID_BUTTON13;
        static const long ID_TEXTCTRL11;
        static const long ID_BUTTON14;
        static const long ID_STATICTEXT27;
        static const long ID_CHOICE6;
        static const long ID_STATICTEXT28;
        static const long ID_CHOICE7;
        static const long ID_STATICTEXT29;
        static const long ID_CHOICE8;
        static const long ID_STATICTEXT30;
        static const long ID_TEXTCTRL12;
        static const long ID_STATICTEXT31;
        static const long ID_TEXTCTRL13;
        static const long ID_STATICTEXT32;
        static const long ID_TEXTCTRL14;
        static const long ID_BUTTON17;
        static const long ID_BUTTON18;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX5;
        static const long ID_STATICTEXT33;
        static const long ID_TEXTCTRL15;
        static const long ID_STATICTEXT34;
        static const long ID_LISTBOX3;
        static const long ID_STATICTEXT36;
        static const long ID_BUTTON16;
        static const long ID_BUTTON15;
        static const long ID_PANEL16;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_PANEL11;
        static const long ID_PANEL5;
        static const long ID_STATICTEXT15;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT16;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT17;
        static const long ID_TEXTCTRL8;
        static const long ID_PANEL12;
        static const long ID_PANEL10;
        static const long ID_STATICTEXT35;
        static const long ID_CHECKBOX6;
        static const long ID_PANEL14;
        static const long ID_PANEL13;
        static const long ID_NOTEBOOK_FIRM;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT9;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT10;
        static const long ID_CHOICE3;
        static const long ID_STATICTEXT11;
        static const long ID_HTMLWINDOW1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON6;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT12;
        static const long ID_LISTBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX1;
        static const long ID_BUTTON3;
        static const long ID_PANEL7;
        static const long ID_PANEL4;
        static const long ID_STATICTEXT24;
        static const long ID_TEXTCTRL9;
        static const long ID_BUTTON7;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT21;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT22;
        static const long ID_CHOICE5;
        static const long ID_STATICTEXT25;
        static const long ID_HTMLWINDOW2;
        static const long ID_STATICTEXT26;
        static const long ID_LISTBOX2;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_BUTTON10;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_PANEL15;
        static const long ID_PANEL6;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long tb_submit;
        static const long tb_update;
        static const long tb_help;
        static const long tb_quit;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(workinprogressFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxHtmlWindow* html_description;
        wxStaticText* StaticText9;
        wxCheckBox* cb_e;
        wxToolBarToolBase* ToolBarItem4;
        wxStaticText* st_note;
        wxTextCtrl* tc_local_port;
        wxPanel* Panel5;
        wxToolBar* ToolBar1;
        wxPanel* pl_avrdude;
        wxButton* b_ad_eeprom;
        wxTextCtrl* tc_file;
        wxStaticText* StaticText29;
        wxListBox* m_lbox_ad;
        wxToolBarToolBase* ToolBarItem3;
        wxTextCtrl* tc_high;
        wxListBox* m_lbox_bootloader;
        wxStaticText* StaticText33;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxStaticText* StaticText30;
        wxButton* b_open;
        wxTextCtrl* tc_file_bootloader;
        wxChoice* c_ad_device;
        wxStaticText* StaticText26;
        wxStaticText* StaticText6;
        wxPanel* pn_usb;
        wxStaticBitmap* StaticBitmap1;
        wxButton* b_source_bootloader;
        wxButton* b_clean;
        wxTextCtrl* tc_product_string;
        wxChoice* c_microcontroller_bootloader;
        wxPanel* pl_welcome;
        wxButton* b_info_bootloader;
        wxButton* b_make;
        wxStaticText* StaticText32;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxPanel* pl_bootloader;
        wxButton* b_ad_flash;
        wxChoice* c_ad_port;
        wxCheckBox* cb_restart;
        wxPanel* Panel1;
        wxStaticText* StaticText31;
        wxNotebook* nb_main;
        wxButton* b_fuses;
        wxCheckBox* cb_bootloader;
        wxStaticText* StaticText27;
        wxFileDialog* FileDialog1;
        wxPanel* pn_avrdude;
        wxTextCtrl* tc_device_port;
        wxHtmlWindow* html_description_bootloader;
        wxStaticText* StaticText3;
        wxButton* b_source;
        wxButton* b_fetch;
        wxListBox* m_lbox;
        wxPanel* Panel6;
        wxPanel* Panel3;
        wxStaticText* StaticText21;
        wxCheckBox* cb_d;
        wxTextCtrl* tc_extended;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxPanel* pn_ethernet;
        wxToolBarToolBase* ToolBarItem1;
        wxButton* b_open_bootloader;
        wxChoice* c_category;
        wxButton* b_fuse_calculator;
        wxChoice* c_microcontroller;
        wxTextCtrl* tc_ad_flash;
        wxTextCtrl* tc_vendor_string;
        wxStaticText* StaticText5;
        wxStaticText* StaticText34;
        wxStaticText* StaticText7;
        wxTextCtrl* tc_low;
        wxPanel* Panel7;
        wxTextCtrl* tc_product_id;
        wxHtmlWindow* HtmlWindow1;
        wxTextCtrl* tc_vendor_id;
        wxTextCtrl* tc_ip;
        wxButton* b_clean_bootloader;
        wxStaticText* StaticText28;
        wxButton* b_info;
        wxStaticText* StaticText15;
        wxStaticText* StaticText12;
        wxStaticText* StaticText35;
        wxTextCtrl* tc_ad_eeprom;
        wxCheckBox* cb_v;
        wxChoice* c_ad_programmer;
        wxPanel* Panel2;
        wxButton* b_program_bootloader;
        wxNotebook* nb_via;
        wxStaticText* StaticText25;
        wxButton* b_program;
        wxStaticText* StaticText17;
        wxStaticText* StaticText4;
        wxStaticText* StaticText36;
        wxChoice* c_firmware;
        wxButton* b_ad_execute;
        wxPanel* pl_firmware;
        wxCheckBox* cb_asp;
        wxToolBarToolBase* ToolBarItem2;
        wxStaticText* StaticText16;
        wxChoice* c_bootloader;
        wxPanel* fm_panel;
        wxButton* b_make_bootloader;
        wxTextCtrl* tc_ad_command;
        //*)

        //CUSTOM
        wxString GetCurrentWorkingDirectory();
        wxString g_application_dir;
        wxString avrdudepath;
        void ShowOutput(const wxString& cmd, const wxArrayString& output, const wxString& title, wxListBox* box);
        wxString g_help;
        DeviceHash device;
        void buildcommand();
        wxString PathGTK(wxString thepath);

        //AVAILABLE FIRMWARE
        wxString g_microcontroller;
        wxString g_microcontroller_bootloader;
        wxString g_category;
        wxString g_firmware;
        wxString g_bootloader;
        DECLARE_EVENT_TABLE()

        //ETHERNET
        unsigned int HexConverter(unsigned char *hex, unsigned char *buff);
        unsigned char Ascii2Hex(unsigned char ascii);

        wxDatagramSocket *pSocket;
        wxChar progmem[PROGMEM_SIZE];// = new wxChar[57344];
        wxUint32 progaddr;
        bool local_port;
};

#endif // WORKINPROGRESSMAIN_H
