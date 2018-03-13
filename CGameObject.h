#pragma once

#include "CAnimation.h"
#include "Vector2D.h"

class CState;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// 상속받는 클래스에서 오버라이딩이 필요한 함수들
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;

	virtual void ProcessCommand() = 0;

	virtual bool IsDelete() = 0;

	// 상속받는 클래스에서 오버라이딩 할 필요가 없는 함수들	
	CState* GetState() const { return m_curState; }

	void ChangeSprite(AnimationState state) { m_renderer->ChangeState(state); }

private:
	Vector2i m_position;

	CState *m_curState;
	queue<CState*> m_stateQueue;

	CAnimation *m_renderer;
};

