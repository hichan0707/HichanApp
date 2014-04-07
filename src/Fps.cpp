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

	//60�t���[����1��ڂȂ�
	if( _count == 0 )
	{
		//���S�ɍŏ��Ȃ�܂��Ȃ�(TickCount...50��?�Ɉ�x0����...�ŏ����Ă�����...�܂�������...|:3�~)
		if( _tickCount != 0 )
		{
			//�O��L�^�������Ԃ����Ɍv�Z
			term = _count0t + 1000 - TickCount;
		}
	}
	else
	{
		//�҂ׂ�����=���݂���ׂ�����-���݂̎���
		term = static_cast<unsigned long>( _count0t + _count * ( 1000.0 / _kFrame ) ) - TickCount;
	}

	//�҂ׂ����Ԃ����҂�
	if( term > 0 )
	{
		Sleep( term );
	}
	
	//60�t���[����1�x������
	if( _count == 0 )
	{
		_count0t = TickCount;
	}

	_frameCnt[_count] = TickCount - _tickCount; //�P���������Ԃ��L�^
	_tickCount = TickCount;

	//���όv�Z
	if( _count == _kFrame - 1 )
	{
		_ave = 0;
		double local_ave = 0; // ���[�J���ϐ��쐬
		register int i; // register�w��q ...�K�v���H
//		for( i = 0; i < _kFrame; ++i )
//		for( i = _kFrame ; --i; ) // �����������莞��-1�A�ց\
		for( i = _kFrame - 1; i >= 0; --i ) // �����������莞��-1�A
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