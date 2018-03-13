#pragma once
#include "CScene.h"

/*
작성일 : 2018-03-13
설명 : nullptr확인을 하지 않기 위해서 추가적으로 정의한 null클래스로
	   별도의 기능은 수행하지 않습니다.
*/
class CNullScene :
	public CScene
{
public:
	CNullScene();
	~CNullScene();

	virtual void Update() {}
	virtual void Draw(HDC hdc) {}
	virtual void ProcessInput(CInput *input) {}

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{ return DefWindowProc(hWnd, message, wParam, lParam); }
};

