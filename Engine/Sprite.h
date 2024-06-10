#pragma once

#include "Object2D.h"

class Sprite : public Object2D
{
public:
    std::vector<RECT> _uvs;
    std::vector<W_STR> _textures;
    std::vector<Texture*> _pTextures;
    std::vector<Sprite*> _pSprites;

    // �ʱ�ȭ
    HRESULT Init();
    // ������ ���
    HRESULT Frame();
    // ����
    HRESULT Render();
    // �޸� ����
    HRESULT Release();

    // ��������Ʈ ����
    virtual HRESULT Load(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext, std::wstring name);
};

class SpriteTexture : public Sprite
{
public:
    virtual HRESULT Load(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pImmediateContext, std::wstring name);
};