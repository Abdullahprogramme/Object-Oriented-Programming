#ifndef Task1_hpp
#define Task1_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;    

// A binary tree class which stores words and their frequencies
class Node {
    public:
        string word;
        int frequency;
        Node* left;
        Node* right;


        // Constructor
        Node(string w) : word(w), frequency(1), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        Node* root;

        void insert(Node*& node, const string& word) {
            if (node == nullptr) {
                node = new Node(word);
            } else if (word < node->word) {
                insert(node->left, word);
            } else if (word > node->word) {
                insert(node->right, word);
            } else {
                node->frequency++;
            }
        }

        vector<string> top_or_bottom_k(int k, bool top) const {
            vector<pair<string, int>> word_freqs;
            Node* current = root;

            // In-order traversal to collect words and their frequencies
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                word_freqs.push_back({node->word, node->frequency});
                inOrder(node->right);
            };

            inOrder(current);

            // Sort the words by frequency
            sort(word_freqs.begin(), word_freqs.end(), [top](const pair<string, int>& a, const pair<string, int>& b) {
                return (top) ? (a.second > b.second) : (a.second < b.second);
            });

            // Collect the top or bottom k words
            vector<string> result;
            for (int i = 0; i < k && i < word_freqs.size(); ++i) {
                result.push_back(word_freqs[i].first);
            }

            return result;
        }

    
    public:
        BinaryTree(string& path) : root(nullptr) {
            ifstream file(path);
            
            if (!file.is_open()) {
                cerr << "Error opening file: " << path << endl;
                return;
            }

            // using sstream to read the file line by line
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string word;
                while (ss >> word) {
                    // Remove digits
                    word.erase(remove_if(word.begin(), word.end(), ::isdigit), word.end());
                    // Remove spaces
                    word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
                    // Remove punctuation
                    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
                    // Convert to lowercase
                    transform(word.begin(), word.end(), word.begin(), ::tolower);

                    // Check if the word is empty after all processing
                    if (word.empty()) continue;

                    insert(root, word);
                }
            }

            file.close();
        }

        int getFrequency(const string& word) const {
            Node* current = root;
            while (current != nullptr) {
                if (word < current->word) {
                    current = current->left;
                } else if (word > current->word) {
                    current = current->right;
                } else {
                    return current->frequency;
                }
            }
            return 0; // Word not found
        }

        bool containsWord(const string& word) const {
            return getFrequency(word) > 0;
        }

        int getTotalWordCount() const {
            Node* current = root;

            int count = 0;

            // In-order traversal to count the total number of words
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                count += node->frequency;
                inOrder(node->right);
            };

            inOrder(current);
            return count;
        }

        // Lexicographically exported in the file
        void exportToFile(const string& path) const {
            ofstream file(path);
            if (!file.is_open()) {
                cerr << "Error opening file: " << path << endl;
                return;
            }

            // In-order traversal to write the words and their frequencies to the file
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                // Write the word and its frequency to the file in format: word<TAB><TAB>count 
                file << node->word << "\t\t" << node->frequency << endl;
                inOrder(node->right);
            };

            inOrder(root);
            file.close();
        }

        vector<string> starts_with(const string& prefix) const {
            vector<string> result;
            Node* current = root;

            // In-order traversal to find words starting with the given prefix
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                if (node->word.find(prefix) == 0) {
                    result.push_back(node->word);
                }
                inOrder(node->right);
            };

            inOrder(current);
            return result;
        }

        vector<string> most_frequent() const {
            vector<string> result;
            Node* current = root;

            // In-order traversal to find the most frequent words
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                if (result.empty() || node->frequency > getFrequency(result[0])) {
                    result.clear();
                    result.push_back(node->word);
                } else if (node->frequency == getFrequency(result[0])) {
                    result.push_back(node->word);
                }
                inOrder(node->right);
            };

            inOrder(current);
            return result;
        }

        vector<string> longest_word() const {
            vector<string> result;
            Node* current = root;

            // In-order traversal to find the longest words
            function<void(Node*)> inOrder = [&](Node* node) {
                if (node == nullptr) return;
                inOrder(node->left);
                if (result.empty() || node->word.length() > result[0].length()) {
                    result.clear();
                    result.push_back(node->word);
                } else if (node->word.length() == result[0].length()) {
                    result.push_back(node->word);
                }
                inOrder(node->right);
            };

            inOrder(current);
            return result;
        }

        vector<string> top_k(int k) const {
            return top_or_bottom_k(k, true);
        }

        vector<string> bottom_k(int k) const {
            return top_or_bottom_k(k, false);
        }

        ~BinaryTree() {
            // Destructor to free memory
            function<void(Node*)> deleteTree = [&](Node* node) {
                if (node == nullptr) return;
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
            };
            deleteTree(root);
        }

};

#endif /* Task1_hpp */

int main() {
    string path = "shakespeare.txt";
    BinaryTree tree(path);

    // Example usage
    cout << "Total word count: " << tree.getTotalWordCount() << endl;
    cout << "Frequency of 'example': " << tree.getFrequency("example") << endl;
    cout << "Contains 'example': " << (tree.containsWord("example") ? "Yes" : "No") << endl;

    vector<string> top_k_words = tree.top_k(5);
    cout << "Top 5 words: ";
    for (const string& word : top_k_words) {
        cout << word << " ";
    }
    cout << endl;

    vector<string> bottom_k_words = tree.bottom_k(5);
    cout << "Bottom 5 words: ";
    for (const string& word : bottom_k_words) {
        cout << word << " ";
    }
    cout << endl;

    vector<string> starts_with_a = tree.starts_with("a");
    cout << "Words starting with 'a': ";
    for (const string& word : starts_with_a) {
        cout << word << " ";
    }
    cout << endl;

    vector<string> most_frequent_words = tree.most_frequent();
    cout << "Most frequent words: ";
    for (const string& word : most_frequent_words) {
        cout << word << " ";
    }
    cout << endl;

    vector<string> longest_words = tree.longest_word();
    cout << "Longest words: ";
    for (const string& word : longest_words) {
        cout << word << " ";
    }
    cout << endl;

    // Export to file
    tree.exportToFile("output.txt");

    return 0;
}