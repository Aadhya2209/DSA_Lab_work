#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Ordered Linked List class
class OrderedLinkedList {
    Node* head;

public:
    OrderedLinkedList() {
        head = nullptr;
    }

    // Insert in ascending order
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};

        // Insert at beginning or before head
        if (!head || value < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;

            // Find correct position
            while (current->next && current->next->data < value) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Inserted: " << value << " ✅\n";
    }

    // Delete a node
    void remove(int value) {
        if (!head) {
            cout << "List is empty ❌\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted: " << value << " ✅\n";
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (!current->next) {
            cout << "Value not found ❌\n";
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Deleted: " << value << " ✅\n";
        }
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty 💤\n";
            return;
        }

        Node* temp = head;
        cout << "Ordered List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~OrderedLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    OrderedLinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! 🚫\n";
        }
    } while (choice != 4);

    return 0;
}
