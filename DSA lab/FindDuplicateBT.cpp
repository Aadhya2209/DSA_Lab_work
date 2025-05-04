#include <iostream>
using namespace std;

// Node of a Binary Search Tree
struct Node {
    int data;
    int count;  // to count duplicates
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value == root->data)
        root->count++; // duplicate found
    else if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder traversal to print duplicates
void printDuplicates(Node* root) {
    if (root == NULL)
        return;

    printDuplicates(root->left);

    if (root->count > 1)
        cout << "Duplicate: " << root->data << " (count: " << root->count << ")" << endl;

    printDuplicates(root->right);
}

int main() {
    int arr[] = {5, 3, 8, 3, 10, 5, 2, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Duplicate numbers in the list are:\n";
    printDuplicates(root);

    return 0;
}
