///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		window.cpp
///	@brief		HWNDのラッパー
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "Window.h"


/////////////////////////////////////////////////////////////////////////////////
Window::Window( HWND windowHandle )
    : _windowHandle( windowHandle )
{
}

/////////////////////////////////////////////////////////////////////////////////
void Window::close()
{
	::PostMessage( _windowHandle , WM_CLOSE, 0, NULL );
}