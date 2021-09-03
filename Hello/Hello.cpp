// Hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>  

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

    HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, 12988);
    if (hProcess) {
        ::TerminateProcess(hProcess, 0);
    }
    else {
        return Error("Failed to open process");
    }

    return 0;
}

