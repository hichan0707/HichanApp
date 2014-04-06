///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Fps.h
///	@brief		FPS
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


///	=============================================================================
///	@brief		FPS管理用
///	=============================================================================
class Fps
{
public:
	///	-----------------------------------------------------------------------------
	///	@brief		コンストラクタ
	///	@param		num		FPS制御数
	///	-----------------------------------------------------------------------------
	Fps( const unsigned long num=60 );
	
	///	-----------------------------------------------------------------------------
	///	@brief		コピーコンストラクタ
	///	-----------------------------------------------------------------------------
	Fps( Fps& ref );

	///	-----------------------------------------------------------------------------
	///	@brief		デストラクタ
	///	-----------------------------------------------------------------------------
	~Fps();


	///	-----------------------------------------------------------------------------
	///	@brief		待機処理
	///	-----------------------------------------------------------------------------
	void wait();

	///	-----------------------------------------------------------------------------
	///	@brief		出力
	///	-----------------------------------------------------------------------------
	void output();

public:
	///	-----------------------------------------------------------------------------
	///	@brief		代入演算子
	///	-----------------------------------------------------------------------------
	Fps& operator=( const Fps& ref );

private:
	///	-----------------------------------------------------------------------------
	///	@			メンバ
	///	-----------------------------------------------------------------------------
	const unsigned long _kFrame;
	unsigned long _count, _count0t, _tickCount;
	unsigned long *_frameCnt;
	double _ave;

};
