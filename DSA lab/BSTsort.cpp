#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal (gives sorted order)
void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int arr[] = {7, 3, 9, 1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;

    // Insert elements into BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Sorted numbers using BST: ";
    inOrder(root);  // Sorted output
    cout << endl;

    return 0;
}
