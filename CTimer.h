#pragma once

/*
작성일 : 2018-03-12
설명 : chrono함수를 이용하여 이전 함수 호출 시간과 
       이번 함수 호출 시간까지의 차이를 계산하는 기능을 제공합니다.
*/


class CTimer
{
public:
	CTimer();
	virtual ~CTimer();

	// 이전 함수 호출 시간과 현재 함수 호출 시간 갱신합니다.
	virtual void Tick() {
		m_curTime = chrono::system_clock::now(); 
		m_timeElapsed = m_curTime - m_prevTime;
		m_prevTime = m_curTime;
		m_timeLag += m_timeElapsed.count();
	}

	// 이전 함수 호출 시간과 현재 함수 호출 시간 사이의 차이를 계산하여 반환합니다.
	double GetTimeLag() const { return m_timeLag; }					// update에서 변화함
	double GetTimeElapsed() const { return m_timeElapsed.count(); }	// update에서 변화안함

	void UpdateTimeLag(double timeLag) { m_timeLag += timeLag; }

private:
	chrono::system_clock::time_point m_curTime;
	chrono::system_clock::time_point m_prevTime;
	chrono::duration<double> m_timeElapsed;
	double m_timeLag;
};

/*
작성일 : 2018-03-13
설명 : CTimer클래스를 상속받아 부모클래스의 기본 기능을 제공하고
	   추가적으로 FPS를 계산하는 기능을 제공합니다.
*/
class CFPSTimer : public CTimer
{
public:
	CFPSTimer();
	
	//virtual void Tick() override final { CTimer::Tick(); m_prevFPSTime = chrono::system_clock::now(); }

	double GetFrameRate();
	
private:
	// FPS를 갱신합니다.
	void Update();

	chrono::system_clock::time_point m_prevFPSTime;
	chrono::duration<double> m_FPSTimeElapsed;

	double m_timeSum;
	int m_nSumCount;

	double m_fps;
};

