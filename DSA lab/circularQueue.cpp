#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
            cout << "Queue is Full 🔄\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = value;
        cout << value << " enqueued ✅\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty ❌\n";
            return;
        }

        cout << "Dequeued: " << items[front] << endl;

        if (front == rear) {
            // Only one element was in the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty 💤\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
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
