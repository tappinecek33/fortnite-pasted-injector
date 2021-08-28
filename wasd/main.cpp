#include <windows.h>
#include <iostream>
#include <string>
#include <conio.h>

///inject includes
#include "define/stdafx.h"
#include "api/xor.h"
#include "api/api.h"
#include "driver/driver.h"
#include "inject/injector.h"
#include "api/drvutils.h"
#include "xorstr.h"
HWND fnt = NULL;
char title[100];

void getrandomnumber(char* sStr, unsigned int iLen)
{
	char Syms[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int Ind = 0;
	srand(time(NULL) + rand());
	while (Ind < iLen)
	{
		sStr[Ind++] = Syms[rand() % 62];
	}
	sStr[iLen] = '\0';
}

std::string randomstringtorenameexe(const size_t length)
{
	std::string r;
	static const char bet[] = { "abcdefghijklmnopqrstuvwxyzz" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}

std::string path()
{
	char shitter[_MAX_PATH];
	GetModuleFileNameA(NULL, shitter, _MAX_PATH);
	return std::string(shitter);
}

void checkadmin() {

	bool admin = false;

	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	admin = fRet;

	if (!admin) {
		exit(0);
	}

}

int main()
{
	checkadmin();
	std::string name = "wasd-" + randomstringtorenameexe(4) + ".exe";
	std::rename(path().c_str(), name.c_str());
	getrandomnumber(title, 32);
	SetConsoleTitle(title);
	std::cout << xor("\n\n    aaaaaaaaaaa#2000 & tappinecek - youtube.com/c/trappinkcc") << std::endl;
	std::cout << xor("    loading driver") << std::endl;
	startdriver();
	std::cout << xor ("    waiting for fortniteclient-win64-shipping.exe") << std::endl;
	while (fnt == NULL)
	{
		fnt = FindWindowA(0, "Fortnite  ");
		Sleep(1);
	}
	std::cout << xor ("    process founded!.") << std::endl;
	std::cout << xor ("    press any key to start process injecting (lobby)") << std::endl;
	getch();

		mixujem2(xor_a("UnrealWindow"), xor_w(L"google.dll")); 

		std::cout << xor ("   application exiting in 5 seconds") << std::endl;
		Sleep(5000);
		return 0;
}