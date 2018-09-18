// mWindow.cpp
#include "mClockView.h"

const char* mPathToConfigFile3 =				"LockWorkstationSettings";
const char* mNameConfigBool =				"clock";
const char* mNameConfigColorR =				"clockR";
const char* mNameConfigColorG =				"clockG";
const char* mNameConfigColorB =				"clockB";
const char* mNameConfigPlaceX =				"clockX";
const char* mNameConfigPlaceY =				"clockY";
const char* mNameConfigFontSize =			"fontSize";

const char* mDefaultBoolClock =				"0";
const char* mDefaultColorClockR =			"0";
const char* mDefaultColorClockG =			"0";
const char* mDefaultColorClockB =			"0";
const char* mDefaultClockPlaceX =			"0";
const char* mDefaultClockPlaceY =			"0";
const char* mDefaultFontSize =				"8"; //*2

/*************************************************/
/******************* Start ***********************/
/*************************************************/
mClockView::mClockView(BRect rect, const char *name, uint32 resizingMode, uint32 flags)
			: BView(BRect(0, 0, 200, 100), "Mariux", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_FORCE_ANTIALIASING | B_WILL_DRAW | B_PULSE_NEEDED)
{
UserThread = spawn_thread(UserThreadChange_static, "Change Image Thread",
								B_URGENT_DISPLAY_PRIORITY, this);
resume_thread(UserThread);	
//FILEREAD
find_directory(B_USER_SETTINGS_DIRECTORY, &path);
path.Append(mPathToConfigFile3);
status = file.SetTo(path.Path(), B_READ_ONLY);
	if (status == B_OK) 
	{
	status = savemessage.Unflatten(&file);
	}
	
//Bool
	if (savemessage.HasString(mNameConfigBool) == 0)
	{
	savemessage.AddString(mNameConfigBool, mDefaultBoolClock);
	}
savemessage.FindString(mNameConfigBool, &mStringBoolClock);

//Red
	if (savemessage.HasString(mNameConfigColorR) == 0)
	{
	savemessage.AddString(mNameConfigColorR, mDefaultColorClockR);
	}
savemessage.FindString(mNameConfigColorR, &mStringColorR);

//Green
	if (savemessage.HasString(mNameConfigColorG) == 0)
	{
	savemessage.AddString(mNameConfigColorG, mDefaultColorClockG);
	}
savemessage.FindString(mNameConfigColorG, &mStringColorG);

//Blue
	if (savemessage.HasString(mNameConfigColorB) == 0)
	{
	savemessage.AddString(mNameConfigColorB, mDefaultColorClockB);
	}
savemessage.FindString(mNameConfigColorB, &mStringColorB);

//PlaceX
	if (savemessage.HasString(mNameConfigPlaceX) == 0)
	{
	savemessage.AddString(mNameConfigPlaceX, mDefaultClockPlaceX);
	}
savemessage.FindString(mNameConfigPlaceX, &mStringPlaceX);

//PlaceY
	if (savemessage.HasString(mNameConfigPlaceY) == 0)
	{
	savemessage.AddString(mNameConfigPlaceY, mDefaultClockPlaceY);
	}
savemessage.FindString(mNameConfigPlaceY, &mStringPlaceY);

//Bool
	if (savemessage.HasString(mNameConfigFontSize) == 0)
	{
	savemessage.AddString(mNameConfigFontSize, mDefaultFontSize);
	}
savemessage.FindString(mNameConfigFontSize, &mStringFontSize);

if (file.SetTo(path.Path(), B_WRITE_ONLY | B_CREATE_FILE) == B_OK) 
	{
	savemessage.Flatten(&file);
	}

mFontSize = atoi(mStringFontSize.String());
mColorR = atoi(mStringColorR.String());
mColorG = atoi(mStringColorG.String());
mColorB = atoi(mStringColorB.String());
mPlaceX = atoi(mStringPlaceX.String());
mPlaceY = atoi(mStringPlaceY.String());
SetHighColor(mColorR, mColorG, mColorB);
SetDrawingMode(B_OP_OVER);
SetFont(be_bold_font);
SetFontSize(((mFontSize)*2));
SetViewColor(B_TRANSPARENT_COLOR);
}

/*********************************************/
/***************** Draw **********************/
/*********************************************/
void mClockView::Draw(BRect updateRect)
{
mSecond.SetTo("");
mMinute.SetTo("");
mHour.SetTo("");
//second
if(todaysecond < 10)
{
mSecond << "0" << todaysecond;
}
else
{
mSecond << todaysecond;
}
//minute
if(todayminute < 10)
{
mMinute << "0" << todayminute;
}
else
{
mMinute << todayminute;
}
//hour
if(todayhour < 10)
{
mHour << "0" << todayhour;
}
else
{
mHour << todayhour;
}
if (mStringBoolClock == "0")
{
mShowClock = false;
}
else
{
mShowClock = true;
}
mTimer.SetTo("");
if (mShowClock)
{
mTimer << mHour.String() << ":" << mMinute.String() << ":" << mSecond.String();
}
MovePenTo((mPlaceX+2), (mPlaceY+15));
DrawString(mTimer.String());
}

void mClockView::Pulse()
{
time(&tmptodaytime);
TodayTime = localtime(&tmptodaytime);
	if (todaysecond != TodayTime->tm_sec)
	{
	Invalidate();
	}
}

int32
mClockView::UserThreadChange_static(void *data)
{
	mClockView *changeimage = (mClockView *)data;
	changeimage->UserThreadChangeImage();

	return 0;
}

void mClockView::UserThreadChangeImage()
{
int a = 1;
while (a == 1)
{
time(&tmptodaytime);
TodayTime = localtime(&tmptodaytime);
todaysecond = TodayTime->tm_sec;
todayminute = TodayTime->tm_min;
todayhour   = TodayTime->tm_hour;
sleep(1);
}
}

