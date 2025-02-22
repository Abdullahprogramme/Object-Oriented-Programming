#include <iostream> 

using namespace std;

class MemoryResource {
    public:
        // Constructor 
        MemoryResource() {
            cout << "MemoryResource base allocated" << endl;
        }

        // Destructor
        ~MemoryResource() {
            cout << "MemoryResource base freed" << endl;
        }
};

class NetworkBuffer : public MemoryResource {
    public:
        // Constructor
        NetworkBuffer() {
            cout << "NetworkBuffer derived allocated" << endl;
        }

        // Destructor
        ~NetworkBuffer() {
            cout << "NetworkBuffer derived freed" << endl;
        }
};

int main() {
    NetworkBuffer nb;
    return 0;
}