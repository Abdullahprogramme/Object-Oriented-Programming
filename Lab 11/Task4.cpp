#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Class to store file data
class FileData {
    public:
        string fileName;
        int fileSize;
        string fileType;

        FileData(string name, int size, string type) : fileName(name), fileSize(size), fileType(type) {}

        // Overloaded << operator for printing
        friend ostream& operator<<(ostream& os, const FileData& file) {
            os << "File Name: " << file.fileName << ", File Size: " << file.fileSize << " MB, File Type: " << file.fileType;
            return os;
        }
};

// BST Node class
class BSTNode {
    public:
        FileData data;
        BSTNode* left;
        BSTNode* right;

        BSTNode(FileData d) : data(d), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
    private:
        BSTNode* root;

        // Helper function for insertion
        void insert(BSTNode*& node, FileData data) {
            if (node == nullptr) {
                node = new BSTNode(data);
            } else if (data.fileName < node->data.fileName) {
                insert(node->left, data);
            } else if (data.fileName > node->data.fileName) {
                insert(node->right, data);
            } else {
                throw runtime_error("Duplicate file name: " + data.fileName);
            }
        }

    // Helper function for deletion
    BSTNode* deleteNode(BSTNode* node, const string& fileName) {
        if (node == nullptr) {
            throw runtime_error("File not found: " + fileName);
        }

        if (fileName < node->data.fileName) {
            node->left = deleteNode(node->left, fileName);
        } else if (fileName > node->data.fileName) {
            node->right = deleteNode(node->right, fileName);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            } else {
                // Node with two children
                BSTNode* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data.fileName);
            }
        }
        return node;
    }

    // Helper function to find the minimum node
    BSTNode* findMin(BSTNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for searching
    BSTNode* search(BSTNode* node, const string& fileName) {
        if (node == nullptr || node->data.fileName == fileName) {
            return node;
        }
        if (fileName < node->data.fileName) {
            return search(node->left, fileName);
        }
        return search(node->right, fileName);
    }

    // Helper function for retrieving files with size > threshold
    void retrieveFiles(BSTNode* node, int threshold, vector<FileData>& result) {
        if (node == nullptr) return;

        if (node->data.fileSize > threshold) {
            result.push_back(node->data);
        }
        retrieveFiles(node->left, threshold, result);
        retrieveFiles(node->right, threshold, result);
    }

    // Helper functions for traversals
    void inorder(BSTNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << endl;
        inorder(node->right);
    }

    void preorder(BSTNode* node) {
        if (node == nullptr) return;
        cout << node->data << endl;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(BSTNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << endl;
    }

    // Helper function to delete all nodes (destructor)
    void deleteTree(BSTNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Destructor
    ~BST() {
        deleteTree(root);
    }

    // Insert a new file node
    void insert(FileData data) {
        insert(root, data);
    }

    // Delete a file by name
    void deleteFile(const string& fileName) {
        root = deleteNode(root, fileName);
    }

    // Rename a file
    void renameFile(const string& oldName, const string& newName) {
        BSTNode* node = search(root, oldName);
        if (node == nullptr) {
            throw runtime_error("File not found: " + oldName);
        }
        FileData newData = node->data;
        newData.fileName = newName;
        deleteFile(oldName);
        insert(newData);
    }

    // Search for a file by name
    FileData search(const string& fileName) {
        BSTNode* node = search(root, fileName);
        if (node == nullptr) {
            throw runtime_error("File not found: " + fileName);
        }
        return node->data;
    }

    // Retrieve all files with size > given threshold
    vector<FileData> retrieveFiles(int threshold) {
        vector<FileData> result;
        retrieveFiles(root, threshold, result);
        return result;
    }

    // Traversals
    void inorder() {
        inorder(root);
    }

    void preorder() {
        preorder(root);
    }

    void postorder() {
        postorder(root);
    }
};

// Main function to demonstrate functionality
int main() {
    BST fileSystem;

    try {
        fileSystem.insert(FileData("file1.txt", 10, "txt"));
        fileSystem.insert(FileData("file2.pdf", 20, "pdf"));
        fileSystem.insert(FileData("file3.exe", 5, "exe"));

        cout << "Inorder Traversal:" << endl;
        fileSystem.inorder();

        cout << "\nFiles larger than 10 MB:" << endl;
        vector<FileData> largeFiles = fileSystem.retrieveFiles(10);
        for (const auto& file : largeFiles) {
            cout << file << endl;
        }

        cout << "\nRenaming file2.pdf to file2_renamed.pdf..." << endl;
        fileSystem.renameFile("file2.pdf", "file2_renamed.pdf");

        cout << "\nInorder Traversal after renaming:" << endl;
        fileSystem.inorder();

        cout << "\nDeleting file1.txt..." << endl;
        fileSystem.deleteFile("file1.txt");

        cout << "\nInorder Traversal after deletion:" << endl;
        fileSystem.inorder();
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}