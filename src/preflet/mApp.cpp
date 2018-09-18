/**********************************************************************************/
/*****************        Lock Workstation By Marius Stene        *****************/
/*****************             m_stene@yahoo.com, 2002            *****************/
/*****************        My contribution to this great OS        *****************/
/**********************************************************************************/
/*****************  You are welcome to use any part of this code  *****************/
/*****************      in whole, or in parts freely without      *****************/
/*****************                  contacting me                 *****************/
/**********************************************************************************/
/*
************                                             ************                *********************    
**************                                        ******************            ***********************  
******     *****                                    ****              ****         *****                 ***  
*****       *****                                  ****                ****       *****                       
*****        *****                                ****                  ****      *****                       
*****        *****                               ****                    ****     *****                      
*****        ****                                ****                    ****     *****                      
******    ******                                ****                      ****     **************            
***************                ****             ****                      ****      **********************  
***************            ************         ****                      ****                  ***********  
******    *****          *****      *****       ****                      ****                         *****  
*****       *****      *****         *****       ****                    ****                           *****  
*****        *****     *******************       ****                    ****                           ****  
*****        *****     *******************        ****                  ****                           ****    
*****        ****      *****                       ****                ****                           ****     
******      *****       ******        ***           ****              ****        ***                ****     
***************          ***************              ******************           *********************   
*************              ***********                   ************                ******************  
*/                                                 
#include <iostream>
#include <stdio.h>
#include <Application.h>
#include "mApp.h"

//main(int argc, char* argv[]) < argv[0]
int main(int32 argc, char** argv)
{
new mApp();
//Path to exe file
BString				mPathToExecFile;
BPath 				path;
status_t			status;
BFile				file;
BMessage 			savemessage;

mPathToExecFile.SetTo(argv[0]);
mPathToExecFile.RemoveLast("Preferences");
find_directory(B_USER_SETTINGS_DIRECTORY, &path);
path.Append("LockWorkstationSettings");
status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
savemessage.ReplaceString("execDir", mPathToExecFile);
	if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}
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
MainWindow = new mWindow("Preferences");
if (MainWindow != NULL)
	{
	MainWindow->Show();
	}
else
	{
		be_app->PostMessage(B_QUIT_REQUESTED);
	}
}
