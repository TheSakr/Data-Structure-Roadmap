#include <iostream>
#include <vector>
#ifndef MAX_HEAP_H
#define MAX_HEAP_H
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    //(after insertion)
    void heapifyUp(int index) {
        if (index == 0) return;

        int parent = (index - 1) / 2;

        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    //(after deletion)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove maximum
    void extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    //maximum 
    int getMax() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    //Print
    void printHeap() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};
#endif MAX_HEAP_H