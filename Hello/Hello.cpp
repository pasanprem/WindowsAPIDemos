// Hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>  
#include <strsafe.h>

int Error(const char* msg) {
    printf("%s (%u)\n", msg, ::GetLastError());
    return 1;
}

int main()
{
    SYSTEM_INFO si;
    ::GetNativeSystemInfo(&si);

    printf("Processors: %u\n", si.dwNumberOfProcessors);
    printf("Page size: %u\n", si.dwPageSize);
    printf("Processor mask: 0x%zX\n", si.dwActiveProcessorMask);

    /*HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, 12988);
    if (hProcess) {
        ::TerminateProcess(hProcess, 0);
    }
    else {
        return Error("Failed to open process");
    }*/

    WCHAR buffer[128];
    ::StringCchPrintf(buffer, _countof(buffer), L"This is my string from process %u", ::GetCurrentProcessId());
    //::MessageBox(nullptr, buffer, L"Strings demo", MB_OK | MB_ICONINFORMATION);

    WCHAR path[MAX_PATH];
    ::GetSystemDirectory(path, _countof(path));
    printf("System directory: %ws\n", path);

    WCHAR computerName[MAX_COMPUTERNAME_LENGTH];
    DWORD len = _countof(computerName);
    if (::GetComputerName(computerName, &len))
        printf("Computer name: %ws (%u)\n", computerName, len);

    return 0;
}

