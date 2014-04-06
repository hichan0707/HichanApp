///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Debug.h
///	@brief		デバッグ用
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#ifndef HICHAN_APP_DEBUG_H
#define HICHAN_APP_DEBUG_H


// デバッグ版の場合、メモリリーク場所を特定するマクロ
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