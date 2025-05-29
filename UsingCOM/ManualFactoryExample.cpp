#include "ManualFactoryExample.h"


#include <windows.h>
#include "../MyCOMLib/IMyCOM.h"

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/MyCOMLib.lib")
#else
#pragma comment(lib, "../x64/Release/MyCOMLib.lib")
#endif


void Run_ManualFactory_Example()
{
	HRESULT hr = CoInitialize(nullptr);
	
	IMyFactory2* pMyFactory = nullptr;
	CreateMyFactory(IID_IMyFactory2, (void**)&pMyFactory);

	IMyCOMObject2* pMyCOMObject = nullptr;
	//pMyFactory->CreateInstance();

	IOtherObject* pOtherObject = nullptr;
	pMyFactory->CreateOther(&pOtherObject);


	pOtherObject->Say();

	
	pOtherObject->Release();
	pMyFactory->Release();

	CoUninitialize();
}
