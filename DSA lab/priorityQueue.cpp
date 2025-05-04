#include <iostream>
using namespace std;

#define SIZE 5

struct Element {
    int value;
    int priority;
};

class PriorityQueue {
    Element queue[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    // Insert element based on priority
    void enqueue(int value, int priority) {
        if (count == SIZE) {
            cout << "Queue is Full ❌\n";
            return;
        }

        int i;
        for (i = count - 1; i >= 0 && queue[i].priority > priority; i--) {
            queue[i + 1] = queue[i];
        }
        queue[i + 1].value = value;
        queue[i + 1].priority = priority;
        count++;

        cout << "Inserted: " << value << " with priority " << priority << " ✅\n";
    }

    // Remove the element with the highest priority
    void dequeue() {
        if (count == 0) {
            cout << "Queue is Empty ❌\n";
            return;
        }

        cout << "Dequeued: " << queue[0].value << " (Priority " << queue[0].priority << ")\n";

        for (int i = 1; i < count; i++) {
            queue[i - 1] = queue[i];
        }
        count--;
    }

    // Display all elements
    void display() {
        if (count == 0) {
            cout << "Queue is Empty 💤\n";
            return;
        }

        cout << "Priority Queue (value:priority): ";
        for (int i = 0; i < count; i++) {
            cout << queue[i].value << ":" << queue[i].priority << "  ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, priority;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value and priority: ";
                cin >> value >> priority;
                pq.enqueue(value, priority);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
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
