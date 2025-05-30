#include "CoCreateInstanceExample.h"

#include "../MyCOMLib/IMyCOM.h"
#include <windows.h>

void Run_CoCreateInstance_Example()
{
	CoInitialize(nullptr);
	IMyCOMObject2* p = nullptr;
	// COM 라이브러리를 사용하기위해 필요한것 
	// 1. 레지스트리에 등록된 ClassID (DLL위치가 저장됨) 
	// 2. 라이브러리 클래스의 인스턴스를 사용하기위한 인터페이스
	HRESULT hr = CoCreateInstance(CLSID_MyCOMObject, 
		nullptr, CLSCTX_INPROC_SERVER, __uuidof(IMyCOMObject2), (void**)&p);
	if (SUCCEEDED(hr)) {
		p->Hello();
		p->Bye();
		p->Release();
	}
	CoUninitialize();
}
