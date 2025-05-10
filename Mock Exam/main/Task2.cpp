#include "../headers/Process.hpp"
#include "../headers/Scheduler.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

void simulateExecution(Scheduler& scheduler, const string& method, int timeQuantum = 3) {
    if (method != "Priority" && method != "SJF" && method != "Round Robin") {
        cerr << "Error: Invalid scheduling method '" << method << "'.\n";
        return;
    }

    if (method == "Round Robin" && timeQuantum <= 0) {
        cerr << "Error: Time quantum must be greater than zero for Round Robin scheduling.\n";
        return;
    }

    cout << "\n--- Scheduling by " << method << " ---\n";
    cout << "Before scheduling:\n";
    scheduler.displayAllProcesses();

    try {
        if (method == "Priority") {
            scheduler.scheduleByPriority();
        } else if (method == "SJF") {
            scheduler.scheduleByShortestJobFirst();
        } else if (method == "Round Robin") {
            scheduler.scheduleByRoundRobin(timeQuantum);
        }
    } catch (const exception& e) {
        cerr << "Error during scheduling: " << e.what() << "\n";
        return;
    }

    cout << "\nAfter scheduling:\n";
    scheduler.displayAllProcesses();
}

int main() {
    Scheduler scheduler;

    // Create 10 processes with different attributes
    vector<shared_ptr<Process>> processes = {
        make_shared<Process>(1, "P1", 3, 10, 0),
        make_shared<Process>(2, "P2", 1, 4, 1),
        make_shared<Process>(3, "P3", 4, 7, 2),
        make_shared<Process>(4, "P4", 2, 5, 3),
        make_shared<Process>(5, "P5", 1, 6, 4),
        make_shared<Process>(6, "P6", 2, 8, 2),
        make_shared<Process>(7, "P7", 3, 3, 1),
        make_shared<Process>(8, "P8", 5, 2, 5),
        make_shared<Process>(9, "P9", 4, 9, 6),
        make_shared<Process>(10, "P10", 2, 1, 7)
    };

    for (auto& p : processes) {
        p->currentState = Process::Ready;
        scheduler.addProcess(*p);
    }

    simulateExecution(scheduler, "Priority");
    simulateExecution(scheduler, "SJF");
    simulateExecution(scheduler, "Round Robin", 3);

    // Simulate execution loop: Update state and terminate
    cout << "\n--- Execution Simulation ---\n";
    for (int i = 1; i <= 10; ++i) {
        try {
            scheduler.UpdateProcessState(i, Process::Running);
            cout << "Running Process " << i << "...\n";
            scheduler.UpdateProcessState(i, Process::Terminated);
        } catch (const exception& e) {
            cerr << "Error updating process state: " << e.what() << "\n";
        }
    }

    // Allocate and release resources
    cout << "\n--- Resource Management ---\n";
    try {
        scheduler.allocateResource(1, 101);
        scheduler.allocateResource(2, 102);
        scheduler.releaseResource(1, 101);
    } catch (const exception& e) {
        cerr << "Error in resource management: " << e.what() << "\n";
    }

    cout << "\nFinal State of All Processes:\n";
    scheduler.displayAllProcesses();

    return 0;
}