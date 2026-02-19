#include <iostream>
#include <array>

using namespace std;

class Priority_Queue {
    private:
        array<pair<int, int>, 5> arr;
        int size;
        int count;

    public:
        Priority_Queue() {
            size = 5;
            count = 0;
        }

        bool isFull() {
            return (count == size);
        }

        bool isEmpty() {
            return (count == 0);
        }

        void enqueue(int x, int p) {
            if (isFull()) {
                cout << "Queue is full" << endl;
            } else {
                int i = count - 1;
                while (i >= 0 && arr[i].second > p) {
                    arr[i + 1] = arr[i];
                    i--;
                }
                arr[i + 1] = make_pair(x, p);
                count++;
            }
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                count--;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "(" << arr[i].first << ", P:" << arr[i].second << ") ";
                }
                cout << endl;
            }
        }

        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            } else {
                return arr[0].first;
            }
        }
};

int main() {
    Priority_Queue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.display();
    pq.dequeue();
    pq.display();
    cout << pq.peek() << endl;
    return 0;
}
