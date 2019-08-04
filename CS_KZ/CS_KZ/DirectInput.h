#pragma once
#include <Windows.h>

namespace DirectInput
{
	HRESULT Initialize();

	UINT SendInput(UINT32 aCount, LPINPUT aInputs, UINT32 aBytes);
}
