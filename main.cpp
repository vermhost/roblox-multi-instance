#include <Windows.h>
#include <iostream>
#include <string>

int main() {
    wchar_t mutexName[] = L"ROBLOX_singletonMutex";
    char mutexNameA[MAX_PATH];
    WideCharToMultiByte(CP_ACP, 0, mutexName, -1, mutexNameA, MAX_PATH, NULL, NULL);

    HANDLE hMutex = CreateMutex(NULL, TRUE, mutexNameA);
    if (hMutex == NULL) {
        std::cerr << "[ERROR] Failed to create mutex." << std::endl;
    } else {
        std::cout << "[LOG] Mutex created successfully." << std::endl;
    }

    std::cout << "Press Enter to exit.";
    std::cin.get();
    CloseHandle(hMutex);
    return 0;
}