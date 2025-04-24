#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Binary Tree Node structure
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

// Binary Tree class
class BinaryTree {
    private: 
        Node* root;

    public:
        BinaryTree() {
            root = nullptr;
        }

        // Helper function to insert a node in the binary tree
        Node* insert(Node* node, int value) {
            if (node == nullptr) {
                return new Node(value);
            }
            if (value < node->data) {
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }
            return node;
        }

        // Helper function for inorder traversal
        void inorder(Node* node) {
            if (node != nullptr) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }

        // Helper function for preorder traversal
        void preorder(Node* node) {
            if (node != nullptr) {
                cout << node->data << " ";
                preorder(node->left);
                preorder(node->right);
            }
        }

        // Helper function for postorder traversal
        void postorder(Node* node) {
            if (node != nullptr) {
                postorder(node->left);
                postorder(node->right);
                cout << node->data << " ";
            }
        }

        // Helper function to find the height of the tree
        int height(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return max(height(node->left), height(node->right)) + 1;
        }

        // Helper function to delete a node from the binary tree
        Node* deleteNode(Node* node, int value) {
            if (node == nullptr) {
                return node;
            }
            if (value < node->data) {
                node->left = deleteNode(node->left, value);
            } else if (value > node->data) {
                node->right = deleteNode(node->right, value);
            } else {
                // Node with only one child or no child
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                // Node with two children: Get the inorder successor (smallest in the right subtree)
                Node* temp = minValueNode(node->right);
                node->data = temp->data; // Copy the inorder successor's content to this node
                node->right = deleteNode(node->right, temp->data); // Delete the inorder successor
            }
            return node;
        }

        // Helper function to find the node with minimum value in a given tree
        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        // Helper function to find the node with maximum value in a given tree
        Node* maxValueNode(Node* node) {
            Node* current = node;
            while (current && current->right != nullptr) {
                current = current->right;
            }
            return current;
        }
};

int main() {
    BinaryTree tree;
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 70);
    tree.insert(root, 60);
    tree.insert(root, 80);

    // Print inorder traversal of the binary tree
    cout << "Inorder traversal: ";
    tree.inorder(root);
    cout << endl;

    // Print preorder traversal of the binary tree
    cout << "Preorder traversal: ";
    tree.preorder(root);
    cout << endl;

    // Print postorder traversal of the binary tree
    cout << "Postorder traversal: ";
    tree.postorder(root);
    cout << endl;

    // Find the height of the binary tree
    cout << "Height of the binary tree: " << tree.height(root) << endl;

    // Delete a node from the binary tree
    root = tree.deleteNode(root, 20);
    cout << "Inorder traversal after deletion: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}