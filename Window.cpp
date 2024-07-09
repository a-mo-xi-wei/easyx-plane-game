#include "window.h"

ExMessage Window::m_msg;

Window::Window(int width, int hight, int flag)
{
    m_handle=::initgraph(width, hight,flag);
    ::setbkmode(TRANSPARENT);
}

void Window::setWindowTitle(const string& title)
{
    ::SetWindowText(m_handle, title.c_str());
}

int Window::getWidth()
{
    return ::getwidth();
}

int Window::getHeight()
{
    return ::getheight();
}

void Window::beginDraw()
{
    ::BeginBatchDraw();
}

void Window::clearBackground()
{
    ::cleardevice();
}

void Window::flushDraw()
{
    ::FlushBatchDraw();
}

void Window::endDraw()
{
    ::EndBatchDraw();
}
