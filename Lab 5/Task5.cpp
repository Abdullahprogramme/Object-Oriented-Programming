#include <iostream>
#include <string>
#include <vector>

using namespace std;


class State {
    private:
        bool isFinal; // A flag to check if the state is final.
        State* t0; // Transition on input 0.
        State* t1; // Transition on input 1.

    public:
        // Constructor to initialize the state.
        State(bool isFinal) {
            this->isFinal = isFinal;
            this->t0 = nullptr;
            this->t1 = nullptr;
        }

        // Marks the state as a final state
        void setFinal() {
            this->isFinal = true;
        }  

        // Sets the transition for input 0.
        void setTransition0(State* s) {
            this->t0 = s;
        }

        // Sets the transition for input 1.
        void setTransition1(State* s) {
            this->t1 = s;
        }

        // Returns the state transitioned to on input 0
        State* getTransition0() {
            return this->t0;
        }

        // Returns the state transitioned to on input 1
        State* getTransition1() {
            return this->t1;
        }

        // Returns true if the state is final, otherwise false.
        bool isFinalState() {
            return this->isFinal;
        }
};

class DFA {
    private:
        vector<State*> states; // Vector to store all the states.
        State* q0; // pointer to the initial state.

    public:
        // Constructor to initialize the DFA.
        DFA( int n = 0 ) {
            for (int i = 0; i < n; i++) {
                states.push_back(new State(false));
            }
            q0 = states[0];
        }

        // Destructor to free the memory allocated for the states.
        ~DFA() {
            for (int i = 0; i < states.size(); i++) {
                delete states[i];
            }
        }

        // Adds a new state to the DFA
        void addState() {
            states.push_back(new State(false));
        }

        // Adds a transition from state from to state to on character c
        void addTransition(int from, char c, int to) {
            if (c == '0') {
                states[from]->setTransition0(states[to]);
            } else {
                states[from]->setTransition1(states[to]);
            }
        }

        // Marks state i as a final state
        void setFinalState(int i) {
            states[i]->setFinal();
        }

        // Sets state i as the start state
        void setStart(int i) {
            q0 = states[i];
        }

        // Returns true if all states have transitions and a start state is set
        bool isComplete() {
            for (int i = 0; i < states.size(); i++) {
                if (states[i]->getTransition0() == nullptr || states[i]->getTransition1() == nullptr) {
                    return false;
                }
            }
            return q0 != nullptr;
        }

        // Returns true if the DFA accepts the input string s
        bool accepts(const string& s) const {
            State* current = q0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '0') {
                    current = current->getTransition0();
                } else {
                    current = current->getTransition1();
                }
            }
            return current->isFinalState();
        }
};

int main() {
    DFA dfa(3);
    dfa.addTransition(0, '1', 0);
    dfa.addTransition(0, '0', 1);
    dfa.addTransition(1, '1', 0);
    dfa.addTransition(1, '0', 2);
    dfa.addTransition(2, '0', 2);
    dfa.addTransition(2, '1', 2);

    dfa.setFinalState(2);
    dfa.setStart(0);

    cout << "DFA is " << (dfa.isComplete() ? "" : "not ") << "complete" << endl;

    cout << "DFA " << (dfa.accepts("101") ? "accepts" : "rejects") << " the string 101" << endl;
    cout << "DFA " << (dfa.accepts("100") ? "accepts" : "rejects") << " the string 100" << endl;
    cout << "DFA " << (dfa.accepts("1001") ? "accepts" : "rejects") << " the string 1001" << endl;
    cout << "DFA " << (dfa.accepts("1000") ? "accepts" : "rejects") << " the string 1000" << endl;

    return 0;
}