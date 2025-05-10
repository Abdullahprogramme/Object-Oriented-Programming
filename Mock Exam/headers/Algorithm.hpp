#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <string>
#include <functional>
#include <vector>

using namespace std;

template<typename T>
class Algorithm {
    private:
        string algorithmId;
        string name;
        string category;
        string timeComplexity;
        string spaceComplexity;
        function<void(vector<T>&)> implementationFunction;
        // function pointer would be: void (*implementationFunction)(vector<T>&);

    public:
        Algorithm() = default;

        Algorithm(const string& id, const string& name,
                const string& category,
                const string& timeComp,
                const string& spaceComp,
                function<void(vector<T>&)> func)
        : algorithmId(id), name(name), category(category),
        timeComplexity(timeComp), spaceComplexity(spaceComp), implementationFunction(func) {}

        string getId() const {
            return algorithmId;
        }

        string getName() const {
            return name;
        }

        string getCategory() const {
            return category;
        }

        string getTimeComplexity() const {
            return timeComplexity;
        }

        string getSpaceComplexity() const {
            return spaceComplexity;
        }

        function<void(vector<T>&)> getFunction() const {
            return implementationFunction;
        }

        // function pointer would be: void (*getFunction())(vector<T>&) {
};

#endif
