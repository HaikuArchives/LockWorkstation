/**********************************************************************************/
/*****************        Lock Workstation By Marius Stene        *****************/
/*****************             m_stene@yahoo.com, 2002            *****************/
/*****************        My contribution to this great OS        *****************/
/**********************************************************************************/
/*****************  You are welcome to use any part of this code  *****************/
/*****************      in whole, or in parts freely without      *****************/
/*****************                  contacting me                 *****************/
/**********************************************************************************/

#ifndef _BitmapView_h
#define _BitmapView_h

#include <View.h>

class BitmapView : public BView
{
public:
	BitmapView(BBitmap* bitmap, BRect frame, const char* name,
		uint32 resizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
		uint32 flags = B_WILL_DRAW);
	~BitmapView();
	
	BBitmap* Bitmap();
	void SetBitmap(BBitmap* bitmap);
	
	void AttachedToWindow();
	void Draw(BRect updateRect);
	void ResizeToPreferred();
	void GetPreferredSize(float* width, float* height);
	
private:
	BBitmap* m_pBitmap;
};

#endif