#include "stdafx.h"
#include "CTitleScene.h"
#include "CGameApp.h"
#include "CMainScene.h"

CTitleScene::CTitleScene()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_textPosX = viewport.right * 0.5;
	m_textPosY = viewport.bottom * 0.5f;

	m_isMoveRight = false;

	m_text = TEXT("CTitleScene");
	m_textLen = lstrlen(m_text);

	m_textPosX -= m_textLen;
	m_textPosY -= 20;
}


CTitleScene::~CTitleScene()
{
}

void CTitleScene::Update()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	if (m_isMoveRight)
	{
		m_textPosX += 5;
		if (m_textPosX + m_textLen * 5 >= viewport.right)
			m_isMoveRight = false;
	}
	else
	{
		m_textPosX -= 5;
		if (m_textPosX <= viewport.left)
			m_isMoveRight = true;
	}
}

void CTitleScene::Draw(HDC hdc)
{
	TextOut(hdc, m_textPosX, m_textPosY, m_text, m_textLen);
}

void CTitleScene::ProcessInput(CInput * input)
{
}

LRESULT CTitleScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
			CGameApp::Get()->ChangeScene(CScene::NewScene<CMainScene>());
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
