#include "stdafx.h"
#include "CTimer.h"

#define FPS_UPDATE_LIMIT 0.5

CTimer::CTimer()
{
	m_curTime = chrono::system_clock::now();
	m_prevTime = chrono::system_clock::now();
}


CTimer::~CTimer()
{
}

CFPSTimer::CFPSTimer()
{
	m_prevFPSTime = chrono::system_clock::now();
	m_timeSum = 0;
	m_fps = 0;
	m_nSumCount = 0;
}

double CFPSTimer::GetFrameRate()
{
	// 지정된 시간이 경과 했다면
	if (m_FPSTimeElapsed.count() > FPS_UPDATE_LIMIT)
	{
		// fps 갱신
		Update();
	}
	else // 경과 하지 않았다면
	{
		// 경과 시간 갱신
		m_FPSTimeElapsed = std::chrono::system_clock::now() - m_prevFPSTime;

		m_timeSum += GetTimeElapsed();
		++m_nSumCount;
	}
	return m_fps;
}

void CFPSTimer::Update()
{
	m_fps = 1.0f / (m_timeSum / m_nSumCount);
	m_timeSum = 0;
	m_nSumCount = 0;

	m_prevFPSTime = std::chrono::system_clock::now();
	m_FPSTimeElapsed = m_prevFPSTime - m_prevFPSTime;
}
