// Framework.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Main.h"
#include "CAppRunner.h"
#include "CGameApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FRAMEWORK)); 

	CGameApp::Create();
	CAppRunner appRunner(CGameApp::Get());
	
	appRunner.Init(hInstance, nCmdShow);

	return appRunner.BeginApp();
}