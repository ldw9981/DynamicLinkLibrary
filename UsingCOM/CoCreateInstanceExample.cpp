#include "CoCreateInstanceExample.h"

#include "../MyCOMLib/IMyCOM.h"
#include <windows.h>

void Run_CoCreateInstance_Example()
{
	CoInitialize(nullptr);
	IMyCOMObject2* p = nullptr;
	// COM ���̺귯���� ����ϱ����� �ʿ��Ѱ� 
	// 1. ������Ʈ���� ��ϵ� ClassID (DLL��ġ�� �����) 
	// 2. ���̺귯�� Ŭ������ �ν��Ͻ��� ����ϱ����� �������̽�
	HRESULT hr = CoCreateInstance(CLSID_MyCOMObject, 
		nullptr, CLSCTX_INPROC_SERVER, __uuidof(IMyCOMObject2), (void**)&p);
	if (SUCCEEDED(hr)) {
		p->Hello();
		p->Bye();
		p->Release();
	}
	CoUninitialize();
}
