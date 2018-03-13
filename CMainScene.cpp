#include "stdafx.h"
#include "CMainScene.h"
#include "CGameApp.h"

CMainScene::CMainScene()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_textPosX = viewport.right * 0.5;
	m_textPosY = viewport.bottom * 0.5f;

	m_isMoveDown = true;
	
	m_text = TEXT("CMainScene");
	m_textLen = lstrlen(m_text);

	m_textPosX -= m_textLen;
	m_textPosY -= 20;
}


CMainScene::~CMainScene()
{
}

void CMainScene::Update()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	if (m_isMoveDown)
	{
		m_textPosY += 5;
		if (m_textPosY + 20>= viewport.bottom)
			m_isMoveDown = false;
	}
	else
	{
		m_textPosY -= 5;
		if (m_textPosY <= viewport.top)
			m_isMoveDown = true;
	}
}

void CMainScene::Draw(HDC hdc)
{
	TextOut(hdc, m_textPosX, m_textPosY, m_text, m_textLen);
}

void CMainScene::ProcessInput(CInput * input)
{
}

LRESULT CMainScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}
