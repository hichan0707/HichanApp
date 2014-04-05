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
            ::DispatchMessage( &msg );        //�E�B���h�E�v���V�[�W���̌Ăяo��
        }
        else
        {
            //�P�t���[���̏������s�����߂ɃQ�[�����[�v�֏�����߂�
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

    //�E�B���h�E�N���X�̓o�^
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

    //�N���C�A���g�T�C�Y����E�B���h�E�T�C�Y���v�Z
    RECT rect = { 0, 0, clientWidth, clientHeight };
    ::AdjustWindowRectEx( &rect, style, FALSE, exstyle );

    //�E�B���h�E����
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

    std::cout << "�E�B���h�E�𐶐�( " << title << "," << clientWidth << "," << clientHeight << " )" << std::endl;

    return window;
}