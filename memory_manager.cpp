#include <iostream>
#include <vector>
using namespace std;

void MemoryManager::menu() {
    cout << "\n--- Memory Management Menu ---\n";
    allocateMemory();
}

void MemoryManager::allocateMemory() {
    int memorySize, blockSize, numBlocks;
    cout << "Enter total memory size: ";
    cin >> memorySize;
    cout << "Enter block size: ";
    cin >> blockSize;

    numBlocks = memorySize / blockSize;
    vector<bool> blocks(numBlocks, false);

    int choice;
    do {
        cout << "\n1. Allocate memory\n2. Deallocate memory\n3. Display memory status\n4. Exit Memory Manager\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int blockNum;
            cout << "Enter block number to allocate (0 to " << numBlocks-1 << "): ";
            cin >> blockNum;
            if (blockNum >= 0 && blockNum < numBlocks) {
                if (!blocks[blockNum]) {
                    blocks[blockNum] = true;
                    cout << "Block " << blockNum << " allocated.\n";
                } else {
                    cout << "Block already allocated.\n";
                }
            } else {
                cout << "Invalid block number.\n";
            }
        } else if (choice == 2) {
            int blockNum;
            cout << "Enter block number to deallocate: ";
            cin >> blockNum;
            if (blockNum >= 0 && blockNum < numBlocks) {
                if (blocks[blockNum]) {
                    blocks[blockNum] = false;
                    cout << "Block " << blockNum << " deallocated.\n";
                } else {
                    cout << "Block already free.\n";
                }
            } else {
                cout << "Invalid block number.\n";
            }
        } else if (choice == 3) {
            cout << "Memory Blocks Status:\n";
            for (int i = 0; i < numBlocks; i++) {
                cout << "Block " << i << ": " << (blocks[i] ? "Allocated" : "Free") << endl;
            }
        }
    } while (choice != 4);
}
