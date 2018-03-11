#pragma once

/*
작성자 : 임종현
작성일 : 2018-03-09
설명   : 윈도우를 생성하고 전체 프로그램을 관리하는 클래스입니다.
*/

#include "Singleton.h"

#define MAX_LOADSTRING 100

class CInput;
class CBackBuffer;

class CGameApp : public Singleton<CGameApp>
{
	//생성자 선언 및 프랜드 클래스 선언 매크로
	SINGLETON_DECL(CGameApp);

public:
	~CGameApp();

	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	
	void BuildObjects();

	void FrameAdvance();

	void ShutDown();
	
private:
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Update(float timeElpased = UPDATE_FPS);
	void Draw(float timeElpased = UPDATE_FPS);
	void ProcessInput(CInput *input);

	void ReleaseObjects();

	// 복사생성과 대입연산을 금지합니다
	CGameApp(const CGameApp& other) = delete;
	CGameApp& operator=(const CGameApp& other) = delete;

	HWND m_hWnd;
	HINSTANCE m_hInst;
	HDC m_hdc;

	WCHAR m_szTitle[MAX_LOADSTRING];       // 제목 표시줄 텍스트입니다.
	WCHAR m_szWindowClass[MAX_LOADSTRING]; // 기본 창 클래스 이름입니다.

	RECT m_rtClientSize;
	CBackBuffer *m_backBuffer;
};

