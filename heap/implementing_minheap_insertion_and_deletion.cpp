#include<bits/stdc++.h>
using namespace std;
class MinHeap {
    int *arr;
    int size; // total number of elements present in the heap
    int total_size; // maximum capacity of the heap
   

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (arr[index] < arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && arr[leftChild] < arr[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && arr[rightChild] < arr[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
 MinHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n ;
    }
    void insert(int val) {
        if (size == total_size) {
            cout << "Heap Overflow" << endl;
            return;
        }
        int index = size;
        arr[size] = val;
        size++;
        heapifyUp(index);
        cout << "Inserted " << val << " into the heap" << endl;
    }
    void deleteMin() {
        if (size == 0) {
            cout << "Heap Underflow" << endl;
            return;
        }
        int minVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        if(size==0){
            cout << "Deleted " << minVal << " from the heap" << endl;
            return;
        }
        heapifyDown(0);
        cout << "Deleted " << minVal << " from the heap" << endl;
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    MinHeap h(10);
    h.insert(10);
    h.insert(4);
    h.insert(14);
    h.insert(11);
    h.printHeap();
    h.deleteMin();
    h.deleteMin();
    h.deleteMin();
    h.printHeap(); 
    h.insert(114);
    h.insert(24);
    h.insert(1);
    h.printHeap(); // Expected output: 1 24 114
    h.deleteMin();
    return 0;
}