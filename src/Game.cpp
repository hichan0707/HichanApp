#include "Game.h"

/**
 *  �R���X�g���N�^
 *
 *  @param  window  �����E�B���h�E��weak_ptr
 */
Game::Game( const WindowWeakPtr& window )
    : window( window )
{
}

/**
 *  �Q�[���̏������������s��
 *
 *  @param  ������������true���A���s��false��Ԃ�
 */
bool Game::Initialize()
{
    return true;    //����������
}

/**
 *  �Q�[���̉���������s��
 */
void Game::Release()
{
}

/**
 *  �Q�[���P�t���[���̏������s��
 */
void Game::Run()
{
}