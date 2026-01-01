#include<iostream>
#ifndef HEAP_H
#define HEAP_H
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    //(after insertion)
    void heapifyUp(int index) {
        if (index == 0) return;

        int parent = (index - 1) / 2;

        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    //(after deletion)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Insert element
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove minimum element
    void extractMin() {
        if (heap.empty()) {

            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get minimum element
    int getMin() {

        if (heap.empty()) return -1;

        return heap[0];
    }

    // Print
    void printHeap() {
        for (int x : heap)

            cout << x << " ";

        cout << endl;
    }
};
#endif