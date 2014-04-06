///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Game.h
///	@brief		ゲーム
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#ifndef HICHAN_APP_GAME_H
#define HICHAN_APP_GAME_H

/////////////////////////////////////////////////////////////////////////////////
///	@		前方宣言
class Window;
typedef std::shared_ptr< Window > WindowPtr;

///	=============================================================================
///	@brief		Gameクラス
///	=============================================================================
class Game
{
public:
	///	-----------------------------------------------------------------------------
	///	@brief		コンストラクタ
	///	@param		window  既存ウィンドウのweak_ptr
	///	-----------------------------------------------------------------------------
    Game( const WindowPtr& window );

public:
	///	-----------------------------------------------------------------------------
	///	@brief		ゲームの初期化処理を行う
	///	@param		初期化成功時trueを、失敗時falseを返す
	///	-----------------------------------------------------------------------------
    bool initialize();

	///	-----------------------------------------------------------------------------
	///	@brief		ゲームの処理を開始する
	///	-----------------------------------------------------------------------------
    void start();

	///	-----------------------------------------------------------------------------
	///	@brief		ゲームの解放処理を行う
	///	-----------------------------------------------------------------------------
    void finalize();

private:
	
	///	-----------------------------------------------------------------------------
	///	@brief		ゲーム１フレームの処理を行う
	///	-----------------------------------------------------------------------------
    int run();

	///	-----------------------------------------------------------------------------
	///	@brief		マルチスレッド化するメンバ関数
	///	-----------------------------------------------------------------------------
	static unsigned int WINAPI beginThread( void *obj );

	///	-----------------------------------------------------------------------------
	///	@			メンバ
	///	-----------------------------------------------------------------------------
	std::shared_ptr<Window> _window;   ///<    既存ウィンドウを指すポインタ
	HANDLE runThreadHendle;
};

#endif