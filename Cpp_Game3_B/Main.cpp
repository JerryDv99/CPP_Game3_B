#include "MainUpdate.h"

int main(void)
{
	DWORD Mode;
	HANDLE Handle = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(Handle, &Mode);
	SetConsoleMode(Handle, Mode & ~ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

	system("title ¹ÚÁØÇü : Highway Chase");
	system("mode con cols = 150 lines = 48");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time <= GetTickCount64())
		{
			Time == GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	return 0;
}