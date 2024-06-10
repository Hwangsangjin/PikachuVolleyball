#pragma once

#include "Texture.h"

class TextureManager
{
	DECLARE_SINGLE(TextureManager);

private:
	ID3D11Device* _pd3dDevice = nullptr;
	ID3D11DeviceContext* _pImmediateContext = nullptr;

	std::map<std::wstring, Texture*> _textures;

public:
	// �ʱ�ȭ
	HRESULT Init();
	// ������ ���
	HRESULT Frame();
	// ����
	HRESULT Render();
	// �޸� ����
	HRESULT Release();

	// ����̽� ����
	HRESULT SetDevice(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext);

	// �ؽ�ó ���� �ε�
	Texture* Load(std::wstring texturefile);
	// �ؽ�ó ���� �˻�
	Texture* Find(std::wstring texturefile);
};

