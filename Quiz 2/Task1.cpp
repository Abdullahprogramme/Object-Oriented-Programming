#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

class Node {
    public:
        int id;
        explicit Node(int id) : id(id) {}
        virtual ~Node() {}
};

class ServerNode : public Node {
    public:
        explicit ServerNode(int id) : Node(id) {}
};

class Network {
    private:
        unordered_map<int, int> parent;
        
        int find(int node) {
            if (parent.find(node) == parent.end()) {
                throw runtime_error("Node not found in the network!");
            }
            if (parent[node] != node) {
                parent[node] = find(parent[node]); // Path compression
            }
            return parent[node];
        }

    public:
        void addNode(Node* node) {
            parent[node->id] = node->id;
        }

        void connect(Node* a, Node* b) {
            if (!a || !b) {
                throw runtime_error("Cannot connect to a null node!");
            }
            int rootA = find(a->id);
            int rootB = find(b->id);
            
            if (rootA == rootB) {
                return;
            }
            parent[rootA] = rootB;
        }

        bool isConnected(Node* a, Node* b) {
            if (parent.find(a->id) == parent.end() || parent.find(b->id) == parent.end()) {
                return false;
            }
            return find(a->id) == find(b->id);
        }
};

int main() {
    Network network;
    ServerNode n1(1);
    Node n2(2);
    
    network.addNode(&n1);
    network.addNode(&n2);
    
    network.connect(&n1, &n2);
    cout << "ServerNode 1 connected to Node 2" << endl;

    Node a(3), b(4);
    network.addNode(&a);
    network.addNode(&b);

    if (!network.isConnected(&a, &b)) {
        cout << "A and B are NOT connected." << endl;
    }

    try {
        network.connect(&a, nullptr);
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
