#include <iostream>
using namespace std;
template <typename T>
struct Node 
{
    T data ;
    Node * next = nullptr;
    Node (T d):data(d){};
};
template <typename T>
class Queue 
{
private:
Node<T> * front =nullptr ;
Node<T> * rear = nullptr ;

public :
bool isEmpty () {
    return (front == nullptr) ;
}
void enqueue(T d)
{
    Node<T>* newNode = new Node<T>(d);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
T dequeue()
{
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return T(); // value default
    }

    Node<T>* temp = front;
    T value = temp->data;

    front = front->next;
    delete temp;

    if (front == nullptr)
        rear = nullptr;

    return value;
}
T peek() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return T();
    }
    return front->data;
}


};


int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.peek()    << endl; // 30
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Queue is Empty

    return 0;
}
