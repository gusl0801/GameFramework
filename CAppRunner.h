#pragma once

/*
작성일 : 2018-03-09
설명   : CGameApp클래스의 윈도우 초기화 및 생성, 작업 처리 
		 함수들을 순서에 맞게 호출할 수 있도록 제어하는 클래스입니다.
*/
#include "CGameApp.h"

class CAppRunner
{
public:
	CAppRunner(CGameApp *app);
	~CAppRunner();

	bool Init(HINSTANCE hInst, int nCmdShow);
	int Run();

private:
	CGameApp *m_app;
};

