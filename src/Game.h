
#ifndef HICHAN_APP_GAME_H
#define HICHAN_APP_GAME_H

class Window;
typedef std::weak_ptr< Window > WindowWeakPtr;

/**
 *  Game�N���X
 */
class Game
{
    //  -------------------------------------------------------------------------------
    //  �����Ɣj��
    //  -------------------------------------------------------------------------------
public:
    /**
     *  �R���X�g���N�^
     */
    Game( const WindowWeakPtr& window );

    //  -------------------------------------------------------------------------------
    //  ��{�@�\
    //  -------------------------------------------------------------------------------
public:
    /**
     *  �Q�[���̏������������s��
     */
    bool Initialize();
    /**
     *  �Q�[���̉���������s��
     */
    void Finalize();
    /**
     *  �Q�[���P�t���[���̏������s��
     */
    void Run();
	/**
	 *  �Q�[���̉���������s��
	 */
	void Game::Release();

private:
    WindowWeakPtr window;   ///<    �����E�B���h�E���w���|�C���^
};

#endif