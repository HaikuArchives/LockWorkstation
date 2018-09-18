// mApp.cpp
#include <iostream>
#include <stdio.h>
#include <Application.h>
#include "mApp.h"


int main()
{
new mApp();
be_app->Run();

return(0);
}


mApp::mApp()
		: BApplication(ApplicationSignature)
{
}

mApp::~mApp()
{
}

void mApp::ReadyToRun()
{
MainWindow = new mWindow("Main Window");
if (MainWindow != NULL)
	{
	/*
	MainWindow->SetFeel(B_MODAL_APP_WINDOW_FEEL);
	*/
	MainWindow->Show();
	}
else
	{
		be_app->PostMessage(B_QUIT_REQUESTED);
	}
}
