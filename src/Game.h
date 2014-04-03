
#ifndef HICHAN_APP_GAME_H
#define HICHAN_APP_GAME_H

class Window;
typedef std::weak_ptr< Window > WindowWeakPtr;

/**
 *  Gameクラス
 */
class Game
{
    //  -------------------------------------------------------------------------------
    //  生成と破棄
    //  -------------------------------------------------------------------------------
public:
    /**
     *  コンストラクタ
     */
    Game( const WindowWeakPtr& window );

    //  -------------------------------------------------------------------------------
    //  基本機能
    //  -------------------------------------------------------------------------------
public:
    /**
     *  ゲームの初期化処理を行う
     */
    bool Initialize();
    /**
     *  ゲームの解放処理を行う
     */
    void Finalize();
    /**
     *  ゲーム１フレームの処理を行う
     */
    void Run();
	/**
	 *  ゲームの解放処理を行う
	 */
	void Game::Release();

private:
    WindowWeakPtr window;   ///<    既存ウィンドウを指すポインタ
};

#endif