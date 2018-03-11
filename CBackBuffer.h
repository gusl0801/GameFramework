#pragma once

class CBackBuffer
{
public:
	CBackBuffer(HWND hWnd, const RECT &rtClientSize);
	~CBackBuffer();

	HDC GetBuffer() const { return m_hDC; }
	void Reset(){ FillRect(m_hDC, &m_rtClientSize, m_hBrush); }
	void Resize(const RECT &rtClientSize) { m_rtClientSize = rtClientSize; }

	// 현재까지 DC에 그려진 내용을 주DC로 옮깁니다.
	void Present();

private:
	// 복사생성과 대입연산을 금지합니다
	CBackBuffer(const CBackBuffer &other) = delete;
	CBackBuffer& operator=(const CBackBuffer &other) = delete;

	HWND m_hWnd;
	HDC m_hDC;
	HBITMAP m_hBmp;
	HBRUSH m_hBrush;

	RECT m_rtClientSize;
};

