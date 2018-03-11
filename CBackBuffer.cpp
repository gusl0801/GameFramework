#include "stdafx.h"
#include "CBackBuffer.h"

#define ERASE_COLOR RGB(255,255,255)

CBackBuffer::CBackBuffer(HWND hWnd, const RECT &rtClientSize)
	:m_hWnd(hWnd), m_rtClientSize(rtClientSize)
{
	m_hBrush = CreateSolidBrush(ERASE_COLOR);

	HDC hdc = ::GetDC(hWnd);

	m_hDC = CreateCompatibleDC(hdc);
	m_hBmp = CreateCompatibleBitmap(hdc, rtClientSize.right, rtClientSize.bottom);
	SelectObject(m_hDC, m_hBmp);
	
	DeleteDC(hdc);
}


CBackBuffer::~CBackBuffer()
{
	if (m_hBrush) DeleteObject(m_hBrush);
	if (m_hBmp) DeleteObject(m_hBmp);
	if (m_hDC) DeleteDC(m_hDC);
}

void CBackBuffer::Present()
{
	HDC hdc = ::GetDC(m_hWnd);

	BitBlt(hdc, 0, 0, m_rtClientSize.right, m_rtClientSize.bottom,
		m_hDC, 0, 0, SRCCOPY);

	DeleteDC(hdc);
}
