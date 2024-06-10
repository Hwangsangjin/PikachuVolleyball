#include "pch.h"
#include "Enemy.h"
#include "Input.h"
#include "Timer.h"
#include "SpriteManager.h"

HRESULT Enemy::Frame()
{
    const float offsetX = 15.0f;
    Vector2 normal{ 1.0f, 1.0f };
    normal.Normalize();

    // ������ ó�� �ӵ�
    float jumpSpeed = -800.0f;

    // ������ ���ӵ�
    float jumpAccel = 1.0f;

    // �׶��忡 ���� ���� Y��ǥ
    // ���� ������ ����Ѵ�.
    float groundY = 485.0f;

    // ������ũ ������ ����ϴ� ��Ʈ�� ����
    const float netY = 400.0f;

    // ���� ������ ó��
    // isJump�� ���� ���¸� ǥ���ϴ� �÷���
    // true�� ���� ���� ����, false�� ���� ������ ���¸� ��Ÿ����.
    if (!_isJump)
    {
        // ��ư�� ������ ���� ���·� ����
        // ���� ������ �÷��׿� �ʼ�(ó�� �ӵ�)�� �����Ѵ�.
        // VY�� ĳ������ Y�� ������ �ӵ�
        if (INPUT->GetKey(VK_UP) == KEY_STATE::DOWN)
        {
            _velocity.y = jumpSpeed;
            _pSprite = SPRITE->GetPtr(L"rtEnemyToss");
            _isJump = true;
        }
    }
    // ���� ������ ó��
    else
    {
        if (_position.y <= netY && INPUT->GetKey(VK_RETURN) == KEY_STATE::DOWN)
        {
            _pSprite = SPRITE->GetPtr(L"rtEnemySpike");
            _isSpike = true;
        }

        // Y�� ������ �ӵ��� ���ӵ��� �߰��Ѵ�.
        _velocity.y += jumpAccel;

        // Y��ǥ ����
        _position.y += _velocity.y * DELTA_TIME;
        if (_position.y <= 200.0f)
        {
            _position.y = 200.0f;
        }

        // ���� ����
        // ĳ���Ͱ� ���� ���̸�(Y�� ������ �ӵ��� ���)
        // ĳ���Ͱ� ���鿡 ���� ���� Y��ǥ�� �����ϸ�
        // �����ߴٰ� �����Ѵ�.
        // ���� ������ �÷��׸� false�� �Ͽ� ���� ���·� �ǵ��ư�
        // Y��ǥ�� ���鿡 ���� ���� ��ǥ�� �����Ѵ�.
        if (_velocity.y > 0 && _position.y >= groundY)
        {
            _isJump = false;
            _isSpike = false;
            _position.y = groundY;
            _pSprite = SPRITE->GetPtr(L"rtEnemyRun");
        }
    }

    // ��
    if (INPUT->GetKey(VK_LEFT))
    {
        _position.x -= normal.x * _speed * DELTA_TIME;
        if (_position.x + _rect.w - offsetX <= RESOLUTION_X / HALF)
        {
            _position.x = RESOLUTION_X / HALF - _rect.w + offsetX;
        }
    }

    if (!_isDig)
    {
        if (_position.y >= groundY && INPUT->GetKey(VK_LEFT) && INPUT->GetKey(VK_SPACE) == KEY_STATE::DOWN)
        {
            _position.x -= normal.x * _speed * DELTA_TIME;
            if (_position.x + _rect.w - offsetX <= RESOLUTION_X / HALF)
            {
                _position.x = RESOLUTION_X / HALF - _rect.w + offsetX;
            }

            _pSprite = SPRITE->GetPtr(L"rtEnemyRightDig");
            _isDig = true;
        }
    }

    // ��
    if (INPUT->GetKey(VK_RIGHT))
    {
        _position.x += normal.x * _speed * DELTA_TIME;
        if (_position.x - _rect.w >= RESOLUTION_X)
        {
            _position.x = RESOLUTION_X + _rect.w;
        }
    }

    if (!_isDig)
    {
        if (_position.y >= groundY && INPUT->GetKey(VK_RIGHT) && INPUT->GetKey(VK_SPACE) == KEY_STATE::DOWN)
        {
            _position.x += normal.x * _speed * DELTA_TIME;
            if (_position.x - _rect.w >= RESOLUTION_X)
            {
                _position.x = RESOLUTION_X + _rect.w;
            }

            _pSprite = SPRITE->GetPtr(L"rtEnemyRightDig");
            _isDig = true;
        }
    }

    // ��������Ʈ
    _spriteTimer += DELTA_TIME;
    _spriteMaxIndex = _pSprite->_uvs.size();
    _spriteStep = 1.0f / _spriteMaxIndex;

    if (_spriteStep <= _spriteTimer)
    {
        _spriteTimer -= _spriteStep;
        _spriteIndex++;
    }

    if (_spriteIndex >= _spriteMaxIndex)
    {
        if (_isDig)
        {
            _pSprite = SPRITE->GetPtr(L"rtEnemyRun");
            _isDig = false;
        }
        else if (_isWin)
        {
            _pSprite = SPRITE->GetPtr(L"rtEnemyWin");
        }
        else if (_isLose)
        {
            _pSprite = SPRITE->GetPtr(L"rtEnemyLose");
        }

        _spriteIndex = 0;
    }

    RECT rect = _pSprite->_uvs[_spriteIndex];
    _rect.x1 = rect.left;
    _rect.y1 = rect.top;
    _rect.w = rect.right;
    _rect.h = rect.bottom;

    SetRect(_rect);
    SetPosition(_position);

	return TRUE;
}

bool Enemy::IsSpike()
{
    return _isSpike;
}

bool Enemy::IsJump()
{
    return _isJump;
}

bool Enemy::IsDig()
{
    return _isDig;
}
