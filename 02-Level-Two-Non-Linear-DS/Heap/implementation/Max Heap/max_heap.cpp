#include<iostream>
#include<max_heap.h>
using namespace std;

int main(){
    MaxHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    h.printHeap();      
    cout << h.getMax();  

    h.extractMax();
    h.printHeap();        

    return 0;

}