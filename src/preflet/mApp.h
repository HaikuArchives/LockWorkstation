/**********************************************************************************/
/*****************        Lock Workstation By Marius Stene        *****************/
/*****************             m_stene@yahoo.com, 2002            *****************/
/*****************        My contribution to this great OS        *****************/
/**********************************************************************************/
/*****************  You are welcome to use any part of this code  *****************/
/*****************      in whole, or in parts freely without      *****************/
/*****************                  contacting me                 *****************/
/**********************************************************************************/

#ifndef _mApp_h_
#define _mApp_h_

#define ApplicationSignature "application/x-vnd.LockWorkstation-Pref"

#include <Application.h>
#include <Path.h>
#include <Alert.h>
#include <String.h>
#include <Path.h>
#include "mWindow.h"

class mApp : public BApplication
{
public:
						mApp();
						~mApp();
	virtual void		ReadyToRun();
private:
	mWindow*			MainWindow;
};

#endif