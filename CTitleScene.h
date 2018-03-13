#pragma once
#include "CScene.h"

/*
�ۼ��� : 2018-03-13
���� : Ÿ��Ʋ Scene�Դϴ�. 
	   �����ϰ� ȭ�鿡 CTitleScene�� ����ϰ� 
	   ����ϴ� �ؽ�Ʈ�� ��ġ�� �¿��� ��� �����̵��� �Ͽ�����
	   �����̽��ٸ� ������ MainScene���� ��ȯ�մϴ�.
*/

class CTitleScene :
	public CScene
{
public:
	CTitleScene();
	~CTitleScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int m_textPosX;
	int m_textPosY;

	bool m_isMoveRight;

	WCHAR *m_text;
	USHORT m_textLen;
};

