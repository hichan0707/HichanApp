///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Debug.h
///	@brief		�f�o�b�O�p
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#ifndef HICHAN_APP_DEBUG_H
#define HICHAN_APP_DEBUG_H


// �f�o�b�O�ł̏ꍇ�A���������[�N�ꏊ����肷��}�N��
#if defined( _DEBUG ) && !defined( NEW )
	#define	NEW	new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#else
	#define	NEW	new
#endif



#if defined( _DEBUG ) && !defined( TRACE_F )
#define DEBUG_TRACE_F( expr ) _CrtDbgReport( _CRT_WARN, __FILE__, __LINE__, NULL, "%s", static_cast<::std::ostringstream&>(::std::ostringstream() << expr).str().c_str() )
#else
#define DEBUG_TRACE_F( expr )
#endif
// TRACE_F( "start" << std::endl );

#endif