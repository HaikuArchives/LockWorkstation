// mWindow.cpp
//0 = English
//1 = Spanish
//2 = Norwegian
//3 = Swedish
//4 = Portugees
//5 = French
//6 = Deutsch
#include "mWindow.h"
const char* mDefaultPathToBG =				"login_gfx";
const char* mDefaultPathToUI =				"UserImage";
const char* mDefaultPathToNUI =				"NoUserImage";
const char* mDefaultPathToSelBG =			"/login_gfx";
const char* mDefaultPathToSelUI =			"/UserImage";
const char* mDefaultPathToSelNUI =			"/NoUserImage";
const char* mDefaultUsername =				"baron";
const char* mDefaultPassword =				"haikubox";
const char* mDefaultColorR =				"0";
const char* mDefaultColorG =				"0";
const char* mDefaultColorB =				"0";
const char* mPathToConfigFile =				"LockWorkstationSettings";
const char* mNameConfigExecDir =			"execDir";
const char* mNameConfigUser =				"username";
const char* mNameConfigPass =				"password";
const char* mNameConfigImagePath =			"imagePath";
const char* mNameConfigRed =				"red";
const char* mNameConfigGreen =				"green";
const char* mNameConfigBlue =				"blue";
const char* mNameConfigClockFontSize =		"fontSize";
const char* mNameConfigLanguage =			"language";
const char* mBAlertTextSelectedINF[7] =		{/*E*/"Selected image not found, using default\n(may look wrong)", /*S*/"Selected image not found, using default\n(may look wrong)", /*N*/"Fant ikke bildene du hadde spesifisert,\nbruker standardbildene(kan se tsarva ut)", /*S*/"Selected image not found, using default\n(may look wrong)", /*P*/"Selected image not found, using default\n(may look wrong)", /*F*/"Image sélectionnée non trouvée, utilisation de valeur par defaut (peut aparaître dérangée)", /*D*/"Selected image not found, using default\n(may look wrong)"};
const char* mBAlertTextSelectedINFButton[7] ={"Nooooooo!", "Nooooooo!", "Nei!!!!", "Nooooooo!", "Nooooooo!", "Noooonnn!", "Nooooooo!"};
const char* mBAlertTextUserConfigNF[7] =	{/*E*/"Username config file not found!\nPlease run the Preferences application\nUsername set to \"baron\"", /*S*/"Username config file not found!\nPlease run the Preferences application\nUsername set to \"baron\"", /*N*/"Finner ikke brukernavnkonfigurasjonsfila!\nVennligs kjør Preferences programmet\nBrukernavnet satt til \"baron\"", /*S*/"Username config file not found!\nPlease run the Preferences application\nUsername set to \"baron\"", /*p*/"Username config file not found!\nPlease run the Preferences application\nUsername set to    \"baron\"", /*F*/"Fichier de configuration du nom d'usagé non trouvé! Svp allez dans les péférences et utilisé \"baron\" comme nom d'usagé", /*D*/"Username config file not found!\nPlease run the Preferences application\nUsername set to \"baron\""};
const char* mBAlertTextUserConfigNFB[7] =	{"Doh!", "Doh!", "Doh!", "Doh!", "Doh!", "Doh!", "Doh!"};
const char* mBAlertTextUserConfigPNF[7] =	{/*E*/"The default password is <haikubox>. Is strongly recommended to change the default password!", /*S*/"Password config file not found!\nPlease run the Preferences application\nPassword set to <nothing>", /*N*/"Finner ikke passordkonfigurasjonsfila!\nVennligs kjør Preferences programmet\npassordet satt til <ingenting>", /*P*/"Password config file not found!\nPlease run the Preferences application\nPassword set to <nothing>", /*F*/"Fichier de configuration du mot de passe non trouvé! Svp allez dans les péférences et utilisé <rien> comme mot de passe", /*D*/"Password config file not found!\nPlease run the Preferences application\nPassword set to <nothing>"};
const char* mBAlertTextUserConfigPNFB[7] =	{"Ouch", "Ouch", "Doh!", "Ouch", "Ouch", "Aie", "Ouch"};
const char* mNameButtonThemeToggle[7] = 	{"Themes", "Themes", "Themes", "Themes", "Themes", "Thèmes", "Themes"};
const char* mWindowTitle = 					"Lock Workstation";
const char* mStringUnlock[7] = 				{"Unlock", "Unlock", "Lås opp", "Unlock", "Unlock", "Déverrouilé", "Unlock"}; 
const BRect UIRect 							(110, 160, 480, 300);
const BRect mFrameButtonLogin 				(320, 390, 445, 410);
const BRect mFrameTextUser 					(0, 330, 450, 350);
const BRect mFrameTextPass 					(0, 356, 450, 376);
const BRect mFrameTextViewUser 				(120, 330, 170, 350);
const BRect mFrameTextViewPass 				(120, 356, 170, 376);
const BRect mFrameEntireScreen 				(0, 0, 1920, 1200);
const char* mInputUserName;
const char* mInputPassWord;
const char* mDefaultLanguage =				"0";

/**********************************************************/
mWindow::mWindow(const char *mWindowTitle)
			: BWindow(BRect(200, 200, 2000, 2000), mWindowTitle , B_NO_BORDER_WINDOW_LOOK, B_MODAL_ALL_WINDOW_FEEL,
			B_WILL_ACCEPT_FIRST_CLICK | B_FLOATING_SUBSET_WINDOW_FEEL | B_NOT_CLOSABLE | B_NOT_ZOOMABLE | B_NOT_RESIZABLE,
			B_ALL_WORKSPACES)
{
mView = new BView(BRect(0, 0, 2000, 2000), NULL, B_FOLLOW_ALL, B_WILL_DRAW);
	if (mView != NULL)
	{
		BWindow::AddChild(mView);
	}
	else
	{
				be_app->PostMessage(B_QUIT_REQUESTED);
	}
mclockview = new mClockView(BRect(0, 0, 200, 100), "mCLockViewaeasdsad", B_FOLLOW_TOP | B_FOLLOW_LEFT,
								 B_WILL_DRAW | B_PULSE_NEEDED);
AddChild(mclockview);
mWindow::SetPulseRate(5000000);
/******************/
/**** Fileread ****/
/******************/
//shortcut

AddShortcut(B_SPACE, B_COMMAND_KEY | B_CONTROL_KEY,
 		new BMessage(B_QUIT_REQUESTED));

//FILEREAD
find_directory(B_USER_SETTINGS_DIRECTORY, &path);
path.Append(mPathToConfigFile);
status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
//IMAGES
	if (savemessage.HasString(mNameConfigImagePath) == 0)
	{
	savemessage.AddString(mNameConfigImagePath, "/system/apps/LockWorkstation/images/default");
	}
savemessage.FindString(mNameConfigImagePath, &mStringPathToImageFolder);
mStringPathToBG << mStringPathToImageFolder << mDefaultPathToSelBG;
mStringPathToCU << mStringPathToImageFolder << mDefaultPathToSelUI;
mStringPathToNOCU << mStringPathToImageFolder << mDefaultPathToSelNUI;
//BG COLOR
//R
	if (savemessage.HasString(mNameConfigRed) == 0)
	{
	savemessage.AddString(mNameConfigRed, mDefaultColorR);
	}
savemessage.FindString(mNameConfigRed, &mStringR);
//G
	if (savemessage.HasString(mNameConfigGreen) == 0)
	{
	savemessage.AddString(mNameConfigGreen, mDefaultColorG);
	}
savemessage.FindString(mNameConfigGreen, &mStringG);
//B
	if (savemessage.HasString(mNameConfigBlue) == 0)
	{
	savemessage.AddString(mNameConfigBlue, mDefaultColorB);
	}
savemessage.FindString(mNameConfigBlue, &mStringB);
//LANGUAGE
	if (savemessage.HasString(mNameConfigLanguage) == 0)
	{
	savemessage.AddString(mNameConfigLanguage, mDefaultLanguage);
	}
savemessage.FindString(mNameConfigLanguage, &mStringLanguage);
//USER
	if (savemessage.HasString(mNameConfigUser) == 0)
	{
	savemessage.AddString(mNameConfigUser, mDefaultUsername);
	BAlert *mAbout = new BAlert("Usernamenotfound",
		mBAlertTextUserConfigNF[mLanguage], mBAlertTextUserConfigNFB[mLanguage]);
		mAbout->Go();
	}
savemessage.FindString(mNameConfigUser, &mTheRightUserName);

//PASS
	if (savemessage.HasString(mNameConfigPass) == 0)
	{
	savemessage.AddString(mNameConfigPass, mDefaultPassword);
	BAlert *mAbout = new BAlert("Passwordnotfound",
	mBAlertTextUserConfigPNF[mLanguage], mBAlertTextUserConfigNFB[mLanguage]);
	mAbout->Go();
	}
savemessage.FindString(mNameConfigPass, &mTheRightPassword);
if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}

/*******************************************/
/****************** Main code **************/
/*******************************************/
mColorR = atoi(mStringR.String());
mColorG = atoi(mStringG.String());
mColorB = atoi(mStringB.String());
mLanguage = atoi(mStringLanguage.String());

const rgb_color mBack = {mColorR, mColorG, mColorB};
const rgb_color mWhite = {255, 255, 255};
const rgb_color mBlack = {0, 0, 0};
mView->SetViewColor(mBack);

mStringLoginButtonLabelUnlock << mStringUnlock[mLanguage];

mButtonLogin = new BButton(mFrameButtonLogin, mStringUnlock[mLanguage], mStringUnlock[mLanguage], 
				new BMessage(BUTTON_LOGIN));		

mTextUser = new BTextControl(mFrameTextUser, "mInputUserName", "", mInputUserName, new BMessage(LOGIN_CHANGED));
mTextPass = new BTextControl(mFrameTextPass, "mInputPassWord", "", mInputPassWord, new BMessage(LOGIN_CHANGED));
mTextPass->TextView()->HideTyping(true);
mTextUser->SetViewColor(mWhite);
mTextUser->SetLowColor(mWhite);
mTextUser->SetHighColor(mBlack);
mTextPass->SetViewColor(mWhite);
mTextPass->SetLowColor(mWhite);
mTextPass->SetHighColor(mBlack);
mView->SetDrawingMode(B_OP_OVER);
mButtonLogin->SetLabel(mStringLoginButtonLabelUnlock.String());
mTextUser->SetModificationMessage(new BMessage(LOGIN_CHANGED));
mTextPass->SetModificationMessage(new BMessage(LOGIN_CHANGED));
//BITMAP 1
BitmapBounds = BTranslationUtils::GetBitmap(mStringPathToBG.String());
if (!BitmapBounds)
{
BitmapBounds = BTranslationUtils::GetBitmap(mDefaultPathToBG);
if (!BitmapBounds)
	{
	mWindow::QuitRequested();
	be_app->PostMessage(B_QUIT_REQUESTED);
	}
	else 
	{
	BAlert *mAbout = new BAlert("BitmapAlerter",
	mBAlertTextSelectedINF[mLanguage], mBAlertTextSelectedINFButton[mLanguage]);
	mAbout->Go();
	BRect bRect = BitmapBounds->Bounds();
	bRect.Set(0, 0, 1920, 1200);
	mViewBitmap = new BitmapView(BitmapBounds, bRect, "BitmapView");
	mView->AddChild(mViewBitmap);
	}
}
else 
{
BRect bRect = BitmapBounds->Bounds();
bRect.Set(0, 0, 1920, 1200);
mViewBitmap = new BitmapView(BitmapBounds, bRect, "BitmapView");
mView->AddChild(mViewBitmap);
}
/* Are they there? */
UserImageBounds = BTranslationUtils::GetBitmap(mStringPathToCU.String());
	if (!UserImageBounds)
	{
	UserImageBounds = BTranslationUtils::GetBitmap(mDefaultPathToUI);
		if (!UserImageBounds)
		{
		mWindow::QuitRequested();
		be_app->PostMessage(B_QUIT_REQUESTED);
		}
		else
		{
		BAlert *mAbout = new BAlert("BitmapAlerter",
		mBAlertTextSelectedINF[mLanguage], mBAlertTextSelectedINFButton[mLanguage]);
		mAbout->Go();
		}
	}
	else
	{
	}
UserNoImageBounds = BTranslationUtils::GetBitmap(mStringPathToNOCU.String());
	if (!UserNoImageBounds)
	{
	UserNoImageBounds = BTranslationUtils::GetBitmap(mDefaultPathToNUI);
		if (!UserNoImageBounds)
		{
		mWindow::QuitRequested();
		be_app->PostMessage(B_QUIT_REQUESTED);
		}
		else
		{
		BAlert *mAbout = new BAlert("BitmapAlerter",
		mBAlertTextSelectedINF[mLanguage], mBAlertTextSelectedINFButton[mLanguage]);
		mAbout->Go();
		}
	}
	else
	{
	}
delete UserImageBounds;
delete UserNoImageBounds;
/*BITMAP END */
mView->AddChild(mTextUser);
mView->AddChild(mTextPass);
mView->AddChild(mButtonLogin);
mButtonLogin->MakeDefault(true);
MoveTo (0, 0);
BMessenger msgr(this);
be_roster->StartWatching(msgr, B_SOME_APP_ACTIVATED);
mTextUser->SetTarget(this);
mTextUser->MakeFocus(true);
mView->LockLooper();
mButtonLogin->SetEnabled(false);
mView->UnlockLooper();
}

/**********************************************************/
mWindow::~mWindow()
{
}

/**********************************************************/
/* da controllare */
void mWindow::MessageReceived(BMessage *message)
{
	switch(message->what)
	{
	case LOGIN_CHANGED:
	User = mTextUser->Text();
	Pass = mTextPass->Text();
	if (User == mTheRightUserName)
	{
		if(Pass == mTheRightPassword)
		{
		mView->LockLooper();
		mButtonLogin->SetEnabled(true);
		mView->UnlockLooper();
			if (mAvoidFlickering != 2)
			{
			UserThread = spawn_thread(UserThreadChange_static, "Change Image Thread",
										B_NORMAL_PRIORITY, this);
			resume_thread(UserThread);
			mAvoidFlickering = 2;
			}
		}
		else
		{
		mView->LockLooper();
		mButtonLogin->SetEnabled(false);
		mView->UnlockLooper();
			if (mAvoidFlickering != 2)
			{
			UserThread = spawn_thread(UserThreadChange_static, "Change Image Thread",
										B_NORMAL_PRIORITY, this);
			resume_thread(UserThread);
			mAvoidFlickering = 2;
			}
		}
	}
	else
	{
	mView->LockLooper();
	mButtonLogin->SetEnabled(false);
	mView->UnlockLooper();
	if (mAvoidFlickering != 1)
		{
		UserThreadUndo = spawn_thread(UserThreadChange_staticUndo, "Undo Image Thread",
										B_NORMAL_PRIORITY, this);
		resume_thread(UserThreadUndo);
		mAvoidFlickering = 1;
		}
	}
	break;
	case THEME_TOGGLED:
	
	break;
	case BUTTON_LOGIN: 
	User = mTextUser->Text();
	mInputUserName = mTextUser->Text();
	Pass = mTextPass->Text();
	mInputPassWord = mTextPass->Text();
	if (User == mTheRightUserName)
	{
		if (Pass == mTheRightPassword)
		{
			be_app->PostMessage(B_QUIT_REQUESTED);
		}
		else
		{
		
		}
	}
	else
	{
	
	}
	break;
	//Kill the Team manager
	case B_SOME_APP_ACTIVATED:
	{
		/* THIS PIECE OF CODE HAS BEEN "BORROWED" FROM BeLogin, I HAVE NOT TALKED WITH THEM,
		BUT I JUST WANT TO MAKE SURE THAT THEY GET SOME OF THE CREDIT 
		And my program doesnt use it at all BTW :-) */
		BString strSignature;
		message->FindString("be:signature", &strSignature);
		if (strSignature.ICompare ("application/x-vnd.Be-input_server") == 0)
		{
			app_info info;
			be_roster->GetAppInfo (strSignature.String(), &info);
			
			BMessage msgGetProperty, msgSetProperty, msgReply;
			status_t result;
			msgGetProperty.what = B_GET_PROPERTY;
			msgGetProperty.AddSpecifier("Messenger");
			msgGetProperty.AddSpecifier("Window", "Team monitor");
			result = BMessenger(info.signature, info.team).SendMessage(&msgGetProperty, &msgReply);
			
			if (result == B_OK)
			{
				BMessenger msng;
				if (msgReply.FindMessenger("result", &msng) == B_OK)
				{
					//msng.SendMessage(QUIT_TEAM_MONITOR);
					new BMessage(B_QUIT_REQUESTED);
					app_info mwinfo;
					be_app->GetAppInfo(&mwinfo);
					be_roster->ActivateApp(mwinfo.team);
					Activate(true);
				}			
			}		
		}
	break;
	}
	default:
	BWindow::MessageReceived(message);
	break;
	}
}

/**********************************************************/
bool mWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return BWindow::QuitRequested();
}

/**********************************************************/
//Change image to the user image
int32
mWindow::UserThreadChange_static(void *data)
{
	mWindow *changeimage = (mWindow *)data;
	changeimage->UserThreadChangeImage();
	return 0;
}

/**********************************************************/
void mWindow::UserThreadChangeImage()
{
UserImageBounds = BTranslationUtils::GetBitmap(mStringPathToCU.String());
if (!UserImageBounds)
{
UserImageBounds = BTranslationUtils::GetBitmap(mDefaultPathToUI);
}
mViewUserImage = new BitmapView(UserImageBounds, UIRect, "UserImage");
AddChild(mViewUserImage);
}

/**********************************************************/
//And back again
int32
mWindow::UserThreadChange_staticUndo(void *data)
{
	mWindow *changeimageundo = (mWindow *)data;
	changeimageundo->UserThreadChangeImageUndo();
	return 0;
}

/**********************************************************/
void mWindow::UserThreadChangeImageUndo()
{
UserNoImageBounds = BTranslationUtils::GetBitmap(mStringPathToNOCU.String());
if (!UserNoImageBounds)
{
UserNoImageBounds = BTranslationUtils::GetBitmap(mDefaultPathToNUI);
}
mViewUserNoImage = new BitmapView(UserNoImageBounds, UIRect, "NoUserImage");
AddChild(mViewUserNoImage);
}
