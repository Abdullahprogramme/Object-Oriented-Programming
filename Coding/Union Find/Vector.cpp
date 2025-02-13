#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i; // Every node is its own parent
                rank[i] = 0; // Every node has rank 0
            }
        }

        int find(int x) {
            if (parent[x] != x) { // If x is not its own parent
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x); // Find the root of x
            int rootY = find(y); // Find the root of y
            if (rootX == rootY) { // If x and y are already connected
                return;
            }
            if (rank[rootX] < rank[rootY]) { // If x has a smaller rank than y
                parent[rootX] = rootY;
            } else { // If y has a smaller rank than x
                parent[rootY] = rootX;
                if (rank[rootX] == rank[rootY]) { // If x and y have the same rank
                    rank[rootX]++;
                }
            }
        }

        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << "Node: " << i << " Parent: " << parent[i] << " Rank: " << rank[i] << endl;
            }
        }

};

int main() {
    UnionFind Union(5);
    Union.unite(0, 1);
    Union.unite(1, 2);

    cout << Union.isConnected(0, 2) << endl;
    cout << Union.isConnected(0, 3) << endl;

    Union.print();

    return 0;
}

// What is kruskal's algorithm?
// Kruskal's algorithm is a minimum spanning tree algorithm that finds an edge of the least possible weight that connects any two trees in the forest. It is a greedy algorithm.