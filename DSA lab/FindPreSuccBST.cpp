#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Utility function to create a new BST node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

// Insert a node in BST
Node* insert(Node* root, int key) {
    if (!root)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Find predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;

    if (root->key == key) {
        // Predecessor is the rightmost in left subtree
        if (root->left) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // Successor is the leftmost in right subtree
        if (root->right) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }
    else if (key < root->key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Driver code
int main() {
    Node* root = nullptr;
    int keys[] = { 50, 30, 20, 40, 70, 60, 80 };
    for (int key : keys)
        root = insert(root, key);

    int target = 65;
    Node* pre = nullptr, *suc = nullptr;
    findPreSuc(root, pre, suc, target);

    cout << "Key: " << target << endl;
    cout << "Predecessor: " << (pre ? to_string(pre->key) : "None") << endl;
    cout << "Successor: " << (suc ? to_string(suc->key) : "None") << endl;

    return 0;
}
