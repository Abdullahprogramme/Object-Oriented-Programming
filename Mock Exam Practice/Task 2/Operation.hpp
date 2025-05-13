#ifndef Operation_hpp
#define Operation_hpp

#include <string>
using namespace std;

template <typename T>
class Operation {
    public:
        virtual T apply(T input) const = 0;
        virtual string name() const = 0;
        virtual ~Operation() = default;
};

template <typename T>
struct OperationNode {
    Operation<T>* operation;
    OperationNode* next;

    OperationNode(Operation<T>* op) : operation(op), next(nullptr) {}
    ~OperationNode() {}
};

#endif /* Operation_hpp */