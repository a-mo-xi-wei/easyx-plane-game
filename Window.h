#pragma once
#include"CommonHead.h"
class Window
{
public:
	Window(int width,int hight, int flag);
	void setWindowTitle(const string &title);
	//存储空间固定，所有实例共享
	static int getWidth();
	static int getHeight();
	static void beginDraw();
	static void clearBackground();
	static void flushDraw();
	static void endDraw();

	inline static bool hasMessage() { return ::peekmessage(&m_msg, EX_MOUSE | EX_KEY); }
	inline static const ExMessage& getMessage() { return m_msg; }
private:
	//成员属性中不需要宽和高，因为窗口的宽和高可以通过easyx中的getwidth和gethight获得。
	HWND m_handle;
	static ExMessage m_msg;//声明为静态，整个窗口共享消息
};

