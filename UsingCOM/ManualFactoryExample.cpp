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
	// 인터페이스 포인터를 다루는 스마트 포인터
	// 변수가 파괴될때 클래스 내부에서 인터페이스의 Release를 호출한다.
	ComPtr<IMyFactory2> myFactory;
	ComPtr<IMyCOMObject2> myCOMObject;
	ComPtr<IOtherObject> otherObject;
	
	CreateMyFactory(__uuidof(myFactory), // 팩토리의 인터페이스 ID
		(void**)myFactory.GetAddressOf()); // 인터페이스 포인터를 저장할 변수
	
	// 팩토리와 1:1로 연결되는 COM객체
	myFactory->CreateInstance(nullptr,
		__uuidof(myCOMObject), // COM객체를 형변환하여 사용할 인터페이스 ID
		(void**)myCOMObject.GetAddressOf()); // 인터페이스 포인터를 저장할 변수

	// COM객체의 사용
	myCOMObject->Hello();
	myCOMObject->Bye();

	// 팩토리가 부가적으로 생성한 COM객체
	myFactory->CreateOther(otherObject.GetAddressOf());
	// COM객체의 사용
	otherObject->Say();	
}
