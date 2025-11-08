#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
    unsigned int cores = thread::hardware_concurrency();
    cout << "cpu cores: " << cores << "\n";

    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buf[32];
    ctime_s(buf, sizeof(buf), &t);
    cout << "time: " << buf;

#ifdef _WIN32
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    if (GlobalMemoryStatusEx(&mem)) {
        cout << "ram: " << mem.ullTotalPhys / (1024 * 1024) << " MB total\n";
        cout << "ram free: " << mem.ullAvailPhys / (1024 * 1024) << " MB\n";
    }
    else {
        cout << "ram info erorred\n";
    }
#else
    cout << "ram info only on windows\n";
#endif
}
