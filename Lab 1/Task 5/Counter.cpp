#include "Counter.hpp"


InstanceCounter::InstanceCounter() {
    count++;
}

int InstanceCounter::getCount() {
    return count;
}
