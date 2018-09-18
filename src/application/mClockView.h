// mWindow.h

#ifndef _mClockView_h_
#define _mClockView_h_

#include "mConstant.h"

class mClockView
		: public BView
{
public:
						mClockView(BRect rect, const char *name, uint32 resizingMode, uint32 flags);
	void				Draw(BRect updateRect);
	 virtual void		Pulse();
			
private:
	time_t				tmptodaytime;
	char 				charer[1024];
	int					todaysecond , todayminute , todayhour , todayday , todaymonth , todayyear ;
	int					mColorR, mColorG, mColorB, mPlaceX, mPlaceY, mFontSize;
	bool				mShowClock;
	struct tm			*TodayTime;
	BString 			mTimer;
	BString				mMinute;
	BString				mHour;
	BString				mSecond;
	BPath 				path;
	BFile				file;
	status_t			status;
	BMessage			savemessage;
	BString				mStringBoolClock;
	BString				mStringColorR;
	BString				mStringColorG;
	BString				mStringColorB;
	BString				mStringPlaceX;
	BString				mStringPlaceY;
	BString				mStringFontSize;
	mClockView*			mCV;
	//threads
	thread_id			UserThread;
	static int32 		UserThreadChange_static(void *data);
	void 				UserThreadChangeImage();
};

#endif