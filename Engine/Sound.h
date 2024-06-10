#pragma once

class Sound
{
public:
	FMOD::System* _pSystem = nullptr;
	FMOD::Sound* _pSound = nullptr;
	FMOD::Channel* _pChannel = nullptr;
	FMOD::Channel* _pChannel2 = nullptr;

	std::wstring _name;
	std::wstring _buffer;
	UINT _totalTime;
	float _volume;

public:
	// �ʱ�ȭ
	HRESULT Init();
	// ������ ���
	HRESULT Frame();
	// ����
	HRESULT Render();
	// �޸� ����
	HRESULT Release();

	HRESULT Load(FMOD::System* pSystem, std::wstring filename);
	HRESULT PlayBGM(bool isLoop = false);
	HRESULT PlayEffect(bool isLoop = false);
	bool IsPlaying();
	void SetLoop(bool isLoop = false);
	void Paused();
	void Stop();
	void VolumeUp(float volume = 0.1f);
	void VolumeDown(float volume = 0.1f);

	std::wstring GetName();
};

