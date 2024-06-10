#pragma once

#include "Shader.h"
#include "Texture.h"

class Object
{
protected:
	ID3D11Device* _pd3dDevice = nullptr;
	ID3D11DeviceContext* _pImmediateContext = nullptr;

	std::vector<Vertex> _vertices;
	std::vector<DWORD> _indices;
	ID3D11Buffer* _pVertexBuffer = nullptr;
	ID3D11Buffer* _pIndexBuffer = nullptr;
	ID3D11InputLayout* _pInputLayout = nullptr;

	Texture* _pTexture = nullptr;
	Shader* _pShader = nullptr;
	ID3D11VertexShader* _pVertexShader = nullptr;
	ID3D11PixelShader* _pPixelShader = nullptr;
	ID3DBlob* _pVertexShaderCode = nullptr;
	ID3DBlob* _pPixelShaderCode = nullptr;

public:
	// �ʱ�ȭ
	virtual HRESULT Init();
	// ������ ���
	virtual HRESULT Frame();
	// ����
	virtual HRESULT PreRender();
	virtual HRESULT Render();
	virtual HRESULT PostRender();
	// �޸� ����
	virtual HRESULT Release();

	// ����̽� ����
	HRESULT SetDevice(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext);

	// ������Ʈ ����
	HRESULT CreateObject(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext, std::wstring shaderFile, std::wstring textureFile);

	// ���� ������ ����
	void CreateVertexData();
	// ���� ���� ����
	HRESULT CreateVertexBuffer();
	// �ε��� ������ ����
	void CreateIndexData();
	// �ε��� ���� ����
	HRESULT CreateIndexBuffer();
	// ���̴� ����
	HRESULT CreateShader(std::wstring shaderFile);
	// �Է� ���̾ƿ� ����
	HRESULT CreateInputLayout();
	// �ؽ�ó ����
	HRESULT CreateTexture(std::wstring textureFile);
};

