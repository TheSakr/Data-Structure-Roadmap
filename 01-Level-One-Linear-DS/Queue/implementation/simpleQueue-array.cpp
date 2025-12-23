#include <iostream>
using namespace std;
template <typename T>
class QueueArray 
{
private :
    int front ;
    int rear ;
    T * arr  ;
    size_t size ;
public :
    QueueArray (size_t sze ):front(-1),rear(-1),size(sze) {arr = new T[size] ;}
    ~QueueArray() {
    delete[] arr;
    }

    bool isEmpty ()
    {
        return (front == -1) ;
    }
    bool isFull ()
    {
        return (rear == size-1) ;

    }
    void enque (T data)
    {
        if (isFull()) {
            cout << "Queue is Full \n" ;
            return ;
        }
        if (isEmpty()){
            front++ ;
        }
        arr[++rear] = data ;

    }
    T deque ()
    {
        if ( isEmpty() ) {
            cout << "cant deque Queue is Empty \n" ;
            return T() ;
        }
        T value = arr[front];
        front++ ;
        if (front > rear) {
            front = rear = -1 ;
        }
        return value ; 
    }




};

