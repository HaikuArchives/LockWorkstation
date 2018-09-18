/**********************************************************************************/
/*****************        Lock Workstation By Marius Stene        *****************/
/*****************             m_stene@yahoo.com, 2002            *****************/
/*****************        My contribution to this great OS        *****************/
/**********************************************************************************/
/*****************  You are welcome to use any part of this code  *****************/
/*****************      in whole, or in parts freely without      *****************/
/*****************                  contacting me                 *****************/
/**********************************************************************************/

#ifndef _mWindow_h_
#define _mWindow_h_

#define TEXTADDUSER 'pro2'
#define TEXTADDPASS 'pro3'
#define USERLIST 'pro4'
#define TEXT_IMAGEPATH 'pro5'
#define BUTTON_DEFAULTPATH 'pro9'
#define BUTTON_BROWSEPATH 'prox'
#define COLOR_CHANGED_R 'prx4'
#define COLOR_CHANGED_G 'prx5'
#define COLOR_CHANGED_B 'prx6'
#define ERASER_FROM_DOOM 'prx8'
#define BUTTON_CLICKED 'pr21'
#define QUIT_TEAM_MONITOR 'Dsab'
#define CLOCKCOLOR_CHANGED_R 'eres'
#define CLOCKCOLOR_CHANGED_G 'ere2'
#define CLOCKCOLOR_CHANGED_B 'ere3'
#define BOOL_CLOCK 'ere5'
#define CLOCKPLACEMENT_X 'ere6'
#define CLOCKPLACEMENT_Y 'ere7'
#define APPLY_EVERYTHING 'ere9'
#define DEFAULT_COLORS 'erea'
#define DEFAULT_CLOCK_COLORS 'eraa'
#define DEFAULT_PLACE 'asda'
#define FOLDER_SELECTED 'asds'
#define SIZE_SLIDER_CHANGED 'asdy'
#define CHANGE_LOGIN 'asd4'
#define BROWSE_FOLDER 'asd3'
#define FOLDER_CHANGED 'a333'
#define LANG_0 'aaaa'
#define LANG_1 'aann'
#define LANG_2 'aan1'
#define LANG_3 'aan2'
#define LANG_4 'aan3'
#define LANG_5 'aan4'
#define LANG_6 'aan5'
#define CHECK_BUTTONS 'ada2'
#define CHECK_USERBUTTON 'wada'

#include <StorageKit.h>
#include <KernelKit.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <SupportKit.h>
#include <TranslationKit.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mBitmap.h"

class mWindow
		: public BWindow
{
public:
						mWindow(const char *mWindowTitle);
						~mWindow();
	virtual void 		MessageReceived(BMessage* message);		
	virtual bool 		QuitRequested();
	BView*				mView;
	BView*				mListView;
	BView*				mImageView;
	BView*				mColorView;
	BView*				mClockView;
	BView*				mApplyView;
private:
	int					LanguageNumber;
	int32				temp, tempHack;
	char 				charer[1024];
	BString				mStringUser1;
	BString				mStringCurrentPathImages;
	BString				mStringRed;
	BString				mStringGreen;
	BString				mStringBlue;
	BString 			PathToBG;
	BString 			PathToUI;
	BString 			PathToNOUI;
	BString				mStringBoolClock;
	BString				mStringClockCCR;
	BString				mStringClockCCG;
	BString				mStringClockCCB;
	BString				mStringClockPlaceX;
	BString				mStringClockPlaceY;
	BString				mStringClockFontSize;
	BString				mStringLanguage;
	BString				mStringInstallDir;
	BString				mDefaultImagePathText;
	BString mDefaultImagepathTextHack, mDefaultColorRHack, mDefaultColorGHack, mDefaultColorBHack, mDefaultClockColorRHack, mDefaultClockColorGHack, mDefaultClockColorBHack, mDefaultClockPlaceXHack, mDefaultClockPlaceYHack, mDefaultBoolClockHack, mPasswordHack, mPasswordRetypeHack, mPasswordDisableButtonHack;
	BStringItem*		mStringItemUser1;
	BSlider*			mSliderFontSize;
	BListView*			mListOfUsers;
	BTextControl*		mAddUserName;
	BTextControl*		mAddPassWord;
	BTextControl*		mAddPassWordRetype;
	BTextControl*		mTextControlmPathToImageFolder;
	BTextControl*		mTextControlmColorControlR;
	BTextControl*		mTextControlmColorControlG;
	BTextControl*		mTextControlmColorControlB;
	BTextControl*		mTextControlClockColorR;
	BTextControl*		mTextControlClockColorG;
	BTextControl*		mTextControlClockColorB;
	BTextControl*		mTextControlClockPlaceX;
	BTextControl*		mTextControlClockPlaceY;
	BCheckBox*			mCheckBoxBoolClock;
	BMenu*				mMenuLanguage;
	BMenuField*			mMenuFieldLanguage;
	BPopUpMenu*			mPopUpMenuLanguage;
	BMenuItem*			mMenuItem;
	BButton*			mButtonDefaultImagePath;
	BButton*			mButtonBrowseImagePath;
	BButton*			mEraserButtonOfDoom;
	BButton*			mButtonApplyEverything;
	BButton*			mButtonDefaultColors;
	BButton*			mButtonDefaultClockColors;
	BButton*			mButtonDefaultClockPlace;
	BButton*			mButtonChangeLogin;
	BFilePanel*			mFilePanelFolderBrowse;
	BBox*				mBoxAroundAddUserName;
	BBox*				mBoxAroundListUsers;
	BBox*				mBoxAroundImagePath;
	BBox*				mBoxAroundColorControl;
	BBox*				mBoxAroundClockConfig;
	entry_ref 			mEntryRef;
	BPath 				path;
	status_t			status;
	BFile				file;
	BMessage 			savemessage;
	
	//BBitmap*			BitmapBounds;
	//BBitmap*			BitmapBounds2;
	//BBitmap*			BitmapBounds3;
	//Thread
	thread_id			CheckerThread;
	static int32 		CheckerThread_static(void *data);
	void 				Checker_Thread();
	thread_id			EnDButtonsThread;
	static int32 		EnDButtonsThread_static(void *data);
	void 				EnDButtons_Thread();
	thread_id			EnDUserButtonThread;
	static int32 		EnDUserButtonThread_static(void *data);
	void 				EnDUserButton_Thread();
	thread_id			UpdateStringsThread;
	static int32 		UpdateStringsThread_static(void *data);
	void 				UpdateStrings_Thread();
};

#endif