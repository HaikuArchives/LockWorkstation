// mWindow.h

#ifndef _mWindow_h_
#define _mWindow_h_

#include "mBitmap.h"
#include "mConstant.h"
#include "mClockView.h"

class mWindow
		: public BWindow
{
public:
						mWindow(const char *mWindowTitle);
						~mWindow();
	virtual void 		MessageReceived(BMessage* message);		
	virtual bool 		QuitRequested();
			
private:
	int					mAvoidFlickering;
	BView* 				mView;
	BBitmap*			BitmapBounds;
	BBitmap*			UserImageBounds;
	BBitmap*			UserNoImageBounds;
	BitmapView*			mViewBitmap;
	BitmapView*			mViewUserImage;
	BitmapView*			mViewUserNoImage;
	BButton*			mButtonLogin;
	BTextControl*		mTextUser;
	BTextControl*		mTextPass;
	BString				Pass;
	BString				User;
	BString 			mStringLoginButtonLabelAs;
	BString				mStringLoginButtonLabelUnlock;
	BString 			mTheRightUserName; 
	BString 			mTheRightPassword;
	BString				mStringPathToBG;
	BString				mStringPathToCU;
	BString				mStringPathToNOCU;
	BString				mStringPathToImageFolder;
	BString				mStringR;
	BString				mStringG;
	BString				mStringB;
	BString				mStringLanguage;
	int 				mColorR;
	int 				mColorG;
	int 				mColorB;
	int 				mLanguage;
	BPath				path;
	BFile				file;
	status_t			status;
	BMessage			savemessage;
	mClockView* 		mclockview;
	//Threads
	thread_id			UserThread;
	static int32 		UserThreadChange_static(void *data);
	void 				UserThreadChangeImage();
	thread_id			UserThreadUndo;
	static int32 		UserThreadChange_staticUndo(void *data);
	void 				UserThreadChangeImageUndo();
	thread_id			InvalidateThread;
	static int32 		InvalidateThread_static(void *data);
	void 				InvalidatemClockViewThread();
};

#endif