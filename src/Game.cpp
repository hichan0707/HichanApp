///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Game.cpp
///	@brief		ゲーム
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "Game.h"
#include "Window.h"
#include "Fps.h"

#include "Allocator.h"

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

	Hichan::Allocator allocator;

	Fps fps( 60 );
	//ゲームループ ウィンドウが閉じられるまで１フレームの処理を繰り返す
	for( ; ; )
	{


		// 終了
		if( GetKeyState( VK_ESCAPE ) &0x8000 ) {
			_window->close();
		}

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

	return reinterpret_cast<Game *>( obj )->run();
}



