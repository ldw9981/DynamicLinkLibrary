#pragma once
#include "IMyCOM.h"


class MyCOMObject : public IMyCOMObject2 {
	ULONG m_refCount = 1;
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
		if (riid == IID_IUnknown || riid == IID_IMyCOMObject) {
			*ppv = static_cast<IMyCOMObject*>(this);
			AddRef();
			return S_OK;
		}
		*ppv = nullptr;
		return E_NOINTERFACE;
	}
	ULONG STDMETHODCALLTYPE AddRef() override { return ++m_refCount; }
	ULONG STDMETHODCALLTYPE Release() override {
		if (--m_refCount == 0) { delete this; return 0; }
		return m_refCount;
	}
	void Hello() override {
		std::cout << "Hello from MyCOMObject!" << std::endl;
	}
	void Bye() override {
		std::cout << "Bye from MyCOMObject!" << std::endl;
	}
};
