// UsingCOM.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>
#include "CoCreateInstanceExample.h"
#include "ManualFactoryExample.h"



int main()
{
    HRESULT hr = CoInitialize(nullptr);

    Run_CoCreateInstance_Example();  

    Run_ManualFactory_Example();  

    CoUninitialize();
}
