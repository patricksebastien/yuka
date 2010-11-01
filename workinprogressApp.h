/***************************************************************
 * Name:      workinprogressApp.h
 * Purpose:   Defines Application Class
 * Author:    Patrick Sébastien (patrick@11h11.com)
 * Created:   2010-10-11
 * Copyright: Patrick Sébastien (www.workinprogress.ca)
 * License:
 **************************************************************/

#ifndef WORKINPROGRESSAPP_H
#define WORKINPROGRESSAPP_H

#include <wx/app.h>

class workinprogressApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WORKINPROGRESSAPP_H
