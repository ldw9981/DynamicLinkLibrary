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
	// �������̽� �����͸� �ٷ�� ����Ʈ ������
	// ������ �ı��ɶ� Ŭ���� ���ο��� �������̽��� Release�� ȣ���Ѵ�.
	ComPtr<IMyFactory2> myFactory;
	ComPtr<IMyCOMObject2> myCOMObject;
	ComPtr<IOtherObject> otherObject;
	
	CreateMyFactory(__uuidof(myFactory), // ���丮�� �������̽� ID
		(void**)myFactory.GetAddressOf()); // �������̽� �����͸� ������ ����
	
	// ���丮�� 1:1�� ����Ǵ� COM��ü
	myFactory->CreateInstance(nullptr,
		__uuidof(myCOMObject), // COM��ü�� ����ȯ�Ͽ� ����� �������̽� ID
		(void**)myCOMObject.GetAddressOf()); // �������̽� �����͸� ������ ����

	// COM��ü�� ���
	myCOMObject->Hello();
	myCOMObject->Bye();

	// ���丮�� �ΰ������� ������ COM��ü
	myFactory->CreateOther(otherObject.GetAddressOf());
	// COM��ü�� ���
	otherObject->Say();	
}
