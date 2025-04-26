#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FileSystem::menu() {
    int choice;
    do {
        cout << "\n--- File Management Menu ---\n";
        cout << "1. Create a file\n";
        cout << "2. Read a file\n";
        cout << "3. Delete a file\n";
        cout << "4. Exit File System\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: deleteFile(); break;
            case 4: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void FileSystem::createFile() {
    string filename, content;
    cout << "Enter filename to create: ";
    cin >> filename;
    ofstream fout(filename);
    cout << "Enter content (end with #): ";
    cin.ignore();
    getline(cin, content, '#');
    fout << content;
    fout.close();
    cout << "File created successfully.\n";
}

void FileSystem::readFile() {
    string filename, content;
    cout << "Enter filename to read: ";
    cin >> filename;
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found.\n";
        return;
    }
    cout << "File Content:\n";
    while (getline(fin, content)) {
        cout << content << endl;
    }
    fin.close();
}

void FileSystem::deleteFile() {
    string filename;
    cout << "Enter filename to delete: ";
    cin >> filename;
    if (remove(filename.c_str()) == 0)
        cout << "File deleted successfully.\n";
    else
        cout << "Error deleting file.\n";
}
