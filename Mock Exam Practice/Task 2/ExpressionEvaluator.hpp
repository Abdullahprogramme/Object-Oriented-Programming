#ifndef ExpressionEvaluator_hpp
#define ExpressionEvaluator_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Operation.hpp"
#include "Add.hpp"
#include "Multiply.hpp"
#include "ExpensivePower.hpp"
#include "CachedAdd.hpp"
#include "CachedMultiply.hpp"
#include "CachedSine.hpp"

using namespace std;

template <typename T>
class ExpressionEvaluator {
    private:
        OperationNode<T>* head;
        OperationNode<T>* tail;

    public:
        ExpressionEvaluator() : head(nullptr), tail(nullptr) {}

        void addOperation(Operation<T>* op) {
            auto* newNode = new OperationNode<T>(op);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        T evaluate(T input) const {
            T result = input;
            OperationNode<T>* current = head;
            while (current) {
                result = current->operation->apply(result);
                current = current->next;
            }
            return result;
        }

        void printPipeline() const {
            OperationNode<T>* current = head;
            while (current) {
                cout << current->operation->name() << " -> ";
                current = current->next;
            }
            cout << "END" << endl;
        }

        ~ExpressionEvaluator() {
            OperationNode<T>* current = head;
            while (current) {
                OperationNode<T>* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            tail = nullptr;
        }
};

#endif /* ExpressionEvaluator_hpp */