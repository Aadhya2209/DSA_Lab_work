#include <iostream>
using namespace std;

// Node structure
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

// Inorder traversal (prints BST in sorted order)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Construct the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    // Print inorder traversal
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
