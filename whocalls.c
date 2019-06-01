#include <stdio.h>
#include <time.h>
#include <windows.h>


#if defined(__cplusplus)
extern "C" {
#endif
  __declspec(dllexport) int DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
  {
    
    if (fdwReason != 1 && fdwReason !=2) { // DLL_PROCESS_ATTACH or DLL_THREAD_ATTACH
        return 1;
    }
    
    FILE *fp;
    fp  = fopen ("C:/HONKHONK.TXT", "a"); // You probably want to customise this... ;-)
    
    char hostname[255] = "";
    ZeroMemory(hostname, sizeof(hostname) );
    DWORD CompBuffer = 255;
    GetComputerName(hostname, &CompBuffer);

    char username[255] = "";
    ZeroMemory(username, sizeof(username) );
    DWORD NameBuffer = 255;
    GetUserName(username, &NameBuffer);

    char dllpath[65535];
	GetModuleFileName(hinstDLL, dllpath, sizeof(dllpath));

    char exepath[65535];
    GetModuleFileName(NULL, exepath, sizeof(exepath));

    SYSTEMTIME st;
    GetSystemTime(&st); // This is UTC time. GetLocalTime, er, gets the local time
    
    fprintf(fp, "%s|%s|%s|%s|%d|%d/%d/%d %d:%d:%d:%d\n", hostname, username, dllpath, exepath, fdwReason, st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);


    fclose (fp);
    return 1;
  }

#if defined(__cplusplus)
}
#endif