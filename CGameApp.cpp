#include "stdafx.h"
#include "CGameApp.h"
#include "resource.h"
#include "CBackBuffer.h"

// �ν��Ͻ��� �ʱ�ȭ ���ݴϴ�.
SINGLETON_IMPL(CGameApp);

CGameApp::CGameApp()
{
	m_hInst = nullptr;
	m_hWnd = nullptr;
}

CGameApp::~CGameApp()
{
}

//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM CGameApp::MyRegisterClass(HINSTANCE hInstance)
{
	LoadStringW(hInstance, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_FRAMEWORK, m_szWindowClass, MAX_LOADSTRING);

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style =
		CS_HREDRAW		//Ŭ���̾�Ʈ�� ���̸� �����ϸ� �ٽ� �׸����� �մϴ�. 
		| CS_VREDRAW	//Ŭ���̾�Ʈ�� ���̸� �����ϸ� �ٽ� �׸����� �մϴ�.
		| CS_DBLCLKS	//�ش� �������α׷��� ���� Ŭ���� �����ϵ��� �մϴ�.
		;
	wcex.lpfnWndProc = StaticWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FRAMEWORK));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  //������ ������ �����Ѵٸ� �ڵ����� ����Ƿη� �մϴ�.
	wcex.lpszMenuName = nullptr; // MAKEINTRESOURCEW(IDC_FRAMEWORK);
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL CGameApp::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	m_hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	// ������ �������� ������ �������ݴϴ�.
	DWORD dwStyle =
		WS_OVERLAPPED	  //����Ʈ ������.Ÿ��Ʋ �ٿ� ũ�� ������ �ȵǴ� ��輱�� ���� �����츦 ����ϴ�.
		| WS_SYSMENU	  //�ý��� �޴��� ���� �����츦 ����ϴ�.
		| WS_MINIMIZEBOX  //�ּ�ȭ ��ư�� ���� �����츦 ����ϴ�.
		| WS_CAPTION	  //Ÿ��Ʋ �ٸ� ���� �����츦 ����� WS_BORDER ��Ÿ���� �����մϴ�.
		//  | WS_BORDER		  //�ܼ����� �� ��輱(ũ�� ���� �Ұ���)�� ����ϴ�.
		//  | WS_CLIPCHILDREN //���ϵ尡 ��ġ�� ������ �׸��� �ʽ��ϴ�.
		//  | WS_CLIPSIBLINGS //���ϵ峢�� ��ȣ ��ģ ������ �׸��� �������� �����մϴ�.
		//	| WS_CLIPCHILDREN //���ϵ尡 ��ġ�� ������ �׸��� �ʽ��ϴ�.
		//	| WS_CLIPSIBLINGS //���ϵ峢�� ��ȣ ��ģ ������ �׸��� �������� �����մϴ�.
		;

	RECT rtClient, rtDesktop;

	// �����찡 ������ ��ġ�� ȭ���� �߰��� �ǵ��� �մϴ�.
	GetWindowRect(GetDesktopWindow(), &rtDesktop); 

	// Ŭ���̾�Ʈ�� ũ�⸦ �����մϴ�.
	rtClient.left = rtClient.top = 0;
	rtClient.right = CLIENT_WIDTH;
	rtClient.bottom = CLIENT_HEIGHT;

	// ������ ������� �߰��Ǵ� ũ��� (ĸ��, �ܰ��� ��)�� �����մϴ�.
	AdjustWindowRect(&rtClient, dwStyle, FALSE);

	//Ŭ���̾�Ʈ�� ������ ��ǥ�� ����ũ���� �߾��� �ǵ��� �����մϴ�.
	POINT ptClientPos;

	ptClientPos.x = (rtDesktop.right - rtClient.right) * 0.5f;
	ptClientPos.y = (rtDesktop.bottom - rtClient.bottom) * 0.5f;

	m_hWnd = CreateWindowW(
		m_szWindowClass,	//������ Ŭ���� ��
		m_szTitle,			//Ÿ��Ʋ�� �Էµ� ���ڿ�
		dwStyle,			//������ ��Ÿ��
		ptClientPos.x,		//���� ���α׷��� ���۵� x��ǥ
		ptClientPos.y,		//���� ���α׷��� ���۵� y��ǥ
		rtClient.right  - rtClient.left,//���� ���α׷��� ���� ����
		rtClient.bottom - rtClient.top, //���� ���α׷��� ���� ���� 
		nullptr,			//�θ� ������
		nullptr,			//�޴� �ڵ�
		hInstance,			//�ν��Ͻ� �ڵ� 
		nullptr				//�߰� �Ķ����
	);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return TRUE;
}

void CGameApp::FrameAdvance()
{
	ProcessInput(nullptr);

	Update();

	Draw();
}

void CGameApp::Update(float timeElpased)
{
}

void CGameApp::Draw(float timeElpased)
{
	HDC backDC = m_backBuffer->GetBuffer();
	GetClientRect(m_hWnd, &m_rtClientSize);

	m_backBuffer->Reset();

	TextOut(backDC, 50, 100, TEXT("Ȯ��"), lstrlen(TEXT("Ȯ��")));
	
	m_backBuffer->Present();
}

void CGameApp::ProcessInput(CInput * input)
{
}

void CGameApp::ShutDown()
{
	ReleaseObjects();

	if (m_hWnd) DestroyWindow(m_hWnd);
}

LRESULT CGameApp::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// return CGameApp::Get()->ProcessWndProc(hWnd, message, wParam, lParam);
	// �� �ڵ�� �Ʒ� �ڵ�� ���� ����� �����մϴ�.
	return instance->ProcessWndProc(hWnd, message, wParam, lParam);
}

LRESULT CGameApp::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void CGameApp::BuildObjects()
{
	GetClientRect(m_hWnd, &m_rtClientSize);
	m_backBuffer = new CBackBuffer(m_hWnd, m_rtClientSize);
}

void CGameApp::ReleaseObjects()
{
	SAFE_DELETE(m_backBuffer);
}
