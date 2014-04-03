#include "Game.h"

/**
 *  コンストラクタ
 *
 *  @param  window  既存ウィンドウのweak_ptr
 */
Game::Game( const WindowWeakPtr& window )
    : window( window )
{
}

/**
 *  ゲームの初期化処理を行う
 *
 *  @param  初期化成功時trueを、失敗時falseを返す
 */
bool Game::Initialize()
{
    return true;    //初期化成功
}

/**
 *  ゲームの解放処理を行う
 */
void Game::Release()
{
}

/**
 *  ゲーム１フレームの処理を行う
 */
void Game::Run()
{
}