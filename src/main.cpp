///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		main.cpp
///	@brief		�G���g���|�C���g��`
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// �Q�l
// http://d.hatena.ne.jp/setuna-kanata/20100706/1278434897

#include "Application.h"
#include "Window.h"
#include "Game.h"
















///	-----------------------------------------------------------------------------
///	@			�G���g���|�C���g
///	-----------------------------------------------------------------------------
int main()
{
#ifdef _DEBUG
    //���������[�N�̌��o��L����
    //  �A�E�g�v�b�g�E�B���h�E�Ƀ��������[�N���̏�񂪏o�͂����
    ::_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    //�Q�[���p�E�B���h�E�𐶐�
    WindowPtr window = Application::createGameWindow( "hoge", 720, 480 );
    if( !window )
	{
		return 0;
	}

    Game game( window );
    //�Q�[�������������āA�Q�[�����[�v���J�n����
    if( game.initialize() )
    {
		game.start();

        //�Q�[�����[�v
        //  �E�B���h�E��������܂łP�t���[���̏������J��Ԃ�
        while( !window->isClosed() )
        {
            //���b�Z�[�W�L���[�ɂ���S�Ă�windows�C�x���g����������
            Application::doEvents();

			// �ҋ@
			Sleep( 16 );
        }
    }
	game.finalize();
    return 0;
}