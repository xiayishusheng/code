// main.c
#include <stdio.h>
#include <windows.h>

int main (int argc, char *argv[])
{
	int a = 10, b = 20;
	int c = 0;
	HINSTANCE   hInstLibrary   =   NULL;
	int (*add)();

	printf ("Load DLL file\n");
	if ((hInstLibrary = LoadLibrary("dll_demo.dll")) == NULL)
	{
		printf ("***LoadLibrary ERROR: %d.\n", GetLastError());
		return 1;
	}
	if((add = (int (*)())GetProcAddress(hInstLibrary, "add")) == NULL)
	{
		printf("***GetProcAddress ERROR: %d.\n", GetLastError());
		return 1;
	}

	c = add(a, b);
	printf("%d + %d = %d\n", a, b, c);

	FreeLibrary(hInstLibrary);
	return 0;
}