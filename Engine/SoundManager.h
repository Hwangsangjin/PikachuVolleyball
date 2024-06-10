#pragma once

#include "Sound.h"

class SoundManager
{
    DECLARE_SINGLE(SoundManager);

public:
    FMOD::System* _pSystem = nullptr;
    std::list<std::wstring> _files;
    std::map<std::wstring, Sound*> _sounds;

public:
    // �ʱ�ȭ
    HRESULT Init();
    // ������ ���
    HRESULT Frame();
    // ����
    HRESULT Render();
    // �޸� ����
    HRESULT Release();

    Sound* Load(std::wstring filename);
    void LoadDir(std::wstring path);
    void LoadAll(std::wstring path);

    Sound* GetPtr(W_STR name);
    T_STR GetSplitName(std::wstring filename);
};

