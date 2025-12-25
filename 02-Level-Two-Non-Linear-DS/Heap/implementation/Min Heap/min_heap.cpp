#include<iostream>
#include<min_heap.h>
using namespace std;

int main(){
    MinHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    h.printHeap();    
    cout << h.getMin() << endl;  

    h.extractMin();
    h.printHeap();  

    return 0;
}