#pragma once

class Font
{
private:
	ID2D1Factory* _pd2dFactory = nullptr;
	IDWriteFactory* _pWriteFactory = nullptr;
	ID2D1RenderTarget* _pd2dRenderTarget = nullptr;
	IDWriteTextFormat* _pTextFormat = nullptr;
	IDWriteTextLayout* _pTextLayout = nullptr;
	ID2D1SolidColorBrush* _pTextColor = nullptr;

	std::wstring _text = L"KGCA Game Academy";

public:
	// �ʱ�ȭ
	HRESULT Init();
	// ������ ���
	HRESULT Frame();
	// ����
	HRESULT Render();
	// �޸� ����
	HRESULT Release();

	// ����
	HRESULT SetSurface(IDXGISurface1* pDXGISurface1);
	// �׸���
	HRESULT Draw(float x, float y, std::wstring text, D2D1_COLOR_F color = { 0, 0, 0, 1 });
	// �ؽ�Ʈ
	void SetText(std::wstring text);
};

