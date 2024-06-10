#pragma once

class Timer
{
    DECLARE_SINGLE(Timer);

private: 
    uint64 _frequency = 0;
    uint64 _prevCount = 0;
    float _deltaTime = 0;

    uint32 _frameCount = 0;
    float _frameTime = 0;
    float _gameTime = 0;
    uint32 _fps = 0;

    std::wstring _text;

public:
    // �ʱ�ȭ
    HRESULT Init();
    // ������ ���
    HRESULT Frame();
    // ����
    HRESULT Render();
    // �޸� ����
    HRESULT Release();

    // �ʴ� ������ ��
    uint32 GetFPS();
    // ���� �ð�
    float GetDeltaTime();

    // �ؽ�Ʈ
    std::wstring GetText();
};

