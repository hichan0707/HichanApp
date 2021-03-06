///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		window.h
///	@brief		HWNDのラッパー
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#ifndef HICHAN_APP_WINDOW_H
#define HICHAN_APP_WINDOW_H


///	=============================================================================
///	@brief		HWNDのラッパークラス
///	=============================================================================
class Window
{
public:
	///	-----------------------------------------------------------------------------
	///	@brief		コンストラクタ
	///	-----------------------------------------------------------------------------
	Window( HWND windowHandle );

public:
	///	-----------------------------------------------------------------------------
	///	@brief		ウィンドウが閉じられたか
	///	-----------------------------------------------------------------------------
	inline bool isClosed()const{ return ::IsWindow( _windowHandle ) == FALSE; }

	///	-----------------------------------------------------------------------------
	///	@brief		ウィンドウを閉じる
	///	-----------------------------------------------------------------------------
	void close();

private:
	///	-----------------------------------------------------------------------------
	///	@			変数
	///	-----------------------------------------------------------------------------
	HWND _windowHandle;
};


#endif