#include <iostream>
using namespace std;

class Node {
public:
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BinarySearchTree {
private:
    Node* root; // Pointer to the root of the tree

    // Helper function for insertion
    Node* insert(Node* root, int key) {
        if (root == nullptr) // Base case: Empty tree
            return new Node(key);

        if (key < root->data) // Insert into the left subtree
            root->left = insert(root->left, key);
        else if (key > root->data) // Insert into the right subtree
            root->right = insert(root->right, key);

        return root; // Return the unchanged root
    }

    // Helper function for searching
    bool treeSearch(Node* root, int key) {
        if (root == nullptr) // Base case: Key not found
            return false;

        if (root->data == key) // Key found
            return true;

        if (key < root->data) // Search in left subtree
            return treeSearch(root->left, key);

        return treeSearch(root->right, key); // Search in right subtree
    }

    // Helper function for in-order traversal
    void inOrder(Node* root) {
        if (root == nullptr) return;
        inOrder(root->left);           // Visit left subtree
        cout << root->data << " ";     // Visit node
        inOrder(root->right);          // Visit right subtree
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr; // Initialize the root as null
    }

    // Function to insert a value into the tree
    void insert(int key) {
        root = insert(root, key);
    }

    // Function to search for a key in the tree
    bool search(int key) {
        return treeSearch(root, key);
    }

    // Function to print the tree in sorted order
    void display() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst; // Create an object of BinarySearchTree

    // Insert values into the tree
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);

    // Display the tree
    bst.display();

    // Search for keys
    int key = 7;
    if (bst.search(key))
        cout << "Key " << key << " found in the tree." << endl;
    else
        cout << "Key " << key << " not found in the tree." << endl;

    key = 15;
    if (bst.search(key))
        cout << "Key " << key << " found in the tree." << endl;
    else
        cout << "Key " << key << " not found in the tree." << endl;

    return 0;
}


// #include <iostream>
// using namespace std;

// // Node structure
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int value) {
//         data = value;
//         left = right = nullptr;
//     }
// };

// // Insert a node into BST
// Node* insert(Node* root, int key) {
//     if (root == nullptr) 
//         return new Node(key);

//     if (key < root->data)
//         root->left = insert(root->left, key);
//     else if (key > root->data)
//         root->right = insert(root->right, key);

//     return root;
// }

// // Search a key in BST
// bool treeSearch(Node* root, int key) {
//     if (root == nullptr) 
//         return false;

//     if (root->data == key)
//         return true;

//     if (key < root->data)
//         return treeSearch(root->left, key);

//     return treeSearch(root->right, key);
// }

// int main() {
//     Node* root = nullptr;
//     root = insert(root, 10);
//     insert(root, 5);
//     insert(root, 20);
//     insert(root, 3);
//     insert(root, 7);

//     int key = 7;
//     if (treeSearch(root, key))
//         cout << "Element found in the tree!" << endl;
//     else
//         cout << "Element not found in the tree!" << endl;

//     return 0;
// }
