#pragma once

class CGameObject;

class CSprite
{
public:
	CSprite();
	virtual ~CSprite();

	bool LoadImage(LPCTSTR szAddress) { return m_image.Load(szAddress); }

	void Update();
	void BitBlt(HDC hdc);
	void StretchBlt(HDC hdc, double xRate, double yRate);
	void AlphaBlend(HDC hdc, std::function<CGameObject*> drawFn);

protected:
	CImage m_image;
};

