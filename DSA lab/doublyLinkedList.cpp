#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, head};
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node with given value
void deleteNode(Node*& head, int value) {
    Node* temp = head;

    while (temp && temp->data != value)
        temp = temp->next;

    if (!temp) {
        cout << "Value not found!\n";
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;  // deleting head

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display the list
void displayList(Node* head) {
    cout << "Doubly Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 20);
    insertAtEnd(head, 25);

    displayList(head);

    deleteNode(head, 10);
    displayList(head);

    deleteNode(head, 100); // not in list

    return 0;
}
