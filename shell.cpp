#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void Shell::menu() {
    cout << "\n--- Shell Command Simulation ---\n";
    simulateCommand();
}

void Shell::simulateCommand() {
    string command;
    do {
        cout << "\nOS> ";
        cin >> command;

        if (command == "ls") {
            for (const auto & entry : fs::directory_iterator(".")) {
                cout << entry.path().filename() << endl;
            }
        } else if (command == "mkdir") {
            string dirName;
            cin >> dirName;
            fs::create_directory(dirName);
            cout << "Directory created.\n";
        } else if (command == "rmdir") {
            string dirName;
            cin >> dirName;
            fs::remove_all(dirName);
            cout << "Directory removed.\n";
        } else if (command == "exit") {
            cout << "Exiting Shell...\n";
        } else {
            cout << "Unknown command.\n";
        }
    } while (command != "exit");
}
