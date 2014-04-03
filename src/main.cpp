///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		main.cpp
///	@brief		エントリポイント定義
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// 参考
// http://d.hatena.ne.jp/setuna-kanata/20100706/1278434897

#include "Application.h"
#include "Window.h"
#include "Game.h"

///	-----------------------------------------------------------------------------
///	@			エントリポイント
///	-----------------------------------------------------------------------------
int main()
{
    //メモリリークの検出を有効化
    //  アウトプットウィンドウにメモリリーク時の情報が出力される
    ::_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    //ゲーム用ウィンドウを生成
    WindowPtr window = Application::CreateGameWindow( "hoge", 720, 480 );
    if( !window )return 0;

    Game game( window );
    //ゲームを初期化して、ゲームループを開始する
    if( game.Initialize() )
    {
        //ゲームループ
        //  ウィンドウが閉じられるまで１フレームの処理を繰り返す
        while( !window->IsClosed() )
        {
            //１フレームの処理
            game.Run();

            //メッセージキューにある全てのwindowsイベントを処理する
            Application::DoEvents();
        }
    }
    game.Release();
    return 0;
}