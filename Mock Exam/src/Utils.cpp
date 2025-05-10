#include "../headers/Process.hpp"
#include "../headers/Utils.hpp"

using namespace std;

bool ProcessComparator::operator()(const Process& p1, const Process& p2) {
    // Primary: priority
    // Secondary: remaining time (shortest first)
    // Tertiary: arrival time (earliest first)
    if (p1.getPriority() != p2.getPriority())
        return p1.getPriority() < p2.getPriority();
    if (p1.getRemainingTime() != p2.getRemainingTime())
        return p1.getRemainingTime() < p2.getRemainingTime();
    return p1.getArrivalTime() < p2.getArrivalTime();
}
