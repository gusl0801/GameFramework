#include "stdafx.h"
#include "CAppRunner.h"


CAppRunner::CAppRunner(CGameApp *app)
	:m_app(app)
{
}


CAppRunner::~CAppRunner()
{
}

bool CAppRunner::Init(HINSTANCE hInst, int nCmdShow)
{
	m_app->MyRegisterClass(hInst);

	// 응용 프로그램 초기화를 수행합니다.
	if (!m_app->InitInstance(hInst, nCmdShow))
	{	// 응용 프로그램 생성이 정상적이지 않은 경우 중단
		m_app->ShutDown();
		return false;
	}

	m_app->BuildObjects();

	srand((unsigned int)time(NULL));

	return true;
}

int CAppRunner::BeginApp()
{
	MSG msg;

	// 기본 메시지 루프입니다
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}//end if  운영체제로부터 메시지를 받은 경우 해당 메시지를 콜백함수에게 전달
		else
		{
			m_app->FrameAdvance();
		}//end elif 메시지가 없는 경우에도 게임은 진행되어야 하므로 게임 갱신
	}

	return (int)msg.wParam;
}
