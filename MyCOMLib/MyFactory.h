#pragma once
#include "IMyCOM.h"

class MyFactory2 : public IMyFactory2 {
	ULONG m_refCount = 1;
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
		if (riid == IID_IUnknown || riid == IID_IMyFactory)
			*ppv = static_cast<IMyFactory*>(this);
		else if (riid == IID_IMyFactory2)
			*ppv = static_cast<IMyFactory2*>(this);
		else {
			*ppv = nullptr;
			return E_NOINTERFACE;
		}
		AddRef();
		return S_OK;
	}
	ULONG STDMETHODCALLTYPE AddRef() override { return ++m_refCount; }
	ULONG STDMETHODCALLTYPE Release() override {
		if (--m_refCount == 0) { delete this; return 0; }
		return m_refCount;
	}
	
	// �������� COM���α׷����� ���丮�� �ϳ��� Ŭ���� �ν��Ͻ��� �����Ѵ�.
	HRESULT CreateInstance(IMyCOMObject** ppObj) override;
	HRESULT CreateOther(IOtherObject** ppObj) override;
};

extern "C" __declspec(dllexport)
HRESULT CreateMyFactory(REFIID riid, void** ppv)
{
	if (!ppv)
		return E_POINTER;

	*ppv = nullptr;

	MyFactory2* pObj = new (std::nothrow) MyFactory2();
	if (!pObj)
		return E_OUTOFMEMORY;

	HRESULT hr = pObj->QueryInterface(riid, ppv);
	pObj->Release();  // QueryInterface�� AddRef �����Ƿ� ���⼭ 1 ����

	return hr;
}
