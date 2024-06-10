#pragma once

#include "Sprite.h"

class SpriteManager
{
	DECLARE_SINGLE(SpriteManager);

public:
    ID3D11Device* _pd3dDevice = nullptr;
    ID3D11DeviceContext* _pImmediateContext = nullptr;
    std::vector<W_STR>  filelist;
    std::vector<UINT>  m_iSpriteTypeList;
    std::vector<W_STR> m_rtNameList;
    std::vector<W_STR> m_TextureNameList;
    std::vector<W_STR> m_MaskTextureNameList;
    std::vector<W_STR> m_ShaderNameList;
    std::vector<std::vector<RECT>> m_rtSpriteList;
    std::vector<TCHAR_STRING_VECTOR> m_szSpriteList;
    std::map<std::wstring, Sprite*> m_List;

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

    HRESULT GameDataLoad(const TCHAR* spriteFile);
    HRESULT Load(std::wstring name);
    Sprite* Find(std::wstring name);

    Sprite& Get(W_STR str);
    Sprite* GetPtr(W_STR str);
};

