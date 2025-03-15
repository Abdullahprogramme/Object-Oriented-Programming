#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct Parcel {
    string id;
    int zone;
};

class ParcelStack {
    private:
        stack<vector<Parcel>> stack;

    public:
        void insert(const string& id, int zone) {
            if (stack.empty() || stack.top().front().zone != zone) {
                stack.push({{id, zone}});
            } else {
                stack.top().push_back({id, zone});
            }
        }

        void remove() {
            if (stack.empty()) {
                cout << "Stack is empty!\n";
                return;
            }
            
            Parcel removed = stack.top().back();
            stack.top().pop_back();
            if (stack.top().empty()) {
                stack.pop();
            }

            cout << removed.id << "\n";
        }
};

int main() {
    ParcelStack parcelStack;
    string command;
    
    while (true) {
        cin >> command;
        if (command == "INSERT") {
            string id;
            int zone;
            cin >> id >> zone;
            parcelStack.insert(id, zone);
        } else if (command == "REMOVE") {
            parcelStack.remove();
        } else if (command == "END") {
            break;
        }
    }

    return 0;
}
