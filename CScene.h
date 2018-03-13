#pragma once

/*
작성일 : 2018-03-13
설명 : 프로그램 논리에 의한 작업공간이 될 여러 Scene들의 상위 클래스입니다.
*/

class CInput;

enum class SceneType
{
	TITLE = 0,
	MAIN = 11,
};

class CScene
{
public:
	virtual ~CScene();
	
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void ProcessInput(CInput *input) = 0;
	
	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	
	// 해당 함수를 통해서 새로운 씬을 생성할 수 있도록 합니다.
	template <class SceneName>
	static CScene* NewScene()
	{
		CScene *scene = new SceneName;
		
		//필요한 초기화가 있다면 이 지점에서 호출할 수 있도록 합니다.

		return scene;
	}
protected:
	// NewScene함수로만 Scene을 생성하도록 강제합니다.
	CScene() {}
};