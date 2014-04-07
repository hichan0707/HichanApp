///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Fps.cpp
///	@brief		FPS
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include "Fps.h"

/////////////////////////////////////////////////////////////////////////////////
Fps::Fps( const unsigned long num/*=60*/ )
	:_kFrame( num )
	,_count( 0 )
	,_count0t( 0 )
	,_tickCount( 0 )
	,_frameCnt( NEW unsigned long[_kFrame] )
	,_ave( 0 )
{
}

/////////////////////////////////////////////////////////////////////////////////
Fps::Fps( Fps& ref )
	:_kFrame( ref._kFrame )
	,_count( ref._count )
	,_count0t( ref._count0t )
	,_tickCount( ref._tickCount )
	,_frameCnt( NEW unsigned long[_kFrame] )
	,_ave( ref._ave )
{
	memcpy_s( _frameCnt, sizeof( _frameCnt ), ref._frameCnt, sizeof( ref._frameCnt ) );
}

/////////////////////////////////////////////////////////////////////////////////
Fps::~Fps()
{
	if( _frameCnt != nullptr )
	{
		delete _frameCnt;
		_frameCnt = nullptr;
	}
}

/////////////////////////////////////////////////////////////////////////////////
void Fps::wait()
{
	const unsigned long TickCount = GetTickCount();
	int term = 0;

	//60フレームの1回目なら
	if( _count == 0 )
	{
		//完全に最初ならまたない(TickCount...50日?に一度0だよ...最初っていつかな...まぁいいか...|:3ミ)
		if( _tickCount != 0 )
		{
			//前回記録した時間を元に計算
			term = _count0t + 1000 - TickCount;
		}
	}
	else
	{
		//待つべき時間=現在あるべき時刻-現在の時刻
		term = static_cast<unsigned long>( _count0t + _count * ( 1000.0 / _kFrame ) ) - TickCount;
	}

	//待つべき時間だけ待つ
	if( term > 0 )
	{
		Sleep( term );
	}
	
	//60フレームに1度基準を作る
	if( _count == 0 )
	{
		_count0t = TickCount;
	}

	_frameCnt[_count] = TickCount - _tickCount; //１周した時間を記録
	_tickCount = TickCount;

	//平均計算
	if( _count == _kFrame - 1 )
	{
		_ave = 0;
		double local_ave = 0; // ローカル変数作成
		register int i; // register指定子 ...必要か？
//		for( i = 0; i < _kFrame; ++i )
//		for( i = _kFrame ; --i; ) // 初期条件判定時に-1、へ―
		for( i = _kFrame - 1; i >= 0; --i ) // 初期条件判定時に-1、
		{
			local_ave += _frameCnt[i];
		}
		//_ave = local_ave;
		_ave = local_ave / _kFrame;
	}
	_count = ( ++_count ) % _kFrame ;
}

/////////////////////////////////////////////////////////////////////////////////
void Fps::output()
{
	if( _ave != 0 )
	{
		std::cout << "FPS( " << ( 1000 / _ave ) << " )" << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////
Fps& Fps::operator=( const Fps& ref )
{
	this->_ave = ref._ave;
	this->_count = ref._count;
	this->_frameCnt = ref._frameCnt;
	this->_ave = ref._ave;

	return ( *this );
}