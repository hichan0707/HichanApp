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
    //���������[�N�̌��o��L����
    //  �A�E�g�v�b�g�E�B���h�E�Ƀ��������[�N���̏�񂪏o�͂����
    ::_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	
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
        //�Q�[�����[�v
        //  �E�B���h�E��������܂łP�t���[���̏������J��Ԃ�
        while( !window->isClosed() )
        {
            //�P�t���[���̏���
            game.run();

            //���b�Z�[�W�L���[�ɂ���S�Ă�windows�C�x���g����������
            Application::doEvents();
        }
    }
	game.finalize();
    return 0;
}