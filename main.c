#include <windows.h>
#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS // so the fucking clang extension doesn't scream at me like a lunatic.

int main(void) {
    char keyword[256];
    char command[256];

    printf("Type the keyword you want to find in the terminal: \n");
    scanf("%s", keyword);

    printf("Type the command to run the process you want to find the keyword in: \n");
    scanf("%s", command);

    HANDLE hRead, hWrite;
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    CreatePipe(&hRead, &hWrite, &sa, 0);

    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = hWrite;
    si.hStdError = hWrite;

    if (!CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_PROCESS_GROUP, NULL, NULL, &si, &pi)) {
        printf("Failed to start process.\n");
        return 1;
    }
    CloseHandle(hWrite);
    char buffer[4096];
    DWORD bytesRead;
    int found = 0;
    while (ReadFile(hRead, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, keyword)) {
            found = 1;
            break;
        }
    }
    CloseHandle(hRead);

    if (found) {
        printf("\nKeyword found! Sending CTRL+C to process...\n");
        GenerateConsoleCtrlEvent(CTRL_C_EVENT, pi.dwProcessId);
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}