#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    int front;
    int rear;
    size_t size;
    T* arr;

public:
    CircularQueue(size_t sze)
        : front(-1), rear(-1), size(sze) {
        arr = new T[size];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(T data) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return T();
        }

        T value = arr[front];

        if (front == rear) {
            // last element removed
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return value;
    }

    T getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return T();
        }
        return arr[front];
    }
};
