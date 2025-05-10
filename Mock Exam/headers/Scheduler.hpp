#ifndef Scheduler_hpp
#define Scheduler_hpp

#include "Process.hpp"
#include "Utils.hpp"
#include <list>
#include <iostream>

using namespace std;

class Scheduler {
    private:
        list<Process> processQueue;

        void merge(list<Process>& arr, int left, int mid, int right);
        void mergeSort(list<Process>& arr, int left, int right);

    public:
        void addProcess(const Process& process);
        void removeProcess(int pid);
        void UpdateProcessState(int pid, Process::state newState);
        void allocateResource(int pid, int resource);
        void releaseResource(int pid, int resource);
        void displayProcessDetails(int pid) const;
        void displayAllProcesses() const;
        Process* getProcessByPid(int pid);
        list<Process> getProcessesByState(Process::state state) const;

        void scheduleByPriority();
        void scheduleByShortestJobFirst();
        void scheduleByRoundRobin(int timeQuantum);
};

#endif /* Scheduler_hpp */
