#include <iostream>
#include "process_scheduler.h"
#include "memory_manager.h"
#include "file_system.h"
#include "shell.h"

using namespace std;

int main() {
    int choice;
    ProcessScheduler scheduler;
    MemoryManager memoryManager;
    FileSystem fileSystem;
    Shell shell;

    do {
        cout << "\n===== Welcome to OS Simulator =====\n";
        cout << "1. Process Scheduling\n";
        cout << "2. Memory Management\n";
        cout << "3. File Management\n";
        cout << "4. Shell Command Simulation\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                scheduler.menu();
                break;
            case 2:
                memoryManager.menu();
                break;
            case 3:
                fileSystem.menu();
                break;
            case 4:
                shell.menu();
                break;
            case 5:
                cout << "Exiting OS Simulator. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
