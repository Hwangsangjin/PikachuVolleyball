#pragma once

class DxState
{
public:
	static ID3D11SamplerState* _pDefaultSamplerState;

	// �ʱ�ȭ
	HRESULT Init();
	// ������ ���
	HRESULT Frame();
	// ����
	HRESULT Render();
	// �޸� ����
	static HRESULT Release();

	// ���÷� ����
	static HRESULT SetSamplerState(ID3D11Device* pd3dDevice);
};

