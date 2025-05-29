// UsingCOM.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CoCreateInstanceExample.h"
#include "ManualFactoryExample.h"

#define USE_FACTORY

int main()
{
#ifdef USE_FACTORY
    Run_ManualFactory_Example();
#else 
    Run_CoCreateInstance_Example();
#endif // USE_FACTORY
}
