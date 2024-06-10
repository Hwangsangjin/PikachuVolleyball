#include "pch.h"
#include "Device.h"

// �ʱ�ȭ
HRESULT Device::Init()
{
    HR(CreateDevice());
    HR(CreateFactory());
    HR(CreateSwapChain());
    HR(CreateRenderTargetView());
    HR(CreateViewport());

    return TRUE;
}

// ������
HRESULT Device::Frame()
{
    return TRUE;
}

// ����
HRESULT Device::Render()
{
    return TRUE;
}

// ������
HRESULT Device::Release()
{
    SAFE_CLEARSTATE(_pImmediateContext);
    SAFE_RELEASE(_pRenderTargetView);
    SAFE_RELEASE(_pSwapChain);
    SAFE_RELEASE(_pFactory);
    SAFE_RELEASE(_pImmediateContext);
    SAFE_RELEASE(_pd3dDevice);

    return TRUE;
}

// ����̽�
HRESULT Device::CreateDevice()
{
    UINT createDeviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 

    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
    };
    UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
        _driverType = driverTypes[driverTypeIndex];
        HRESULT hr = D3D11CreateDevice(NULL, _driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &_pd3dDevice, &_featureLevel, &_pImmediateContext);

        if (SUCCEEDED(hr))
        {
            break;
        }
    }

    return TRUE;
}

// ���丮
HRESULT Device::CreateFactory()
{
    HR(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&_pFactory));

    return TRUE;
}

// ����ü��
HRESULT Device::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = rtClient.right;
    sd.BufferDesc.Height = rtClient.bottom;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.Windowed = true;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    HR(_pFactory->CreateSwapChain(_pd3dDevice, &sd, &_pSwapChain));

    return TRUE;
}

// ����Ÿ�ٺ�
HRESULT Device::CreateRenderTargetView()
{
    ID3D11Texture2D* pBackBuffer = nullptr;
    _pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
    HR(_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &_pRenderTargetView));
    pBackBuffer->Release();

    return TRUE;
}

// ����Ʈ
HRESULT Device::CreateViewport()
{
    D3D11_VIEWPORT vp;
    vp.Width = rtClient.right;
    vp.Height = rtClient.bottom;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    _pImmediateContext->RSSetViewports(1, &vp);

    return TRUE;
}

HRESULT Device::ResizeDevice(UINT width, UINT height)
{
    // ����̽��� �������� ���� ���
    if (_pd3dDevice == nullptr) return TRUE;

    // ����Ÿ�ٰ� ����Ÿ�ٺ並 �����Ѵ�.
    _pImmediateContext->OMSetRenderTargets(0, nullptr, nullptr);
    SAFE_RELEASE(_pRenderTargetView);

    // �ĸ� ������ ũ�⸦ �����Ѵ�.
    DXGI_SWAP_CHAIN_DESC current, after;
    _pSwapChain->GetDesc(&current);
    _pSwapChain->ResizeBuffers(current.BufferCount, width, height, current.BufferDesc.Format, 0);

    // ����� �ĸ� ������ ũ�⸦ ��´�.
    _pSwapChain->GetDesc(&after);
    GetClientRect(hWnd, &rtClient);
    rtClient.right = after.BufferDesc.Width;
    rtClient.bottom = after.BufferDesc.Height;

    // ����Ÿ�ٺ並 �����ϰ� �����Ѵ�.
    HR(CreateRenderTargetView());

    // ����Ʈ�� �����ϰ� �����Ѵ�.
    HR(CreateViewport());

    return TRUE;
}
