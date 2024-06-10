#pragma once

#include "Scene.h"

class InGame : public Scene
{
public:
	uint64 _netTimer1;
	uint64 _netTimer2;
	uint64 _netTimer3;
	uint64 _netTimer4;
	uint64 _playerTimer;
	uint64 _enemyTimer;

	// �ʱ�ȭ
	virtual HRESULT Init() override;
	// ������ ���
	virtual HRESULT Frame() override;
	// ����
	virtual HRESULT Render() override;
	// �޸� ����
	virtual HRESULT Release() override;
};

