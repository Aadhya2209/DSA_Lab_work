#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

// Insert a key into BST
Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Find minimum value in BST
int findMin(Node* root) {
    if (!root) return -1; // Tree is empty
    while (root->left)
        root = root->left;
    return root->key;
}

// Find maximum value in BST
int findMax(Node* root) {
    if (!root) return -1; // Tree is empty
    while (root->right)
        root = root->right;
    return root->key;
}

// Driver code
int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int key : keys)
        root = insert(root, key);

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}
