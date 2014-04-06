///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Game.cpp
///	@brief		ゲーム
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "Game.h"
#include "Window.h"
#include "Fps.h"


/////////////////////////////////////////////////////////////////////////////////
Game::Game( const WindowPtr& window )
	: _window( window )
	,runThreadHendle( nullptr )
{
}

/////////////////////////////////////////////////////////////////////////////////
bool Game::initialize()
{
	DEBUG_TRACE_F( "Game::initialize" << std::endl );
	return true; //初期化成功
}

/////////////////////////////////////////////////////////////////////////////////
void Game::start()
{
	runThreadHendle = (HANDLE)_beginthreadex( NULL, 0, beginThread, this, 0, NULL ); 
}

/////////////////////////////////////////////////////////////////////////////////
void Game::finalize()
{
	DEBUG_TRACE_F( "Game::finalize" << std::endl );
	if( runThreadHendle )
	{
		WaitForSingleObject( runThreadHendle, INFINITE );
		CloseHandle( runThreadHendle );
	}
}

/////////////////////////////////////////////////////////////////////////////////
int Game::run()
{
	//  ウィンドウの生存
	if( _window->isClosed() )
	{
		return 1;
	}

	Fps fps(120);
	//ゲームループ ウィンドウが閉じられるまで１フレームの処理を繰り返す
	for( ; ; )
	{
		fps.wait();
		fps.output();
		if( _window->isClosed() )
		{
			break;
		}
	}

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////
unsigned int WINAPI Game::beginThread( void *obj )
{
	DEBUG_TRACE_F( "Game::beginThread" << std::endl );

	reinterpret_cast<Game *>( obj )->run();

	return 0;
}



