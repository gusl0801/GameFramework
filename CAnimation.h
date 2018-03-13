#pragma once

#include "CSprite.h"

enum class AnimationState
{
	None = 0,
	Idle = 11,
	Move = 21,
};

class CAnimation : public CSprite
{
public:
	CAnimation();
	~CAnimation();

	void ChangeState(AnimationState state) { m_state = state; }

public:
	AnimationState m_state;
};

