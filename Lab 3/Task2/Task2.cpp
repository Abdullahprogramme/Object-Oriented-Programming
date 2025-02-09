#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        string url;
        Node* next;

        Node(string url) {
            this->url = url;
            this->next = nullptr;
        }
};

class BrowserHistory {
    private:
        Node* head; // Oldest page in history
        Node* tail; // Newest page in history
        Node* current; // Current page in navigation

    public:

        BrowserHistory() {
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }

        // Destructor to free memory
        ~BrowserHistory() {
            Node* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void visitPage(const string& url) {
            Node* newNode = new Node(url);
            if (tail != nullptr) {
                tail->next = newNode;
            } else {
                head = newNode;
            }
            tail = newNode;
            current = newNode;
        }

        // Moves the current pointer backwards by one page
        Node* goBack() {
            if (current == head) {
                return nullptr;
            }
            
            // going back to the previous page
            Node* temp = head;
            while (temp->next != current) {
                temp = temp->next;
            }

            current = temp;

            // printing the url
            cout << "current URL: https://" << current->url << endl;

            return current;
        }

        // Prints all URLs from oldest to newest, marking the current page with [CURRENT]
        void displayHistory() const {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp == current) {
                    cout << temp->url << " [CURRENT]" << endl;
                } else {
                    cout << temp->url << endl;
                }
                temp = temp->next;
            }
        }
};

int main() {
    BrowserHistory browserHistory;
    browserHistory.visitPage("https://google.com");
    browserHistory.visitPage("https://github.com");
    browserHistory.visitPage("https://stackoverflow.com");

    browserHistory.displayHistory();

    browserHistory.goBack();
    browserHistory.displayHistory();

    browserHistory.goBack();
    browserHistory.displayHistory();

    return 0;
}