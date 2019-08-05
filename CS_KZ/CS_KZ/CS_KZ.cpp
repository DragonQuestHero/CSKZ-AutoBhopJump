#include <windows.h>

#include <iostream>
#include <thread>
#include <string>

#include "DirectInput.h"

volatile bool Jump = false;

int temp = 220;
int last_x = 0;
int last_key = 0;
volatile bool ad = false;
volatile bool adl = false;
volatile bool adr = false;
volatile bool longjump = false;
volatile bool longjumpj = false;
volatile bool jump = false;
volatile bool mouse = false;
volatile bool mcj = false;
volatile bool down = false;
volatile bool haihuang = false;
volatile bool haihuang2 = false;


struct DATA_IMFOMATION
{
	int key;
	int flag;
};

void LongJump()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}

		if (longjump && longjumpj)
		{
			for (auto i = 0; i < 2; i++)
			{
				{
					INPUT Input = { 0 };
					Input.type = INPUT_KEYBOARD;
					Input.ki.wVk = 0x41;
					Input.ki.dwFlags = 0;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}

				for (int i = 0; i < 43; i++)
				{
					INPUT Input = { 0 };
					Input.type = INPUT_MOUSE;
					Input.mi.dx = -10;
					Input.mi.dy = 0;
					Input.mi.mouseData = 0;
					Input.mi.dwFlags = MOUSEEVENTF_MOVE;
					Input.mi.time = 0;
					Input.mi.dwExtraInfo = 0;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}

				{
					INPUT Input;
					Input.type = INPUT_KEYBOARD;
					Input.ki.wVk = 0x41;
					Input.ki.dwFlags = KEYEVENTF_KEYUP;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}




				{
					INPUT Input = { 0 };
					Input.type = INPUT_KEYBOARD;
					Input.ki.wVk = 0x44;
					Input.ki.dwFlags = 0;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}

				for (int i = 0; i < 50; i++)
				{
					INPUT Input = { 0 };
					Input.type = INPUT_MOUSE;
					Input.mi.dx = 10;
					Input.mi.dy = 0;
					Input.mi.mouseData = 0;
					Input.mi.dwFlags = MOUSEEVENTF_MOVE;
					Input.mi.time = 0;
					Input.mi.dwExtraInfo = 0;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}

				{
					INPUT Input;
					Input.type = INPUT_KEYBOARD;
					Input.ki.wVk = 0x44;
					Input.ki.dwFlags = KEYEVENTF_KEYUP;
					DirectInput::SendInput(1, &Input, sizeof(INPUT));
					Sleep(1);
				}


			}
			


			longjumpj = false;
			longjump = false;
		}
	}
}

void MCJ()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}

		if (mcj)
		{
			{
				INPUT Input = { 0 };
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}

			for (int i = 0; i < 300; i++)
			{
				INPUT Input = { 0 };
				Input.type = INPUT_MOUSE;
				Input.mi.dx = -4;
				Input.mi.dy = 0;
				Input.mi.mouseData = 0;
				Input.mi.dwFlags = MOUSEEVENTF_MOVE;
				Input.mi.time = 0;
				Input.mi.dwExtraInfo = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}

			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}




			{
				INPUT Input = { 0 };
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}

			for (int i = 0; i < 300; i++)
			{
				INPUT Input = { 0 };
				Input.type = INPUT_MOUSE;
				Input.mi.dx = 4;
				Input.mi.dy = 0;
				Input.mi.mouseData = 0;
				Input.mi.dwFlags = MOUSEEVENTF_MOVE;
				Input.mi.time = 0;
				Input.mi.dwExtraInfo = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}

			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(1);
			}
		}
	}
}

void AtuoMouseR()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}

		if (mouse && adr)
		{

			{
				INPUT Input = { 0 };
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(3);
			}

			for (int i = 0; i < 50; i++)
			{
				INPUT Input = { 0 };
				Input.type = INPUT_MOUSE;
				Input.mi.dx = 10;
				Input.mi.dy = 0;
				Input.mi.mouseData = 0;
				Input.mi.dwFlags = MOUSEEVENTF_MOVE;
				Input.mi.time = 0;
				Input.mi.dwExtraInfo = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(4);
			}

			//for (int i = 0; i < 3; i++)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(3);
			}
			
			adr = false;
			adl = true;

		}


	}
}

void AtuoMouseL()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}

		if (mouse && adl)
		{
			{
				INPUT Input = { 0 };
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(3);
			}

			for (int i = 0; i < 50; i++)
			{
				
				INPUT Input = { 0 };
				Input.type = INPUT_MOUSE;
				Input.mi.dx = -10;
				Input.mi.dy = 0;
				Input.mi.mouseData = 0;
				Input.mi.dwFlags = MOUSEEVENTF_MOVE;
				Input.mi.time = 0;
				Input.mi.dwExtraInfo = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(4);
			}

			//for (int i = 0; i < 3; i++)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				Sleep(3);
			}

			
			adr = true;
			adl = false;
			


		}


	}
}

void Dance()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}
		Sleep(1);


		POINT p;
		GetCursorPos(&p);

		if (ad)
		{
			if (1280 > p.x)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				last_key = 1;
			}
			else if (1280 < p.x)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = 0;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
				last_key = 2;
			}
		}

		if (1280 == p.x)
		{
			if (last_key == 1)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x41;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
			}
			if (last_key == 2)
			{
				INPUT Input;
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = 0x44;
				Input.ki.dwFlags = KEYEVENTF_KEYUP;
				DirectInput::SendInput(1, &Input, sizeof(INPUT));
			}
			last_key = 0;
		}



		last_x = p.x;
	}
}

void HaiHuang()
{
	while (true)
	{
		Sleep(1);
		if (haihuang && haihuang2)
		{
			INPUT Input = { 0 };
			Input.type = INPUT_MOUSE;
			Input.mi.dx = 0;
			Input.mi.dy = 0;
			Input.mi.mouseData = 0;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			Input.mi.time = 0;
			Input.mi.dwExtraInfo = 0;
			DirectInput::SendInput(1, &Input, sizeof(INPUT));
			Sleep(1);

			Input.type = INPUT_MOUSE;
			Input.mi.dx = 0;
			Input.mi.dy = 0;
			Input.mi.mouseData = 0;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			Input.mi.time = 0;
			Input.mi.dwExtraInfo = 0;
			DirectInput::SendInput(1, &Input, sizeof(INPUT));
			Sleep(1);

			Input.type = INPUT_MOUSE;
			Input.mi.dx = 0;
			Input.mi.dy = 0;
			Input.mi.mouseData = 0;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			Input.mi.time = 0;
			Input.mi.dwExtraInfo = 0;
			DirectInput::SendInput(1, &Input, sizeof(INPUT));
			Sleep(1);

			Input.type = INPUT_MOUSE;
			Input.mi.dx = 0;
			Input.mi.dy = 0;
			Input.mi.mouseData = 0;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			Input.mi.time = 0;
			Input.mi.dwExtraInfo = 0;
			DirectInput::SendInput(1, &Input, sizeof(INPUT));
			Sleep(1);

			haihuang2 = false;
		}


	}
}

void Jumper()
{
	while (true)
	{
		if (down == true)
		{
			return;
		}
		if (jump)
		{
			INPUT Input = { 0 };
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_WHEEL;
			if (mcj)
			{
				Input.mi.mouseData = 360;
			}
			else
			{
				Input.mi.mouseData = -360;
			}
			DirectInput::SendInput(1, &Input, sizeof(INPUT));
			if (mcj)
			{
				Sleep(temp);
			}
			else
			{
				Sleep(20);
			}
		}
	}
}

void Start()
{
	HANDLE m_hDevice = CreateFileA("\\\\.\\IO_Control", GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	if (INVALID_HANDLE_VALUE == m_hDevice)
	{
		return;
	}
	HANDLE event_handle = CreateEventA(NULL, TRUE, FALSE, NULL);
	OVERLAPPED temp_ol = { 0 };
	temp_ol.hEvent = event_handle;
	DWORD dwRet = 0;
	DATA_IMFOMATION info = { 0 };
	DeviceIoControl(m_hDevice, 0x1234, &info, sizeof(DATA_IMFOMATION),
		&info, sizeof(DATA_IMFOMATION), &dwRet, &temp_ol); //hook it.
	int index = 0;


	while (down == false)
	{
		DWORD result_status = WaitForSingleObject(event_handle, 1);
		switch (result_status)
		{
		case WAIT_OBJECT_0:
		{
			std::cout << info.key << std::endl;
			std::cout << info.flag << std::endl;
			if (info.key == 33 && info.flag == 0)//F
			{
				ad = !ad;
				jump = !jump;
				if (jump == true)
				{
					MessageBeep(MB_OK);
				}
			}

			//if (info.key == 46 && info.flag == 0)//C
			//{
			//	jump = !jump;
			//	mouse = !mouse;
			//	adl = true;
			//}

			if (info.key == 57 && info.flag == 0)//speac
			{
				haihuang2 = true;
			}

			//if (info.key == 42 && info.flag == 0)//F
			//{
			//	ad = !ad;
			//}

			/*if (info.key == 45 && info.flag == 0)
			{
				temp = temp + 1;
				std::cout << "temp=" << temp << std::endl;
			}

			if (info.key == 44 && info.flag == 0)
			{
				temp = temp - 1;
				std::cout << "temp=" << temp << std::endl;
			}*/

			/*if (info.key == 47 && info.flag == 0)
			{
				jump = !jump;
				mcj = !mcj;
			}*/

			if (info.key == 59 && info.flag == 0)//F1
			{
				haihuang = true;
			}
			DeviceIoControl(m_hDevice, 0x1234, &info, sizeof(DATA_IMFOMATION),
				&info, sizeof(DATA_IMFOMATION), &dwRet, &temp_ol); //hook it.
			break;
		}
		case WAIT_TIMEOUT:
			break;
		}
	}

	CloseHandle(event_handle);
	CloseHandle(m_hDevice);
}


int main()
{
	std::thread t1(Jumper);
	std::thread t2(Dance);
	std::thread t3(Start);
	std::thread t4(AtuoMouseL);
	std::thread t44(AtuoMouseR);
	std::thread t5(MCJ);
	std::thread t6(LongJump);
	std::thread t7(HaiHuang);
	t1.detach();
	t2.detach();
	t3.detach();
	t4.detach();
	t44.detach();
	t5.detach();
	t6.detach();
	t7.detach();


	getchar();
	down = true;
	system("pause");
}


