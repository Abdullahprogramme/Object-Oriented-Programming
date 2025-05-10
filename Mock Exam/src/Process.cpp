#include "../headers/Process.hpp"

#include <iostream>
#include <list>
#include <string>

using namespace std;

Process::Process(int pid, const string& name, int priority, int burstTime, int arrivalTime)
    : pid(pid), name(name), priority(priority), burstTime(burstTime),
      arrivalTime(arrivalTime), remainingTime(burstTime) {}

int Process::getPid() const { return pid; }
string Process::getName() const { return name; }
int Process::getPriority() const { return priority; }
int Process::getBurstTime() const { return burstTime; }
int Process::getArrivalTime() const { return arrivalTime; }
int Process::getRemainingTime() const { return remainingTime; }
list<int> Process::getResources() const { return resources; }

void Process::setPid(int newPid) { pid = newPid; }
void Process::setName(const string& newName) { name = newName; }
void Process::setPriority(int newPriority) { priority = newPriority; }
void Process::setBurstTime(int newBurstTime) { burstTime = newBurstTime; }
void Process::setArrivalTime(int newArrivalTime) { arrivalTime = newArrivalTime; }
void Process::setRemainingTime(int newRemainingTime) { remainingTime = newRemainingTime; }
void Process::addResource(int resource) { resources.push_back(resource); }

void Process::removeResource(int resource) {
    resources.remove(resource);
}

void Process::clearResources() {
    resources.clear();
}

void Process::printProcessInfo() const {
    cout << "Process ID: " << pid << ", Name: " << name
         << ", Priority: " << priority << ", Burst Time: " << burstTime
         << ", Arrival Time: " << arrivalTime
         << ", Remaining Time: " << remainingTime
         << ", Resources: ";
    for (const auto& res : resources) {
        cout << res << " ";
    }
    cout << endl;
}
