#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CreateMutexW(NULL, TRUE, L"mtx_hsupdate");
	HANDLE hEvent = CreateEventW(NULL, FALSE, FALSE, L"Global\\EF81BA4B-4163-44f5-90E2-F05C1E49C12D");
	if (hEvent)
	{
		SetEvent(hEvent);
		CloseHandle(hEvent);
	}
	return 0;
}