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

// Insert into BST
Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Search for a key in BST
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key)
        return true;
    else if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Driver code
int main() {
    Node* root = nullptr;
    int keys[] = { 50, 30, 20, 40, 70, 60, 80 };
    for (int key : keys)
        root = insert(root, key);

    int target = 40;
    if (search(root, target))
        cout << "Key " << target << " found in BST." << endl;
    else
        cout << "Key " << target << " not found in BST." << endl;

    return 0;
}
