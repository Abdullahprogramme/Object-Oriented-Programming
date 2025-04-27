#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <vector>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        // Node structure for the binary tree
        struct Node {
            T value;
            unique_ptr<Node> left;
            unique_ptr<Node> right;

            Node(T val) : value(val), left(nullptr), right(nullptr) {}
        };

        unique_ptr<Node> root;

        // Helper function for in-order traversal
        void in_order_traversal_helper(const Node* node, vector<T>& result) const {
            if (!node) return;
            in_order_traversal_helper(node->left.get(), result);
            result.push_back(node->value);
            in_order_traversal_helper(node->right.get(), result);
        }

        // Helper function to clear the tree
        void clear_helper(unique_ptr<Node>& node) {
            if (node) {
                clear_helper(node->left);
                clear_helper(node->right);
                node.reset(); // Deletes the node
            }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree
    void insert(const T& value) {
        if (!root) {
            root = make_unique<Node>(value);
        } else {
            Node* current = root.get();
            while (true) {
                if (value < current->value) {
                    if (!current->left) {
                        current->left = make_unique<Node>(value);
                        break;
                    }
                    current = current->left.get();
                } else {
                    if (!current->right) {
                        current->right = make_unique<Node>(value);
                        break;
                    }
                    current = current->right.get();
                }
            }
        }
    }

    // Perform in-order traversal and return the values in a vector
    vector<T> in_order_traversal() const {
        vector<T> result;
        in_order_traversal_helper(root.get(), result);
        return result;
    }

    // Clear the tree
    void clear() {
        clear_helper(root);
        root.reset();
    }

    // Operator() to insert values from a vector and return sorted values
    void operator()(vector<T>& values) {
        for (const T& value : values) {
            insert(value);
        }
        values = in_order_traversal();
    }

    // Destructor to ensure all nodes are cleared
    ~BinaryTree() {
        clear();
    }
};

#endif // Binary_tree_hpp