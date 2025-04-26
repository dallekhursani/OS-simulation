#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, burstTime, arrivalTime, priority;
};

class ComparePriority {
public:
    bool operator()(Process a, Process b) {
        return a.priority < b.priority;
    }
};

void ProcessScheduler::menu() {
    int choice;
    cout << "\n--- Process Scheduling Menu ---\n";
    cout << "1. First Come First Serve (FCFS)\n";
    cout << "2. Shortest Job First (SJF)\n";
    cout << "3. Priority Scheduling\n";
    cout << "4. Round Robin Scheduling\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: fcfs(); break;
        case 2: sjf(); break;
        case 3: priorityScheduling(); break;
        case 4: roundRobin(); break;
        default: cout << "Invalid choice!\n";
    }
}

void ProcessScheduler::fcfs() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i+1 << ": ";
        cin >> p[i].burstTime;
        p[i].pid = i+1;
    }

    int waitingTime = 0;
    cout << "\nProcess Execution Order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << p[i].pid << " Waiting Time: " << waitingTime << endl;
        waitingTime += p[i].burstTime;
    }
}

void ProcessScheduler::sjf() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i+1 << ": ";
        cin >> p[i].burstTime;
        p[i].pid = i+1;
    }

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.burstTime < b.burstTime;
    });

    int waitingTime = 0;
    cout << "\nProcess Execution Order:\n";
    for (auto &proc : p) {
        cout << "Process " << proc.pid << " Waiting Time: " << waitingTime << endl;
        waitingTime += proc.burstTime;
    }
}

void ProcessScheduler::priorityScheduling() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time and Priority for Process " << i+1 << ": ";
        cin >> p[i].burstTime >> p[i].priority;
        p[i].pid = i+1;
    }

    sort(p.begin(), p.end(), ComparePriority());

    int waitingTime = 0;
    cout << "\nProcess Execution Order:\n";
    for (auto &proc : p) {
        cout << "Process " << proc.pid << " Waiting Time: " << waitingTime << endl;
        waitingTime += proc.burstTime;
    }
}

void ProcessScheduler::roundRobin() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> burstTime(n);
    vector<int> remainingTime(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i+1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    cout << "Enter Quantum Time: ";
    cin >> quantum;

    int t = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = false;
                if (remainingTime[i] > quantum) {
                    t += quantum;
                    remainingTime[i] -= quantum;
                    cout << "Process " << i+1 << " executed for " << quantum << " units.\n";
                } else {
                    t += remainingTime[i];
                    cout << "Process " << i+1 << " executed for " << remainingTime[i] << " units (Completed).\n";
                    remainingTime[i] = 0;
                }
            }
        }
    } while (!done);
}
