#ifndef Process_hpp
#define Process_hpp

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Process {
    private:
        int pid;
        string name;
        int priority;
        int burstTime;
        int arrivalTime;
        int remainingTime;
        list<int> resources;

    public:
        enum state { Ready, Running, Blocked, Terminated };
        state currentState;

        Process(int pid, const string& name, int priority, int burstTime, int arrivalTime);

        int getPid() const;
        string getName() const;
        int getPriority() const;
        int getBurstTime() const;
        int getArrivalTime() const;
        int getRemainingTime() const;
        list<int> getResources() const;

        void setPid(int newPid);
        void setName(const string& newName);
        void setPriority(int newPriority);
        void setBurstTime(int newBurstTime);
        void setArrivalTime(int newArrivalTime);
        void setRemainingTime(int newRemainingTime);
        void addResource(int resource);
        void removeResource(int resource);
        void clearResources();

        void printProcessInfo() const;
};

#endif // Process_hpp
