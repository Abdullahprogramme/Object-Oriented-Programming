#ifndef Utils_hpp
#define Utils_hpp

#include "Process.hpp"

class ProcessComparator {
    public:
        bool operator()(const Process& p1, const Process& p2);
};

#endif // Utils_hpp
