#pragma once
#include "CScene.h"

/*
작성일 : 2018-03-13
설명 : 타이틀 Scene입니다. 
	   간단하게 화면에 CTitleScene을 출력하고 
	   출력하는 텍스트의 위치를 좌에서 우로 움직이도록 하였으며
	   스페이스바를 누르면 MainScene으로 전환합니다.
*/

class CTitleScene :
	public CScene
{
public:
	CTitleScene();
	~CTitleScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int m_textPosX;
	int m_textPosY;

	bool m_isMoveRight;

	WCHAR *m_text;
	USHORT m_textLen;
};

