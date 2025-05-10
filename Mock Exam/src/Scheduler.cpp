#include "../headers/Scheduler.hpp"
#include "../headers/Process.hpp"
#include "../headers/Utils.hpp"

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void Scheduler::merge(list<Process>& arr, int left, int mid, int right) {
    list<Process> leftArr(arr.begin(), next(arr.begin(), mid + 1));
    list<Process> rightArr(next(arr.begin(), mid + 1), next(arr.begin(), right + 1));

    auto i = leftArr.begin();
    auto j = rightArr.begin();
    auto k = arr.begin();

    while (i != leftArr.end() && j != rightArr.end()) {
        if (ProcessComparator()(*i, *j)) {
            *k++ = *i++;
        } else {
            *k++ = *j++;
        }
    }
    while (i != leftArr.end()) {
        *k++ = *i++;
    }
    while (j != rightArr.end()) {
        *k++ = *j++;
    }
}

void Scheduler::mergeSort(list<Process>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void Scheduler::addProcess(const Process& process) {
    processQueue.push_back(process);
}

void Scheduler::removeProcess(int pid) {
    // processQueue.remove_if([pid](const Process& p) { return p.getPid() == pid; });
    processQueue.erase(
        remove_if(processQueue.begin(), processQueue.end(),
            [pid](const Process& p) { return p.getPid() == pid; }),
        processQueue.end());
}

void Scheduler::UpdateProcessState(int pid, Process::state newState) {
    for (auto& process : processQueue) {
        if (process.getPid() == pid) {
            process.currentState = newState;
            break;
        }
    }
}

void Scheduler::allocateResource(int pid, int resource) {
    for (auto& process : processQueue) {
        if (process.getPid() == pid) {
            process.addResource(resource);
            break;
        }
    }
}

void Scheduler::releaseResource(int pid, int resource) {
    for (auto& process : processQueue) {
        if (process.getPid() == pid) {
            process.removeResource(resource);
        }
    }
}

void Scheduler::displayProcessDetails(int pid) const {
    for (const auto& process : processQueue) {
        if (process.getPid() == pid) {
            process.printProcessInfo();
            break;
        }
    }
}

void Scheduler::displayAllProcesses() const {
    for (const auto& process : processQueue) {
        process.printProcessInfo();
    }
}

Process* Scheduler::getProcessByPid(int pid) {
    for (auto& process : processQueue) {
        if (process.getPid() == pid) {
            return &process;
        }
    }
    return nullptr;
}

list<Process> Scheduler::getProcessesByState(Process::state state) const {
    list<Process> result;
    for (const auto& process : processQueue) {
        if (process.currentState == state) {
            result.push_back(process);
        }
    }
    return result;
}

void Scheduler::scheduleByPriority() {
    mergeSort(processQueue, 0, processQueue.size() - 1);
}

void Scheduler::scheduleByShortestJobFirst() {
    processQueue.sort([](const Process& p1, const Process& p2) {
        return p1.getBurstTime() < p2.getBurstTime();
    });
}

void Scheduler::scheduleByRoundRobin(int timeQuantum) {
    list<Process> tempQueue = processQueue;
    while (!tempQueue.empty()) {
        Process& process = tempQueue.front();
        if (process.getRemainingTime() > timeQuantum) {
            process.setRemainingTime(process.getRemainingTime() - timeQuantum);
            tempQueue.push_back(process);
        } else {
            process.setRemainingTime(0);
        }
        tempQueue.pop_front();
    }
}
