#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

int main() {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        cout << "snap fail\n";
        return 1;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);

    if (!Process32First(snap, &pe)) {
        cout << "no proc\n";
        CloseHandle(snap);
        return 1;
    }

    cout << "running procs:\n";
    do {
        wcout << L"- " << pe.szExeFile << L" (pid: " << pe.th32ProcessID << L")\n";
    } while (Process32Next(snap, &pe));

    CloseHandle(snap);
    return 0;
}