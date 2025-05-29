#include "pch.h"
#include "MyFactory.h"
#include "MyCOMObject.h"
#include "OtherObject.h"

HRESULT MyFactory2::CreateInstance(IMyCOMObject** ppObj)
{
	if (!ppObj) return E_POINTER;
	*ppObj = new MyCOMObject();
	return S_OK;
}

HRESULT MyFactory2::CreateOther(IOtherObject** ppObj)
{
	if (!ppObj) return E_POINTER;
	*ppObj = new OtherObject();
	return S_OK;
}
