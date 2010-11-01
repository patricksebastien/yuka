/***************************************************************
 * Name:      workinprogressApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Patrick Sébastien (patrick@11h11.com)
 * Created:   2010-10-11
 * Copyright: Patrick Sébastien (www.workinprogress.ca)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "workinprogressApp.h"

//(*AppHeaders
#include "workinprogressMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(workinprogressApp);

bool workinprogressApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	workinprogressFrame* Frame = new workinprogressFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
