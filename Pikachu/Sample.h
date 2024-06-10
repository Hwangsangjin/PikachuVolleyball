#pragma once

#include "Core.h"
#include "Title.h"
#include "InGame.h"

class Sample : public Core
{
private:
	Scene* _pScene = nullptr;
	Title* _pTitle = nullptr;
	InGame* _pInGame = nullptr;

public:
	Sample() = default;
	virtual ~Sample() = default;

	// �ʱ�ȭ
	virtual HRESULT Init() override;
	// ������ ���
	virtual HRESULT Frame() override;
	// ����
	virtual HRESULT Render() override;
	// �޸� ����
	virtual HRESULT Release() override;
};

