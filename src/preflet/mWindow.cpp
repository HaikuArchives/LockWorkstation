/**********************************************************************************/
/*****************        Lock Workstation By Marius Stene        *****************/
/*****************             m_stene@yahoo.com, 2002            *****************/
/*****************        My contribution to this great OS        *****************/
/**********************************************************************************/
/*****************  You are welcome to use any part of this code  *****************/
/*****************      in whole, or in parts freely without      *****************/
/*****************                  contacting me                 *****************/
/**********************************************************************************/
//Global
#include <Application.h>
#include <iostream>
#include <stdio.h>
//Local
#include "mWindow.h"
#include "mApp.h"

using namespace std;

//0 = English
//1 = Spanish
//2 = Norwegian
//3 = Swedish
//4 = Portugees
//5 = French préférences
//6 = Deutsch
//Language stuff							//English			//Spanish			//Norwegian			//Swedish			//Portugees			//French			//Deutsch
const char* mStringLabelUsername[7] =		{"Username", 		"Nombre de Usuario","Brukernavn", 		"Användarnamn", 	"Username", 		"Nom D'utilisateur", "Username"};
const char* mStringLabelPassword[7] =		{"Password", 		"Contraseña", 		"Passord", 			"Lösenord", 		"Password", 		"Mot de Passe", 	"Password"};
const char* mStringLabelChangeLogin[7] = 	{"Change Login", 	"Cambiar nombre del usuario","Skift innloggingsdata", "Ändra login", "Change Login", 	"Change Login", "Change Login"};
const char* mStringLabelCurrentUsers[7] =	{"Current Users", 	"Usuarios Actuales","Bruker", 			"Aktiv användare", 	"Current Users", 	"Utilisateur", "Current Users"};
const char* mStringLabelColors[7] = 		{"Colors",			"Colores", 			"Farger", 			"Färger", 			"Colors", 			"Couleurs", 		"Colors"};
const char* mStringLabelCRed[7] = 			{"Red", 			"Rojo", 			"Rød", 				"Röd", 				"Red", 				"Rouge", 			"Red"};
const char* mStringLabelCGreen[7] = 		{"Green", 			"Verde", 			"Grønn", 			"Grön", 			"Green", 			"Vert", 			"Green"};
const char* mStringLabelCBlue[7] =			{"Blue", 			"Azul", 			"Blå", 				"Blå", 				"Blue", 			"Bleu", 			"Blue"};
const char* mStringLabelApply[7] =			{"Apply", 			"Aplicar", 			"Bruk",				"Bekräfta", 		"Apply", 			"Appliquer", 		"Apply"};
const char*	mStringLabelDefault[7] =		{ "Default", 		"Defecto", 			"Standard", 		"Standard", 		"Default", 			"Defaut", 			"Default"};
const char* mStringLabelChange[7] =			{"Change", 			"cambios", 			"Forandre", 		"Använd", 			"Change", 			"Change", 			"Change"};
const char* mStringLabelBrowse[7] =			{"Browse", 			"Examinar", 		"Se igjennom", 		"Sökväg", 			"Browse", 			"Selectionner un répertoire", 			"Browse"};
const char* mBAlertTextImageNFB[7] =		{"OK", 				"Aceptar", 			"Greit", 			"Okej", 			"Okej", 			"OK", 				"OK"};
const char* mStringLabelShowClock[7] =		{"Show Clock?", 	"Mostrar Reloj?", 	"Vis klokken?", 	"Visa klocka?", 	"Visa klocka?", 	"l'horloge?", "Show Clock?"};
const char* mStringLabelPlaceX[7] =			{"Placement X", 	"Colocación X", 	"Plassering X", 	"Placering X", 		"Placement X", 		"Positionement X", 	"Placement X"};
const char* mStringLabelPlaceY[7] =			{"Placement Y", 	"Colocación Y", 	"Plassering Y", 	"Placering Y", 		"Placement Y", 		"Positionement Y", 	"Placement Y"};
const char* mStringLabelFontSize[7] =		{"Clock Size", 		"Tamaño del Reloj", "Klokkestørrelse", 	"Klock storlek", 	"Klock storlek", 	"Dimention de l'horloge", "Clock Size"};
const char* mStringLabelPasswordRetype[7] =	{"Repeat", "Repeat", "Gjennta", "återtypa", "Repeat", "répéter", "Repeat"};
const char* mStringLanguageLanguage[7] =	{"Language", "Language", "Språk", "Language", "Language", "Langage", "Language"};
const char* mStringSliderMinLimitLabel =	"10";
const char* mStringSliderMaxLimitLabel =	"30";
const char* mStringDefaultUser =			"baron";
const char* mStringLabelPathToImages[7] =	{/*E*/"Path to image folder", 
/*S*/"Ruta al directorio de imágenes", 
/*N*/"Adressen til bildene", 
/*S*/"Sökväg till bildmapp", 
/*P*/"Path to image folder", 
/*F*/"Repertoire d'image", 
/*D*/"Path to image folder"};
const char* mBAlertTextImageNF[7] =			{/*E*/"Images not found, pleace check your settings", 
/*S*/"Images not found, pleace check your settings", 
/*N*/"Fant ikke bildene, vennligst sjekk instillingene", 
/*S*/"Kunde inte hitta filen, kolla dina inställningar", 
/*P*/"Images not found, pleace check your settings", 
/*F*/"Images non touvées, svp vérifier vos règlages", 
/*D*/"Bild nicht gefunden, pleace check your settings"};
const char* mStringClockConfigLabel[7] =	{/*E*/"Clock Configurations", 
/*S*/"Clock Configurations", 
/*N*/"Klokkeinnstillinger", 
/*S*/"Konfigurera klockan", 
/*P*/"Clock Configurations", 
/*F*/"Configurations d'horloge", 
/*D*/"Clock Configurations"};
const char* mBAlertTextLanguageChanged[7] =	{/*E*/"You must restart the application\nfor the changes to take effect", 
/*S*/"You must restart the application\nfor the changes to take effect", 
/*N*/"Du må starte programmet på nytt for\nat instillingene skal ha noen effekt", 
/*S*/"Starta om för att använda de nya inställningarna", 
/*P*/"You must restart the application\nfor the changes to take effect", 
/*F*/"Vous devez redémarrer l'application pour que les changements soits effectif", 
/*D*/"You must restart the application\nfor the changes to take effect"};
//The rest
const char* mStringAboutRequested =		"Lock Workstation Preferences\nVersion 0.99\nBy Marius Stene\nm_stene@yahoo.com\n2002\n\n\"Don't say a word!\"\n\"OK\"";
const char*	mStringNameLanguage0 =		"English";
const char* mStringNameLanguage1 =		"Español";
const char* mStringNameLanguage2 =		"Norsk";
const char* mStringNameLanguage3 =		"Svenska";
const char* mStringNameLanguage4 =		"Portugees";
const char* mStringNameLanguage5 =		"Français";
const char* mStringNameLanguage6 =		"Deutsch";
const char* mStringNameLanguage[7] =	{mStringNameLanguage0, mStringNameLanguage1, mStringNameLanguage2, mStringNameLanguage3, mStringNameLanguage4, mStringNameLanguage5, mStringNameLanguage6};	
const char* mWindowTitle = 				"This doesnt work";
const char* mDefaultBGImageName =		"/login_gfx";
const char* mDefaultUIImageName =		"/UserImage";
const char* mDefaultNOUIImageName =		"/NoUserImage";
const char* mDefaultInstallDir = 		"/boot/apps/Lock_Workstation/";
const char* mDefaultUsername = 			"baron";
const char* mDefaultPassword = 			"haikubox";
const char* mDefaultColorR = 			"0";
const char* mDefaultColorG = 			"0";
const char* mDefaultColorB = 			"0";
const char* mDefaultBoolClock =			"0";
const char* mDefaultClockColorR =		"0";
const char* mDefaultClockColorG =		"0";
const char* mDefaultClockColorB =		"0";
const char* mDefaultClockPlaceX =		"0";
const char* mDefaultClockPlaceY =		"0";
const char* mDefaultClockFontSize =		"8"; //see below
const char* mMinFontValue =				"5"; // this will be *2 on the font view, this just a "fit with hashmarks hack"
const char* mMaxFontValue =				"15";
const char* mHashMarkCountOnSlider =	"11";
const char* mDefaultLanguage =			"0";
const char* mPathToConfigFile =			"LockWorkstationSettings";
const char* mNameConfigExecDir =		"execDir";
const char* mNameConfigUser =			"username";
const char* mNameConfigPass =			"password";
const char* mNameConfigImagePath =		"imagePath";
const char* mNameConfigRed =			"red";
const char* mNameConfigGreen =			"green";
const char* mNameConfigBlue =			"blue";
const char* mNameConfigBoolClock =		"clock";
const char* mNameConfigClockColorR =	"clockR";
const char* mNameConfigClockColorG =	"clockG";
const char* mNameConfigClockColorB =	"clockB";
const char* mNameConfigClockPlaceX =	"clockX";
const char* mNameConfigClockPlaceY =	"clockY";
const char* mNameConfigClockFontSize =	"fontSize";
const char* mNameConfigLanguage =		"language";


const char* url = 						NULL;
const char* email =						NULL;
const rgb_color mBlue = 					{90, 85, 205};
const rgb_color mDefault = 					{219, 219, 219};
const rgb_color mWhite = 					{255, 255, 255};
const rgb_color mBlack = 					{1, 1, 1, 40};
const BRect mFrameListViewUsers 			(10, 20, 90, 120);
const BRect mWindowRect 					(64, 64, 504, 424);
const BRect mFrameBoxAddUserName 			(5, 5, 230, 120);
const BRect mFrameBoxListUsers 				(0, 5, 100, 120);
const BRect mFrameBoxImagePath 				(5, 5, 435, 73);
const BRect mFrameBoxColorControl			(0, 5, 95, 120);
const BRect mFrameTextColorR 				(5, 20, 88, 40);
const BRect mFrameTextColorG 				(5, 45, 88, 65);
const BRect mFrameTextColorB 				(5, 70, 88, 90);
const BRect mFrameTextAddUserName 			(10, 20, 220, 40);
const BRect mFrameTextAddPassWord	 		(10, 45, 220, 65);
const BRect mFrameTextAddPassWordRetype		(10, 70, 220, 90);
const BRect mFrameButtonDefaultImagePath	(350, 45, 430, 67);
const BRect mFrameButtonBrowseImagePath		(265, 45, 345, 67);
const BRect mFrameEraserButtonOfDoom		(265, 10, 345, 30);
const BRect mFrameTextPathImageFolder	 	(10, 20, 428, 40);
const BRect mFrameBoxAoundClockConfig		(5, 0, 435, 120);
const BRect mFrameTextClockColorR			(10, 20, 88, 40);
const BRect mFrameTextClockColorG			(10, 45, 88, 65);
const BRect mFrameTextClockColorB			(10, 70, 88, 90);
const BRect mFrameCheckBoxBoolClock			(122, 70, 202, 85);
const BRect mFrameTextColorPlaceX			(100, 20, 200, 40);
const BRect mFrameTextColorPlaceY			(100, 45, 200, 65);
const BRect mFrameButtonApplyEverything 	(350, 10, 430, 30);
const BRect mFrameButtonDefaultColors		(10, 92, 90, 112);
const BRect mFrameButtonDefaultClockColor	(10, 92, 90, 112);
const BRect mFrameButtonDefaultClockPlace	(122, 92, 202, 112);
const BRect mFrameSliderFontSize			(230, 20, 400, 50);
const BRect mFrameButtonChangeLogin			(140, 92, 220, 112);
const BRect mFrameMenuBarLanguage			(5, 10, 150, 30);

//Constructa
mWindow::mWindow(const char *mWindowTitle)
			: BWindow(BRect(mWindowRect),mWindowTitle ,B_TITLED_WINDOW, B_NOT_RESIZABLE)
{
mView = new BView(BRect(0, 0, 235, 120), "MainView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mView != NULL)
	{BWindow::AddChild(mView);}
mListView = new BView(BRect(236, 0, 340, 120), "ListView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mListView != NULL)
	{BWindow::AddChild(mListView);}
mImageView = new BView(BRect(0, 121, 500, 200), "ImageView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mImageView != NULL)
	{BWindow::AddChild(mImageView);}
mColorView = new BView(BRect(340, 0, 500, 120), "ColorView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mColorView != NULL)
	{BWindow::AddChild(mColorView);}
mClockView = new BView(BRect(0, 201, 500, 321), "ClockView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mClockView != NULL)
	{BWindow::AddChild(mClockView);}
mApplyView = new BView(BRect(0, 322, 500, 360), "ApplyView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE);
	if (mApplyView != NULL)
	{BWindow::AddChild(mApplyView);}
	
mView->SetFont(be_fixed_font);
mView->SetFontSize(12);
mView->SetDrawingMode(B_OP_COPY);
mView->SetLowColor(mWhite);
mView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mView->SetHighColor(mWhite);
mListView->SetFont(be_fixed_font);
mListView->SetFontSize(16);
mListView->SetDrawingMode(B_OP_COPY);
mListView->SetLowColor(mWhite);
mListView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mListView->SetHighColor(mWhite);
mImageView->SetFont(be_fixed_font);
mImageView->SetFontSize(16);
mImageView->SetDrawingMode(B_OP_COPY);
mImageView->SetLowColor(mWhite);
mImageView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mImageView->SetHighColor(mWhite);
mColorView->SetFont(be_fixed_font);
mColorView->SetFontSize(16);
mColorView->SetDrawingMode(B_OP_COPY);
mColorView->SetLowColor(mWhite);
mColorView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mColorView->SetHighColor(mWhite);
mClockView->SetFont(be_fixed_font);
mClockView->SetFontSize(16);
mClockView->SetDrawingMode(B_OP_COPY);
mClockView->SetLowColor(mWhite);
mClockView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mClockView->SetHighColor(mWhite);
mApplyView->SetFont(be_fixed_font);
mApplyView->SetFontSize(16);
mApplyView->SetDrawingMode(B_OP_COPY);
mApplyView->SetLowColor(mWhite);
mApplyView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
mApplyView->SetHighColor(mWhite);
//FILEREAD
find_directory(B_USER_SETTINGS_DIRECTORY, &path);
path.Append(mPathToConfigFile);
status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
//Execdir
	if (savemessage.HasString(mNameConfigExecDir) == 0)
	{
	savemessage.AddString(mNameConfigExecDir, mDefaultInstallDir);
	}
savemessage.FindString(mNameConfigExecDir, &mDefaultImagePathText);
mDefaultImagePathText << "images/default";
//ImagePath
	if (savemessage.HasString(mNameConfigImagePath) == 0)
	{
	savemessage.AddString(mNameConfigImagePath, mDefaultImagePathText.String());
	}
savemessage.FindString(mNameConfigImagePath, &mStringCurrentPathImages);
//Red
	if (savemessage.HasString(mNameConfigRed) == 0)
	{
	savemessage.AddString(mNameConfigRed, mDefaultColorR);
	
	}
savemessage.FindString(mNameConfigRed, &mStringRed);
//Green
	if (savemessage.HasString(mNameConfigGreen) == 0)
	{
	savemessage.AddString(mNameConfigGreen, mDefaultColorG);
	}
savemessage.FindString(mNameConfigGreen, &mStringGreen);
//Blue
	if (savemessage.HasString(mNameConfigBlue) == 0)
	{
	savemessage.AddString(mNameConfigBlue, mDefaultColorB);
	}
savemessage.FindString(mNameConfigBlue, &mStringBlue);
//Clock
//Clock On/Off?
	if (savemessage.HasString(mNameConfigBoolClock) == 0)
	{
	savemessage.AddString(mNameConfigBoolClock, mDefaultBoolClock);
	}
savemessage.FindString(mNameConfigBoolClock, &mStringBoolClock);
//ClockColor
//Red
	if (savemessage.HasString(mNameConfigClockColorR) == 0)
	{
	savemessage.AddString(mNameConfigClockColorR, mDefaultClockColorR);
	}
savemessage.FindString(mNameConfigClockColorR, &mStringClockCCR);
//Green
	if (savemessage.HasString(mNameConfigClockColorG) == 0)
	{
	savemessage.AddString(mNameConfigClockColorG, mDefaultClockColorG);
	}
savemessage.FindString(mNameConfigClockColorG, &mStringClockCCG);
//Blue
	if (savemessage.HasString(mNameConfigClockColorB) == 0)
	{
	savemessage.AddString(mNameConfigClockColorB, mDefaultClockColorB);
	}
savemessage.FindString(mNameConfigClockColorB, &mStringClockCCB);
//ClockPlacement
//Place X
	if (savemessage.HasString(mNameConfigClockPlaceX) == 0)
	{
	savemessage.AddString(mNameConfigClockPlaceX, mDefaultClockPlaceX);
	}
savemessage.FindString(mNameConfigClockPlaceX, &mStringClockPlaceX);
//Place Y
	if (savemessage.HasString(mNameConfigClockPlaceY) == 0)
	{
	savemessage.AddString(mNameConfigClockPlaceY, mDefaultClockPlaceY);
	}
savemessage.FindString(mNameConfigClockPlaceY, &mStringClockPlaceY);
//Fontsize
	if (savemessage.HasString(mNameConfigClockFontSize) == 0)
	{
	savemessage.AddString(mNameConfigClockFontSize, mDefaultClockFontSize);
	}
savemessage.FindString(mNameConfigClockFontSize, &mStringClockFontSize);
//Language
	if (savemessage.HasString(mNameConfigLanguage) == 0)
	{
	savemessage.AddString(mNameConfigLanguage, mDefaultLanguage);
	}
savemessage.FindString(mNameConfigLanguage, &mStringLanguage);

if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}
LanguageNumber = atoi(mStringLanguage.String());
switch(LanguageNumber){
case 0:	mStringLanguage.SetTo(mStringNameLanguage0);	break;
case 1:	mStringLanguage.SetTo(mStringNameLanguage1);	break;
case 2:	mStringLanguage.SetTo(mStringNameLanguage2);	break;
case 3:	mStringLanguage.SetTo(mStringNameLanguage3);	break;
case 4:	mStringLanguage.SetTo(mStringNameLanguage4);	break;
case 5:	mStringLanguage.SetTo(mStringNameLanguage5);	break;
case 6:	mStringLanguage.SetTo(mStringNameLanguage6);	break;
}
/***********************************************************************************************************************/
//AddUser
mBoxAroundAddUserName = new BBox(mFrameBoxAddUserName, "Add User",
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE_JUMP, B_FANCY_BORDER);
mAddUserName = new BTextControl(mFrameTextAddUserName, "TextAddUser", mStringLabelUsername[LanguageNumber], mStringDefaultUser, new BMessage(TEXTADDUSER),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mAddPassWord = new BTextControl(mFrameTextAddPassWord, "TextPassWord", mStringLabelPassword[LanguageNumber], "", new BMessage(TEXTADDPASS),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mAddPassWordRetype = new BTextControl(mFrameTextAddPassWordRetype, "TextPassWord", mStringLabelPasswordRetype[LanguageNumber], "", new BMessage(TEXTADDPASS),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mButtonChangeLogin = new BButton(mFrameButtonChangeLogin, "LoginChange", mStringLabelChange[LanguageNumber], new BMessage(CHANGE_LOGIN),
							B_FOLLOW_LEFT | B_FOLLOW_TOP);
mBoxAroundAddUserName->SetLabel(mStringLabelChangeLogin[LanguageNumber]);
mAddPassWord->TextView()->HideTyping(true);
mAddPassWordRetype->TextView()->HideTyping(true);
mAddUserName->SetDivider(80);
mAddPassWord->SetDivider(80);
mAddPassWordRetype->SetDivider(80);
mAddUserName->SetModificationMessage(new BMessage(CHECK_USERBUTTON));
mAddPassWord->SetModificationMessage(new BMessage(CHECK_USERBUTTON));
mAddPassWordRetype->SetModificationMessage(new BMessage(CHECK_USERBUTTON));
//mView->LockLooper();
mButtonChangeLogin->SetEnabled(false);
//mView->UnlockLooper();

//UserList
mBoxAroundListUsers = new BBox(mFrameBoxListUsers, "Add User",
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE_JUMP, B_FANCY_BORDER);
mListOfUsers = new BListView(mFrameListViewUsers, "UserList", B_SINGLE_SELECTION_LIST,
							B_FOLLOW_LEFT | B_FOLLOW_TOP);
mBoxAroundListUsers->SetLabel(mStringLabelCurrentUsers[LanguageNumber]);

//Colorcontrol
mBoxAroundColorControl = new BBox(mFrameBoxColorControl, "Colors",
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlmColorControlR = new BTextControl(mFrameTextColorR, "ColorControlR", mStringLabelCRed[LanguageNumber], mStringRed.String(), new BMessage(COLOR_CHANGED_R),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlmColorControlG = new BTextControl(mFrameTextColorG, "ColorControlG", mStringLabelCGreen[LanguageNumber], mStringGreen.String(), new BMessage(COLOR_CHANGED_G),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlmColorControlB = new BTextControl(mFrameTextColorB, "ColorControlB", mStringLabelCBlue[LanguageNumber], mStringBlue.String(), new BMessage(COLOR_CHANGED_B),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mButtonDefaultColors = new BButton(mFrameButtonDefaultColors, "DefaultColors", mStringLabelDefault[LanguageNumber], new BMessage(DEFAULT_COLORS),
							B_FOLLOW_LEFT | B_FOLLOW_TOP);
mBoxAroundColorControl->SetLabel(mStringLabelColors[LanguageNumber]);
mTextControlmColorControlR->SetDivider(50);
mTextControlmColorControlG->SetDivider(50);
mTextControlmColorControlB->SetDivider(50);
mTextControlmColorControlR->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlmColorControlG->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlmColorControlB->SetModificationMessage(new BMessage(CHECK_BUTTONS));
	
//LanguageBar
mMenuLanguage = new BMenu(mStringNameLanguage[LanguageNumber], B_ITEMS_IN_COLUMN);
mMenuFieldLanguage = new BMenuField(mFrameMenuBarLanguage, "mMenuBare", mStringLanguageLanguage[LanguageNumber], mMenuLanguage);
mMenuItem = new BMenuItem(mStringNameLanguage0, new BMessage(LANG_0));
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 0) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage1, new BMessage(LANG_0));/*LANG_1*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 1) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage2, new BMessage(LANG_0));/*LANG_2*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 2) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage3, new BMessage(LANG_0));/*LANG_3*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 3) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage4, new BMessage(LANG_0));/*LANG_4*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 4) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage5, new BMessage(LANG_0));/*LANG_5*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 5) { mMenuItem->SetMarked(true); }
mMenuItem = new BMenuItem(mStringNameLanguage6, new BMessage(LANG_0));/*LANG_6*/
mMenuLanguage->AddItem(mMenuItem);
if (LanguageNumber == 6) { mMenuItem->SetMarked(true); }
mMenuFieldLanguage->SetDivider(60);
mMenuLanguage->SetLabelFromMarked(true); 
		
//ClockConfig	
int mMinFontValueint, mMaxFontValueint;
mMinFontValueint = atoi(mMinFontValue);
mMaxFontValueint = atoi(mMaxFontValue);
mBoxAroundClockConfig = new BBox(mFrameBoxAoundClockConfig, "Clock Config", 
							B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE_JUMP, B_FANCY_BORDER);
mTextControlClockColorR = new BTextControl(mFrameTextClockColorR, "ClockColorControlR", mStringLabelCRed[LanguageNumber], mStringClockCCR.String(), new BMessage(CLOCKCOLOR_CHANGED_R),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlClockColorG = new BTextControl(mFrameTextClockColorG, "ClockColorControlG", mStringLabelCGreen[LanguageNumber], mStringClockCCG.String(), new BMessage(CLOCKCOLOR_CHANGED_G),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlClockColorB = new BTextControl(mFrameTextClockColorB, "ClockColorControlB", mStringLabelCBlue[LanguageNumber], mStringClockCCB.String(), new BMessage(CLOCKCOLOR_CHANGED_B),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);	
mCheckBoxBoolClock = new BCheckBox(mFrameCheckBoxBoolClock, "Bool clock", mStringLabelShowClock[LanguageNumber], new BMessage(BOOL_CLOCK),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);	
mTextControlClockPlaceX = new BTextControl(mFrameTextColorPlaceX, "ClockPlacementX", mStringLabelPlaceX[LanguageNumber], mStringClockPlaceX.String(), new BMessage(CLOCKPLACEMENT_X),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mTextControlClockPlaceY = new BTextControl(mFrameTextColorPlaceY, "ClockPlacementY", mStringLabelPlaceY[LanguageNumber], mStringClockPlaceY.String(), new BMessage(CLOCKPLACEMENT_Y),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mButtonDefaultClockColors = new BButton(mFrameButtonDefaultClockColor, "DefaultClockColors", mStringLabelDefault[LanguageNumber], new BMessage(DEFAULT_CLOCK_COLORS),
							B_FOLLOW_LEFT | B_FOLLOW_TOP);
mButtonDefaultClockPlace = new BButton(mFrameButtonDefaultClockPlace, "DefaultPlace", mStringLabelDefault[LanguageNumber], new BMessage(DEFAULT_PLACE),
							B_FOLLOW_LEFT | B_FOLLOW_TOP);
mSliderFontSize = new BSlider(mFrameSliderFontSize, "FontSizeSlider", mStringLabelFontSize[LanguageNumber], new BMessage(SIZE_SLIDER_CHANGED),
							 mMinFontValueint, mMaxFontValueint, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP, B_FRAME_EVENTS | B_WILL_DRAW | B_NAVIGABLE); 
int value, HashMarksCount, CurrentSliderValue;
value = atoi(mStringBoolClock.String());
HashMarksCount = atoi(mHashMarkCountOnSlider);
CurrentSliderValue = atoi(mStringClockFontSize.String());
mCheckBoxBoolClock->SetValue(value);	
mTextControlClockPlaceX->SetDivider(67);	
mTextControlClockPlaceY->SetDivider(67);				 				
mTextControlClockColorR->SetDivider(45);
mTextControlClockColorG->SetDivider(45);
mTextControlClockColorB->SetDivider(45);							
mBoxAroundClockConfig->SetLabel(mStringClockConfigLabel[LanguageNumber]);
mSliderFontSize->SetHashMarks(B_HASH_MARKS_BOTH);
mSliderFontSize->SetHashMarkCount(HashMarksCount);
mSliderFontSize->SetLimitLabels(mStringSliderMinLimitLabel, mStringSliderMaxLimitLabel);
mSliderFontSize->SetKeyIncrementValue(2);
mSliderFontSize->SetValue(CurrentSliderValue);
mTextControlClockColorR->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlClockColorG->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlClockColorB->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlClockPlaceX->SetModificationMessage(new BMessage(CHECK_BUTTONS));
mTextControlClockPlaceY->SetModificationMessage(new BMessage(CHECK_BUTTONS));
		
//ImagePath
BEntry("boot/apps/Lock Workstation").GetRef(&mEntryRef);
mTextControlmPathToImageFolder = new BTextControl(mFrameTextPathImageFolder, "TextPathToImages", mStringLabelPathToImages[LanguageNumber], mStringCurrentPathImages.String(), new BMessage(TEXT_IMAGEPATH),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP);
mButtonDefaultImagePath = new BButton(mFrameButtonDefaultImagePath, "mFrameButtonDefaultImagePath", mStringLabelDefault[LanguageNumber], new BMessage(BUTTON_DEFAULTPATH),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
mButtonBrowseImagePath = new BButton(mFrameButtonBrowseImagePath, "mFrameButtonBrowseImagePath", mStringLabelBrowse[LanguageNumber], new BMessage(BROWSE_FOLDER),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
mBoxAroundImagePath = new BBox(mFrameBoxImagePath, "ImagePathBox",
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE_JUMP, B_FANCY_BORDER);	
mFilePanelFolderBrowse = new BFilePanel(B_OPEN_PANEL, NULL, &mEntryRef, B_DIRECTORY_NODE, false, new BMessage(FOLDER_CHANGED), NULL, true, true);
mBoxAroundImagePath->SetLabel(mStringLabelPathToImages[LanguageNumber]);
mTextControlmPathToImageFolder->SetDivider(120);
mTextControlmPathToImageFolder->SetModificationMessage(new BMessage(CHECK_BUTTONS));

//I te yo evythin
mButtonApplyEverything = new BButton(mFrameButtonApplyEverything, "mFrameButtonApplyEverything", mStringLabelApply[LanguageNumber], new BMessage(APPLY_EVERYTHING),
							 B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
mEraserButtonOfDoom = new BButton(mFrameEraserButtonOfDoom, "EraserButtonOfDoom", mStringLabelDefault[LanguageNumber], new BMessage(ERASER_FROM_DOOM),
							B_FOLLOW_LEFT | B_FOLLOW_TOP);

//User
find_directory(B_USER_SETTINGS_DIRECTORY, &path);
path.Append(mPathToConfigFile);
status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
	if (savemessage.HasString(mNameConfigUser) == 0)
	{
	savemessage.AddString(mNameConfigUser, mDefaultUsername);
	}
savemessage.FindString(mNameConfigUser, &mStringUser1);
if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}
mStringItemUser1 = new BStringItem(mStringUser1.String(), 0);
mListOfUsers->AddItem(mStringItemUser1);
		
mView->AddChild(mAddUserName);
mView->AddChild(mAddPassWord);
mView->AddChild(mAddPassWordRetype);
mView->AddChild(mButtonChangeLogin);
mView->AddChild(mBoxAroundAddUserName);
mListView->AddChild(mListOfUsers);
mListView->AddChild(mBoxAroundListUsers);
mImageView->AddChild(mTextControlmPathToImageFolder);
mImageView->AddChild(mButtonDefaultImagePath);
/*mImageView->AddChild(mButtonBrowseImagePath); Not working */
mImageView->AddChild(mBoxAroundImagePath);
mColorView->AddChild(mTextControlmColorControlR);
mColorView->AddChild(mTextControlmColorControlG);
mColorView->AddChild(mTextControlmColorControlB);
mColorView->AddChild(mButtonDefaultColors);
mColorView->AddChild(mBoxAroundColorControl);
mClockView->AddChild(mTextControlClockColorR);
mClockView->AddChild(mTextControlClockColorG);
mClockView->AddChild(mTextControlClockColorB);
mClockView->AddChild(mTextControlClockPlaceX);
mClockView->AddChild(mTextControlClockPlaceY);
mClockView->AddChild(mSliderFontSize);
mClockView->AddChild(mCheckBoxBoolClock);
mClockView->AddChild(mButtonDefaultClockColors);
mClockView->AddChild(mButtonDefaultClockPlace);
mClockView->AddChild(mBoxAroundClockConfig);
mApplyView->AddChild(mEraserButtonOfDoom);
mApplyView->AddChild(mButtonApplyEverything);
mApplyView->AddChild(mMenuFieldLanguage);
BMessenger msgr(this);
be_roster->StartWatching(msgr, B_SOME_APP_ACTIVATED);
AddShortcut('A', B_COMMAND_KEY, new BMessage(B_ABOUT_REQUESTED));
AddShortcut('S', B_COMMAND_KEY, new BMessage(APPLY_EVERYTHING));
AddShortcut('D', B_COMMAND_KEY, new BMessage(ERASER_FROM_DOOM));
//Enable and disable buttons
EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
									B_LOW_PRIORITY, this);
resume_thread(EnDButtonsThread);
}

/**************************************************************/
mWindow::~mWindow()
{
}

/**************************************************************/
/**************** BMessages ***********************************/
/**************************************************************/
void mWindow::MessageReceived(BMessage *message)
{
	switch(message->what)
	{
	case BUTTON_DEFAULTPATH:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
	mTextControlmPathToImageFolder->SetText(mDefaultImagePathText.String());
	savemessage.ReplaceString(mNameConfigImagePath, mTextControlmPathToImageFolder->Text());
	if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}
	//Check if there are any images there!
	CheckerThread = spawn_thread(CheckerThread_static, "Check if images are there thread",
										B_LOW_PRIORITY, this);
	resume_thread(CheckerThread);
	//Update Strings
	UpdateStringsThread = spawn_thread(UpdateStringsThread_static, "Update Strings",
									B_NORMAL_PRIORITY, this);
	resume_thread(UpdateStringsThread);
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	/*****************************************************************************/
	/******************************** DIE!!! *************************************/
	/*****************************************************************************/
	case ERASER_FROM_DOOM:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mTextControlmPathToImageFolder->SetText(mDefaultImagePathText.String());
	mTextControlmColorControlR->SetText(mDefaultColorR);
	mTextControlmColorControlG->SetText(mDefaultColorG);
	mTextControlmColorControlB->SetText(mDefaultColorB);
	mTextControlClockColorR->SetText(mDefaultClockColorR);
	mTextControlClockColorG->SetText(mDefaultClockColorG);
	mTextControlClockColorB->SetText(mDefaultClockColorB);
	mTextControlClockPlaceX->SetText(mDefaultClockPlaceX);
	mTextControlClockPlaceY->SetText(mDefaultClockPlaceY);
	savemessage.ReplaceString(mNameConfigImagePath, mTextControlmPathToImageFolder->Text());
	savemessage.ReplaceString(mNameConfigRed, mTextControlmColorControlR->Text());
	savemessage.ReplaceString(mNameConfigGreen, mTextControlmColorControlG->Text());
	savemessage.ReplaceString(mNameConfigBlue, mTextControlmColorControlB->Text());
	savemessage.ReplaceString(mNameConfigClockColorR, mTextControlClockColorR->Text());
	savemessage.ReplaceString(mNameConfigClockColorG, mTextControlClockColorG->Text());
	savemessage.ReplaceString(mNameConfigClockColorB, mTextControlClockColorB->Text());
	savemessage.ReplaceString(mNameConfigClockPlaceX, mTextControlClockPlaceX->Text());	
	savemessage.ReplaceString(mNameConfigClockPlaceY, mTextControlClockPlaceY->Text());	
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Check if images are there
	CheckerThread = spawn_thread(CheckerThread_static, "Check if images are there thread",
										B_LOW_PRIORITY, this);
	resume_thread(CheckerThread);
	/*buttons*/
	mApplyView->LockLooper();
	mButtonApplyEverything->SetEnabled(false);
	mEraserButtonOfDoom->SetEnabled(false);
	mApplyView->UnlockLooper();
	//Bool clock
	mCheckBoxBoolClock->SetValue(atoi(mDefaultBoolClock));
	//slider
	mStringClockFontSize.SetTo("");
	mStringClockFontSize << mSliderFontSize->Value();
	//Update Strings
	UpdateStringsThread = spawn_thread(UpdateStringsThread_static, "Update Strings",
									B_NORMAL_PRIORITY, this);
	resume_thread(UpdateStringsThread);
	break;
	/********************************************************************/
	/************************** LIVE! ***********************************/
	/********************************************************************/
	case APPLY_EVERYTHING:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigImagePath, mTextControlmPathToImageFolder->Text());
	//Check if there are any images there!
	CheckerThread = spawn_thread(CheckerThread_static, "Check if images are there thread",
										B_NORMAL_PRIORITY, this);
	resume_thread(CheckerThread);
		if (mCheckBoxBoolClock->Value() == 0)
		{
		savemessage.ReplaceString(mNameConfigBoolClock, "0");	
		}	else	{
		savemessage.ReplaceString(mNameConfigBoolClock, "1");	
		}
	savemessage.ReplaceString(mNameConfigImagePath, mTextControlmPathToImageFolder->Text());
	savemessage.ReplaceString(mNameConfigRed, mTextControlmColorControlR->Text());
	savemessage.ReplaceString(mNameConfigGreen, mTextControlmColorControlG->Text());
	savemessage.ReplaceString(mNameConfigBlue, mTextControlmColorControlB->Text());
	savemessage.ReplaceString(mNameConfigClockColorR, mTextControlClockColorR->Text());
	savemessage.ReplaceString(mNameConfigClockColorG, mTextControlClockColorG->Text());
	savemessage.ReplaceString(mNameConfigClockColorB, mTextControlClockColorB->Text());
	savemessage.ReplaceString(mNameConfigClockPlaceX, mTextControlClockPlaceX->Text());	
	savemessage.ReplaceString(mNameConfigClockPlaceY, mTextControlClockPlaceY->Text());	
	mStringClockFontSize.SetTo("");
	mStringClockFontSize << mSliderFontSize->Value();
	savemessage.ReplaceString(mNameConfigClockFontSize, mStringClockFontSize.String());
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
		else
		//Here both for debugging and because for some ************* reason my app doesnt work without the cout lines:-D
		cout << "Before" << endl;
		cout << mStringCurrentPathImages.String() << std::endl;
		cout << "-------------------------" << std::endl;
		cout << mTextControlmPathToImageFolder->Text() << std::endl;
	mStringCurrentPathImages.SetTo(mTextControlmPathToImageFolder->Text());
		cout << "After" << endl;
		cout << mStringCurrentPathImages.String() << std::endl;
		cout << "-------------------------" << std::endl;
		cout << mTextControlmPathToImageFolder->Text() << std::endl;
	mStringRed.SetTo(mTextControlmColorControlR->Text());
	mStringGreen.SetTo(mTextControlmColorControlG->Text());
	mStringBlue.SetTo(mTextControlmColorControlB->Text());
	mStringClockCCR.SetTo(mTextControlClockColorR->Text());
	mStringClockCCG.SetTo(mTextControlClockColorG->Text());
	mStringClockCCB.SetTo(mTextControlClockColorB->Text());
	mStringClockPlaceX.SetTo(mTextControlClockPlaceX->Text());
	mStringClockPlaceY.SetTo(mTextControlClockPlaceY->Text());
	temp = mCheckBoxBoolClock->Value();
	mStringBoolClock.SetTo("");
	mStringBoolClock << temp;
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case BOOL_CLOCK:
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case DEFAULT_COLORS:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mTextControlmColorControlR->SetText(mDefaultColorR);
	mTextControlmColorControlG->SetText(mDefaultColorG);
	mTextControlmColorControlB->SetText(mDefaultColorB);
	savemessage.ReplaceString(mNameConfigRed, mTextControlmColorControlR->Text());
	savemessage.ReplaceString(mNameConfigGreen, mTextControlmColorControlG->Text());
	savemessage.ReplaceString(mNameConfigBlue, mTextControlmColorControlB->Text());
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Update Strings
	UpdateStringsThread = spawn_thread(UpdateStringsThread_static, "Update Strings",
									B_NORMAL_PRIORITY, this);
	resume_thread(UpdateStringsThread);
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case DEFAULT_CLOCK_COLORS:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mTextControlClockColorR->SetText(mDefaultClockColorR);
	mTextControlClockColorG->SetText(mDefaultClockColorG);
	mTextControlClockColorB->SetText(mDefaultClockColorB);
	savemessage.ReplaceString(mNameConfigClockColorR, mTextControlClockColorR->Text());
	savemessage.ReplaceString(mNameConfigClockColorG, mTextControlClockColorG->Text());
	savemessage.ReplaceString(mNameConfigClockColorB, mTextControlClockColorB->Text());
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Update Strings
	UpdateStringsThread = spawn_thread(UpdateStringsThread_static, "Update Strings",
									B_NORMAL_PRIORITY, this);
	resume_thread(UpdateStringsThread);
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case DEFAULT_PLACE:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mTextControlClockPlaceX->SetText(mDefaultClockPlaceX);
	mTextControlClockPlaceY->SetText(mDefaultClockPlaceY);
	savemessage.ReplaceString(mNameConfigClockPlaceX, mTextControlClockPlaceX->Text());	
	savemessage.ReplaceString(mNameConfigClockPlaceY, mTextControlClockPlaceY->Text());	
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Bool clock
	mCheckBoxBoolClock->SetValue(atoi(mDefaultBoolClock));
	//Update Strings
	UpdateStringsThread = spawn_thread(UpdateStringsThread_static, "Update Strings",
									B_NORMAL_PRIORITY, this);
	resume_thread(UpdateStringsThread);
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case SIZE_SLIDER_CHANGED:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mStringClockFontSize.SetTo("");
	mStringClockFontSize << mSliderFontSize->Value();
	savemessage.ReplaceString(mNameConfigClockFontSize, mStringClockFontSize.String());
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
		else
	break;
	case CHANGE_LOGIN:
	//AddUser
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigUser, mAddUserName->Text());
	
		if (savemessage.HasString(mNameConfigPass) == 0)
		{
		savemessage.AddString(mNameConfigPass, mAddPassWord->Text());
		}
		else
		{
		savemessage.ReplaceString(mNameConfigPass, mAddPassWord->Text());
		}
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	mView->LockLooper();
	mButtonChangeLogin->SetEnabled(false);
	mView->UnlockLooper();
	break;
	case BROWSE_FOLDER:
	{
	mFilePanelFolderBrowse->Show();
	}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case FOLDER_CHANGED:
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	mFilePanelFolderBrowse->GetPanelDirectory(&mEntryRef);
	path.SetTo(&mEntryRef);
	savemessage.ReplaceString(mNameConfigImagePath, path.Path());
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	CheckerThread = spawn_thread(CheckerThread_static, "Check if images are there thread",
									B_NORMAL_PRIORITY, this);
	resume_thread(CheckerThread);
	break;
	case LANG_0:
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	"I am sorry, but until i can get some decent translations, language support has been disabled", "Ouch");
	mAbout->Go();
	/*
	if (LanguageNumber == 0)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[0], mBAlertTextImageNFB[0]);
	mAbout->Go();
	}
	
//	mTextControlClockPlaceX->SetLabel(mStringLabelPlaceX[LanguageNumber]);
//	mTextControlClockPlaceY->SetLabel(mStringLabelPlaceY[LanguageNumber]);
//	mTextControlClockColorR->SetLabel(mStringCRed[LanguageNumber]);
//	mTextControlClockColorG->SetLabel(mStringCGreen[LanguageNumber]);
//	mTextControlClockColorB->SetLabel(mStringCBlue[LanguageNumber]);
//	mTextControlmColorControlR->SetLabel(mStringCRed[LanguageNumber]);
//	mTextControlmColorControlG->SetLabel(mStringCGreen[LanguageNumber]);
//	mTextControlmColorControlB->SetLabel(mStringCBlue[LanguageNumber]);
//	mButtonChangeLogin->SetLabel(mStringChange[LanguageNumber]);
//	mButtonDefaultClockPlace->SetLabel(mStringDefault[LanguageNumber]);
//	mButtonDefaultClockColors->SetLabel(mStringDefault[LanguageNumber]);
//	mButtonDefaultColors->SetLabel(mStringDefault[LanguageNumber]);
//	mButtonApplyEverything->SetLabel(mStringApply[LanguageNumber]);
//	mButtonBrowseImagePath->SetLabel(mStringBrowse[LanguageNumber]);
//	mButtonDefaultImagePath->SetLabel(mStringDefault[LanguageNumber]);
//	mTextControlmPathToImageFolder->SetLabel(mStringPathToImages[LanguageNumber]);
	
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "0");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	*/
	break;
	}
	case LANG_1:
	if (LanguageNumber == 1)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[1], mBAlertTextImageNFB[1]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "1");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case LANG_2:	
	if (LanguageNumber == 2)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[2], mBAlertTextImageNFB[2]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "2");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case LANG_3:	
	if (LanguageNumber == 3)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[3], mBAlertTextImageNFB[3]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "3");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case LANG_4:
	if (LanguageNumber == 4)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[4], mBAlertTextImageNFB[4]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "4");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case LANG_5:
	if (LanguageNumber == 5)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[5], mBAlertTextImageNFB[5]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "5");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case LANG_6:	
	if (LanguageNumber == 6)
	{
	}
	else
	{
	BAlert *mAbout = new BAlert("Language BAlert",
	mBAlertTextLanguageChanged[6], mBAlertTextImageNFB[6]);
	mAbout->Go();
	}
	find_directory(B_USER_SETTINGS_DIRECTORY, &path);
	path.Append(mPathToConfigFile);
	status = file.SetTo(path.Path(), B_READ_ONLY);
		if (status == B_OK) 
		{
		status = savemessage.Unflatten(&file);
		}
	savemessage.ReplaceString(mNameConfigLanguage, "6");
		if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
		{
		savemessage.Flatten(&file);
		}
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case CHECK_BUTTONS:
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	case CHECK_USERBUTTON:
	EnDUserButtonThread = spawn_thread(EnDUserButtonThread_static, "Enable and disable user button",
										B_LOW_PRIORITY, this);
	resume_thread(EnDUserButtonThread);
	break;
	case B_ABOUT_REQUESTED:
	{
		switch((new BAlert("Language BAlert",
		mStringAboutRequested, "E-Mail", "BeBits Page", "OK"))->Go())
		{
		case 0: 
		email = "m_stene@yahoo.com";
		url = NULL;
		break;
		case 1:
		url = "http://www.bebits.com/app/2824/";
		email = NULL;
		break;
		default:
		url = NULL;
		email = NULL;
		break;
		}
	if (email) be_roster->Launch("text/x-email", 1, (char**) &email);
	if (url) be_roster->Launch("text/html", 1, (char**) &url);
	break;
	}
	default:
	//Enable and disable buttons
	EnDButtonsThread = spawn_thread(EnDButtonsThread_static, "Enable and disable buttons",
										B_LOW_PRIORITY, this);
	resume_thread(EnDButtonsThread);
	break;
	}
}
/**********************************************************************************************************************/
/****Change image to the user image**********/
int32
mWindow::CheckerThread_static(void *data)
{
	mWindow *changeimage = (mWindow *)data;
	changeimage->Checker_Thread();
	return 0;
}

/**********************************************/
void mWindow::Checker_Thread()
{
	//bg
	PathToBG.SetTo("");
	PathToBG << mTextControlmPathToImageFolder->Text() << mDefaultBGImageName;
	BBitmap* BitmapBounds = BTranslationUtils::GetBitmap(PathToBG.String());
	if (!BitmapBounds)
		{
		BAlert *mAbout = new BAlert("Usernamenotfound",
		mBAlertTextImageNF[LanguageNumber], mBAlertTextImageNFB[LanguageNumber]);
		mAbout->Go();
		}
		else
		{
		delete BitmapBounds;
		//cu
		PathToUI.SetTo("");
		PathToUI << mTextControlmPathToImageFolder->Text() << mDefaultUIImageName;
		BBitmap* BitmapBounds2 = BTranslationUtils::GetBitmap(PathToUI.String());
			if (!BitmapBounds2)
			{
			BAlert *mAbout = new BAlert("Usernamenotfound",
			mBAlertTextImageNF[LanguageNumber], mBAlertTextImageNFB[LanguageNumber]);
			mAbout->Go();
			}
			else 
			{
			delete BitmapBounds2;
			//nocu
			PathToNOUI.SetTo("");
			PathToNOUI << mTextControlmPathToImageFolder->Text() << mDefaultNOUIImageName;
			BBitmap* BitmapBounds3 = BTranslationUtils::GetBitmap(PathToNOUI.String());
				if (!BitmapBounds3)
				{
				BAlert *mAbout = new BAlert("Usernamenotfound",
				mBAlertTextImageNF[LanguageNumber], mBAlertTextImageNFB[LanguageNumber]);
				mAbout->Go();
				}
				else
				{
				delete BitmapBounds3;
				}
			}
		}

}

/*******Enable and Disable Buttons**************/
int32
mWindow::EnDButtonsThread_static(void *data)
{
	mWindow *enabuttons = (mWindow *)data;
	enabuttons->EnDButtons_Thread();
	return 0;
}

/*************************************************/
void mWindow::EnDButtons_Thread()
{
snooze(10000);
/*These are for the default thing, not for the apply thing*/
mDefaultImagepathTextHack.SetTo(mDefaultImagePathText.String());
mDefaultColorRHack.SetTo(mDefaultColorR);
mDefaultColorGHack.SetTo(mDefaultColorG);
mDefaultColorBHack.SetTo(mDefaultColorB);
mDefaultClockColorRHack.SetTo(mDefaultClockColorR);
mDefaultClockColorGHack.SetTo(mDefaultClockColorG);
mDefaultClockColorBHack.SetTo(mDefaultClockColorB);
mDefaultClockPlaceXHack.SetTo(mDefaultClockPlaceX);
mDefaultClockPlaceYHack.SetTo(mDefaultClockPlaceY);
tempHack = 1;
if(mStringCurrentPathImages == mTextControlmPathToImageFolder->Text())
{
cout << "It should now be disabled" << std::endl;
cout << mStringCurrentPathImages.String() << std::endl;
cout << "-------------------------" << std::endl;
cout << mTextControlmPathToImageFolder->Text() << std::endl;
}
else
{
cout << "It should now be enabled" << std::endl;
}
	/* Apply everything */						
	if (mTextControlmPathToImageFolder->Text() == mStringCurrentPathImages && 
		mTextControlmColorControlR->Text() == mStringRed && 
		mTextControlmColorControlG->Text() == mStringGreen && 
		mTextControlmColorControlB->Text() == mStringBlue && 
		mTextControlClockColorR->Text() == mStringClockCCR && 
		mTextControlClockColorG->Text() == mStringClockCCG && 
		mTextControlClockColorB->Text() == mStringClockCCB && 
		mTextControlClockPlaceX->Text() == mStringClockPlaceX && 
		mTextControlClockPlaceY->Text() == mStringClockPlaceY &&
		mCheckBoxBoolClock->Value() == temp)
	{
	mApplyView->LockLooper();
	mButtonApplyEverything->SetEnabled(false);
	mApplyView->UnlockLooper();
	}
	else
	{
	mApplyView->LockLooper();
	mButtonApplyEverything->SetEnabled(true);
	mApplyView->UnlockLooper();
	}
	/* Revert anything */
	if (mTextControlmPathToImageFolder->Text() == mDefaultImagepathTextHack && 
		mTextControlmColorControlR->Text() == mDefaultColorRHack && 
		mTextControlmColorControlG->Text() == mDefaultColorGHack && 
		mTextControlmColorControlB->Text() == mDefaultColorBHack && 
		mTextControlClockColorR->Text() == mDefaultClockColorRHack && 
		mTextControlClockColorG->Text() == mDefaultClockColorGHack && 
		mTextControlClockColorB->Text() == mDefaultClockColorBHack && 
		mTextControlClockPlaceX->Text() == mDefaultClockPlaceXHack && 
		mTextControlClockPlaceY->Text() == mDefaultClockPlaceYHack &&
		mCheckBoxBoolClock->Value() == tempHack)
	{ 
	mApplyView->LockLooper();
	mEraserButtonOfDoom->SetEnabled(false);
	mApplyView->UnlockLooper();
	}
	else
	{
	mApplyView->LockLooper();
	mEraserButtonOfDoom->SetEnabled(true);
	mApplyView->UnlockLooper();
	}
	/* Default path */
	if (mTextControlmPathToImageFolder->Text() == mDefaultImagepathTextHack)
	{
	mImageView->LockLooper();
	mButtonDefaultImagePath->SetEnabled(false);
	mImageView->UnlockLooper();
	}
	else
	{
	mImageView->LockLooper();
	mButtonDefaultImagePath->SetEnabled(true);
	mImageView->UnlockLooper();
	}
	/* Default colors */
	if (mTextControlmColorControlR->Text() == mDefaultColorRHack && 
		mTextControlmColorControlG->Text() == mDefaultColorGHack && 
		mTextControlmColorControlB->Text() == mDefaultColorBHack)
	{
	mColorView->LockLooper();
	mButtonDefaultColors->SetEnabled(false);
	mColorView->UnlockLooper();
	}
	else
	{
	mColorView->LockLooper();
	mButtonDefaultColors->SetEnabled(true);
	mColorView->UnlockLooper();
	}
	/* Default Clockcolors */
	if (mTextControlClockColorR->Text() == mDefaultClockColorRHack && 
		mTextControlClockColorG->Text() == mDefaultClockColorGHack && 
		mTextControlClockColorB->Text() == mDefaultClockColorBHack)
	{
	mClockView->LockLooper();
	mButtonDefaultClockColors->SetEnabled(false);
	mClockView->UnlockLooper();
	}
	else
	{
	mClockView->LockLooper();
	mButtonDefaultClockColors->SetEnabled(true);
	mClockView->UnlockLooper();
	}
	/* Default ClockPlacement */
	if (mTextControlClockPlaceX->Text() == mDefaultClockPlaceXHack && 
		mTextControlClockPlaceY->Text() == mDefaultClockPlaceYHack &&
		mCheckBoxBoolClock->Value() == tempHack)
	{
	mClockView->LockLooper();
	mButtonDefaultClockPlace->SetEnabled(false);
	mClockView->UnlockLooper();
	}
	else
	{
	mClockView->LockLooper();
	mButtonDefaultClockPlace->SetEnabled(true);
	mClockView->UnlockLooper();
	}
}
/*******Enable and Disable User Button**************/
int32
mWindow::EnDUserButtonThread_static(void *data)
{
	mWindow *enauserbutton = (mWindow *)data;
	enauserbutton->EnDUserButton_Thread();
	return 0;
}

/*************************************************/
void mWindow::EnDUserButton_Thread()
{
mPasswordHack = mAddPassWord->Text();
mPasswordRetypeHack = mAddPassWordRetype->Text();
mPasswordDisableButtonHack.SetTo("");
	if (mPasswordRetypeHack == mPasswordHack && mPasswordHack != mPasswordDisableButtonHack)
	{
	mView->LockLooper();
	mButtonChangeLogin->SetEnabled(true);
	mView->UnlockLooper();
	}
	else
	{
	mView->LockLooper();
	mButtonChangeLogin->SetEnabled(false);
	mView->UnlockLooper();
	}
}
/*******Update Strings**************/
int32
mWindow::UpdateStringsThread_static(void *data)
{
	mWindow *updatestrings = (mWindow *)data;
	updatestrings->UpdateStrings_Thread();
	return 0;
}

/*************************************************/
void mWindow::UpdateStrings_Thread()
{
	mStringCurrentPathImages.SetTo(mTextControlmPathToImageFolder->Text());
	mStringRed.SetTo(mTextControlmColorControlR->Text());
	mStringGreen.SetTo(mTextControlmColorControlG->Text());
	mStringBlue.SetTo(mTextControlmColorControlB->Text());
	mStringClockCCR.SetTo(mTextControlClockColorR->Text());
	mStringClockCCG.SetTo(mTextControlClockColorG->Text());
	mStringClockCCB.SetTo(mTextControlClockColorB->Text());
	mStringClockPlaceX.SetTo(mTextControlClockPlaceX->Text());
	mStringClockPlaceY.SetTo(mTextControlClockPlaceY->Text());
	temp = mCheckBoxBoolClock->Value();
	mStringBoolClock.SetTo("");
	mStringBoolClock << temp;
}

/***************************************************/
bool mWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return BWindow::QuitRequested();
}
