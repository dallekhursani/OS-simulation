#ifndef PROCESS_SCHEDULER_H
#define PROCESS_SCHEDULER_H

class ProcessScheduler {
public:
    void menu();
private:
    void fcfs();
    void sjf();
    void priorityScheduling();
    void roundRobin();
};

#endif
