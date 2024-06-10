#pragma once

#include "Shader.h"

class ShaderManager
{
	DECLARE_SINGLE(ShaderManager);

private:
	ID3D11Device* _pd3dDevice = nullptr;
	ID3D11DeviceContext* _pImmediateContext = nullptr;

	std::map<std::wstring, Shader*> _shaders;
	
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

	// ���̴� ���� �ε�
	Shader* Load(std::wstring shaderFile);
};

