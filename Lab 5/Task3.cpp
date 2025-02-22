#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Base Class: Cache
class Cache {
    protected:
        int capacity;
        list<int> currentItems;

    public:
        Cache(int max) : capacity(max) {}

        // Pure virtual function
        virtual void addItem(int item) = 0;

        void printCache() {
            for (int item : currentItems) {
                cout << item << " ";
            }
            cout << endl;
        }
};

// Derived Class: FIFOCache
class FIFOCache : public Cache {
    public:
        FIFOCache(int max) : Cache(max) {}

        // Overriding the pure virtual function
        void addItem(int item) override {
            if (currentItems.size() >= capacity) {
                currentItems.pop_front();
            }
            currentItems.push_back(item);
        }
};

// Derived Class: LRUCache
class LRUCache : public Cache {
    unordered_map<int, list<int>::iterator> itemMap;

    public:
        LRUCache(int max) : Cache(max) {}

        // Overriding the pure virtual function
        void addItem(int item) override {
            if (itemMap.find(item) != itemMap.end()) {
                currentItems.erase(itemMap[item]);
            } else if (currentItems.size() >= capacity) {
                int last = currentItems.back();
                currentItems.pop_back();
                itemMap.erase(last);
            }
            currentItems.push_front(item);
            itemMap[item] = currentItems.begin();
        }
};

int main() {
    FIFOCache fifoCache(3);
    cout << "FIFO Cache:" << endl;
    fifoCache.addItem(1);
    fifoCache.addItem(2);
    fifoCache.addItem(3);
    fifoCache.printCache(); // Output: 1 2 3
    fifoCache.addItem(4);
    fifoCache.printCache(); // Output: 2 3 4

    cout << "LRU Cache:" << endl;

    LRUCache lruCache(3);
    lruCache.addItem(1);
    lruCache.addItem(2);
    lruCache.addItem(3);
    lruCache.printCache(); // Output: 3 2 1
    lruCache.addItem(4);
    lruCache.printCache(); // Output: 4 3 2
    lruCache.addItem(2);
    lruCache.printCache(); // Output: 2 4 3

    return 0;
}