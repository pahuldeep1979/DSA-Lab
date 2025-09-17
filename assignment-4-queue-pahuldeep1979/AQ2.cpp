/* Roll no :1024030982 , assignment completed */
//Q2. menu-driven Circular Queue in C++
#include <iostream>
using namespace std;

const int MAX = 10;  // capacity of the circular queue

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() const {
        return (front == -1);
    }

    bool isFull() const {
        return (!isEmpty() && ((rear + 1) % MAX == front));
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow: Queue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
        cout << "Enqueued: " << x << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow: Queue is empty.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) {
            // removing last element â†’ queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        int i = front;
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << "  ";
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n===== CIRCULAR QUEUE (Array) =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front)\n";
        cout << "4. isEmpty?\n";
        cout << "5. isFull?\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            return 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                if (cin >> value) q.enqueue(value);
                else { cout << "Invalid input.\n"; return 0; }
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                cout << (q.isEmpty() ? "Yes, queue is empty.\n" : "No, queue is not empty.\n");
                break;

            case 5:
                cout << (q.isFull() ? "Yes, queue is full.\n" : "No, queue is not full.\n");
                break;

            case 6:
                q.display();
                break;

            case 0:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Please choose a valid option (0-6).\n";
        }
    }
}
