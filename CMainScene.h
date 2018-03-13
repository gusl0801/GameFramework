#pragma once
#include "CScene.h"

/*
작성일 : 2018-03-13
설명 : main scene입니다.
간단하게 화면에 CMainScene을 출력하고
출력하는 텍스트의 위치를 위에서 아래로 움직이도록 합니다.
*/

class CMainScene :
	public CScene
{
public:
	CMainScene();
	~CMainScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int m_textPosX;
	int m_textPosY;

	bool m_isMoveDown;

	WCHAR *m_text;
	USHORT m_textLen;
};

