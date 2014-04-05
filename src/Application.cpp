#include "Application.h"
#include "Window.h"

/////////////////////////////////////////////////////////////////////////////////
bool Application::doEvents()
{
    MSG msg;
    for( ; ; )
    {
        if( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            if( msg.message == WM_QUIT )
			{
				return false;
			}

            ::TranslateMessage( &msg );
            ::DispatchMessage( &msg );        //ウィンドウプロシージャの呼び出し
        }
        else
        {
            //１フレームの処理を行うためにゲームループへ処理を戻す
            return true;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////
WindowPtr Application::createGameWindow( const std::string& title, int clientWidth, int clientHeight )
{
    const std::string class_name = "hoge";
    const DWORD style = WS_OVERLAPPEDWINDOW & ~( WS_MAXIMIZEBOX | WS_THICKFRAME );
    const DWORD exstyle = 0;
    const HINSTANCE instance = ::GetModuleHandle( nullptr );

    //ウィンドウクラスの登録
    WNDCLASSEX wc = { sizeof( WNDCLASSEX ) };
    wc.hInstance = instance;
    wc.lpszClassName = class_name.c_str();
    wc.lpfnWndProc = DefWindowProc;
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wc.hIcon = static_cast< HICON >( ::LoadImage( nullptr, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED ) );
    wc.hIconSm = wc.hIcon;
    wc.hCursor = static_cast< HCURSOR >( ::LoadImage( nullptr, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED ) );
    wc.hbrBackground = static_cast< HBRUSH >( ::GetStockObject( WHITE_BRUSH ) );
    if( !::RegisterClassEx( &wc ) )
	{
		return nullptr;
	}

    //クライアントサイズからウィンドウサイズを計算
    RECT rect = { 0, 0, clientWidth, clientHeight };
    ::AdjustWindowRectEx( &rect, style, FALSE, exstyle );

    //ウィンドウ生成
    HWND windwoHandle =
		::CreateWindowEx(
			exstyle,
			class_name.c_str(),
			title.c_str(),
			style,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			nullptr,
			nullptr,
			instance,
			nullptr 
        );
    if( windwoHandle == nullptr )
	{
		return nullptr;
	}
    ::ShowWindow( windwoHandle, SW_SHOW );

    WindowPtr window( new Window( windwoHandle ) );

    std::cout << "ウィンドウを生成( " << title << "," << clientWidth << "," << clientHeight << " )" << std::endl;

    return window;
}