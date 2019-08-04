#include "IO_Control.h"
#include "CRT/NtSysAPI_Func.hpp"
#include "NtHookEngine/x64detour.h"
#include<Ntddkbd.h>

HOOK_INFO info;

typedef struct  _Device_Extend
{
	DEVICE_OBJECT* Target;
}Device_Extend,*PDevice_Extend;

IO_Control *_IO_Control = nullptr;

void Unload(PDRIVER_OBJECT DriverObject)
{
	_IO_Control->Delete_IO_Control();
	delete _IO_Control;
	UnhookFunction(&info);
}

typedef
VOID
(*PSERVICE_CALLBACK_ROUTINE) (
	_In_ PVOID NormalContext,
	_In_ PVOID SystemArgument1,
	_In_ PVOID SystemArgument2,
	_Inout_ PVOID SystemArgument3
	);


VOID __stdcall mycallback( // 定义回调函数
	_In_    PDEVICE_OBJECT       DeviceObject,
	_In_    PKEYBOARD_INPUT_DATA InputDataStart,
	_In_    PKEYBOARD_INPUT_DATA InputDataEnd,
	_Inout_ PULONG               InputDataConsumed
) 
{
	for (int i = 0; i < (InputDataEnd - InputDataStart); i++) 
	{
		if (_IO_Control && _IO_Control->_Last_IRP)
		/*if (_IO_Control && _IO_Control->_Last_IRP &&
			(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 0x21 &&
			(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->Flags == KEY_MAKE)*/
		{
			if ((InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 33 ||//F
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 19 ||//R
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 45 ||//F
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 46 ||//C
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 47 ||//V
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 59 ||//F1
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 60 ||//F2
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 61 ||//F3
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 62 ||//F4
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 63 ||//F5
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 64 ||//F6
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 65 ||//F7
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 66 ||//F8
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 67 ||//F9
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 68 ||//F10
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 44 ||//Z
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 16 ||//Q
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 82 ||//0
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 79 ||//1
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 80 ||//2
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 81 ||//3
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 75 ||//4
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 76 ||//5
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 77 ||//6
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 71 ||//7
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 72 ||//8
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 73 ||//9
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 20 ||//T
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 56 ||//ALT
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 29 ||//CTRL
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 57 ||//SPEAC
				(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode == 42 )//SHIFT
			{
				DATA_IMFOMATION info;
				info.key = (InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode;
				info.flag = (InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->Flags;
				_IO_Control->PushMessage(info);
			}
		}
		/*DbgPrintEx(DPFLTR_IHVDRIVER_ID, 0, "The Scancode : %d,key %s\n", (InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->MakeCode,
			(InputDataStart + i * sizeof(KEYBOARD_INPUT_DATA))->Flags ? "Up" : "Down");*/
	}
	auto func = (PSERVICE_CALLBACK_ROUTINE)info.Bridge;
	return func(DeviceObject, InputDataStart, InputDataEnd, InputDataConsumed);
}

NTSTATUS Initialize()
{
	constexpr auto KeyboardHid = LR"(\Driver\kbdhid)";
	constexpr auto KeyboardClass = LR"(\Driver\kbdclass)";
	constexpr auto PS2Port = LR"(\Driver\i8042prt)";

	void *service_func = nullptr;

	NTSTATUS vStatus = STATUS_SUCCESS;

	PDRIVER_OBJECT vDeviceDriver = nullptr;
	PDRIVER_OBJECT vClassDriver = nullptr;
	for (;;)
	{
		auto vObjectName = UNICODE_STRING{};
		auto vDeviceName = KeyboardHid;
		auto vClassName = KeyboardClass;

		RtlInitUnicodeString(&vObjectName, vDeviceName);
		vStatus = ObReferenceObjectByName(
			&vObjectName, OBJ_CASE_INSENSITIVE,
			nullptr,
			FILE_ANY_ACCESS,
			*IoDriverObjectType,
			KernelMode,
			nullptr,
			(PVOID*)&vDeviceDriver);
		if (!NT_SUCCESS(vStatus))
		{
			if (STATUS_OBJECT_NAME_NOT_FOUND != vStatus)
			{
				break;
			}

			vDeviceName = PS2Port;
			RtlInitUnicodeString(&vObjectName, vDeviceName);
			vStatus = ObReferenceObjectByName(
				&vObjectName, OBJ_CASE_INSENSITIVE,
				nullptr,
				FILE_ANY_ACCESS,
				*IoDriverObjectType,
				KernelMode,
				nullptr,
				(PVOID*)&vDeviceDriver);
			if (!NT_SUCCESS(vStatus))
			{
				break;
			}
		}

		RtlInitUnicodeString(&vObjectName, vClassName);
		vStatus = ObReferenceObjectByName(
			&vObjectName, OBJ_CASE_INSENSITIVE,
			nullptr,
			FILE_ANY_ACCESS,
			*IoDriverObjectType,
			KernelMode,
			nullptr,
			(PVOID*)&vClassDriver);
		if (!NT_SUCCESS(vStatus))
		{
			break;
		}
		auto vClassDriverStart = (PVOID)(vClassDriver->DriverStart);
		auto vClassDriverEnd = (PVOID)((SIZE_T)vClassDriverStart + vClassDriver->DriverSize);

		vStatus = STATUS_NOT_FOUND;
		for (auto vDeviceDevice = vDeviceDriver->DeviceObject; vDeviceDevice; vDeviceDevice = vDeviceDevice->NextDevice)
		{
			auto vDeviceExtBytes = (intptr_t)vDeviceDevice->DeviceObjectExtension - (intptr_t)vDeviceDevice->DeviceExtension;
			if (vDeviceExtBytes < 0)
			{
				continue;
			}
			auto vDeviceExtPtrCount = vDeviceExtBytes / sizeof(void*) - 1;
			auto vDeviceExt = static_cast<void**>(vDeviceDevice->DeviceExtension);

			for (auto vClassDevice = vClassDriver->DeviceObject; vClassDevice; vClassDevice = vClassDevice->NextDevice)
			{
				for (auto i = 0u; i < vDeviceExtPtrCount; ++i)
				{
					if (vDeviceExt[i] == vClassDevice &&
						vDeviceExt[i + 1] > vClassDriverStart   &&
						vDeviceExt[i + 1] < vClassDriverEnd)
					{
						service_func = vDeviceExt[i + 1];
						vStatus = STATUS_SUCCESS;
						break;
					}
				}
				if (NT_SUCCESS(vStatus))
				{
					break;
				}
			}
			if (NT_SUCCESS(vStatus))
			{
				break;
			}
		}
		if (!NT_SUCCESS(vStatus))
		{
			break;
		}

		break;
	}
	if (vClassDriver)  ObDereferenceObject(vClassDriver), vClassDriver = nullptr;
	if (vDeviceDriver) ObDereferenceObject(vDeviceDriver), vDeviceDriver = nullptr;

	if (service_func)
	{
		HookFunction((ULONG_PTR)service_func, (ULONG_PTR)mycallback, &info);
	}
	return vStatus;
}



extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING  RegistryPath)
{
	DriverObject->DriverUnload = Unload;
	NTSTATUS status = Initialize();
	if (!NT_SUCCESS(status))
	{
		return STATUS_UNSUCCESSFUL;
	}

	_IO_Control = new IO_Control(DriverObject);
	if (!_IO_Control)
	{
		return STATUS_UNSUCCESSFUL;
	}

	status = _IO_Control->Create_IO_Control();
	if (!NT_SUCCESS(status))
	{
		return STATUS_UNSUCCESSFUL;
	}

	return STATUS_SUCCESS;

}


