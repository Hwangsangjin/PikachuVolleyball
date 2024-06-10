#pragma once
class Texture
{
private:
	ID3D11Device* _pd3dDevice = nullptr;
	ID3D11DeviceContext* _pImmediateContext = nullptr;
	ID3D11Texture2D* _pTexture2D = nullptr;

public:
	D3D11_TEXTURE2D_DESC _desc;
	ID3D11ShaderResourceView* _pShaderResourceView = nullptr;

	// �ʱ�ȭ
	HRESULT Init();
	// ������ ���
	HRESULT Frame();
	// ����
	HRESULT Render();
	// �޸� ����
	HRESULT Release();

	// ����̽� ����
	void SetDevice(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext);

	// �ؽ�ó ����
	HRESULT CreateTexture(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext, std::wstring texturefile);
};

