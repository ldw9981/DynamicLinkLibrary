#include "ManualFactoryExample.h"


#include <windows.h>
#include "../MyCOMLib/IMyCOM.h"

#include <wrl.h>	// ComPtr
using namespace Microsoft::WRL;

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/MyCOMLib.lib")
#else
#pragma comment(lib, "../x64/Release/MyCOMLib.lib")
#endif


void Run_ManualFactory_Example()
{	
	ComPtr<IMyFactory2> myFactory;
	ComPtr<IMyCOMObject2> myCOMObject;
	ComPtr<IOtherObject> otherObject;
	
	CreateMyFactory(IID_IMyFactory2, (void**)myFactory.GetAddressOf());
	myFactory->CreateInstance(nullptr, IID_IMyCOMObject2, (void**)myCOMObject.GetAddressOf());
	myCOMObject->Hello();
	myCOMObject->Bye();

	myFactory->CreateOther(otherObject.GetAddressOf());
	otherObject->Say();	
}
