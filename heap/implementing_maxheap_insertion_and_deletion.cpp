#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int *arr;
    int size; // total number of elements present in the heap
    int total_size; // maximum capacity of the heap
public:
    MaxHeap(int n){
        arr= new int[n];
        size =0;
        total_size = n;
    }
    // insertion in a max heap
    void insert(int val){
        // check for overflow
        if(size==total_size){   
            cout<<"Heap Overflow"<<endl;
            return;
        }
        arr[size]=val; // insert at the end
        int index = size;
        size++;
        // bubble up the inserted element to maintain heap property
        // parent index = (index-1)/2
        // keep swapping until we reach root or parent is greater than or equal to current element
        while(index>0){
            int parent = (index-1)/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                cout<<"Inserted "<<arr[index]<<" into the heap"<<endl;
                return;
            }
        }
        cout<<"Inserted "<<arr[index]<<" into the heap"<<endl;
    }
    void heapify(int index){
        // largest will store the index of largest element among root, left child and right child
        // left child index = 2*index +1
        // right child index = 2*index +2
        // if largest is not root, swap and continue heapifying
        // down the affected subtree
        // base case is when index is a leaf node
        // leaf nodes are present from index size/2 to size-1
        // so if index >= size/2, return
        // if(index>=size/2){
        //     return;
        // }
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        if(left<size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest = right;
        }
        if(largest!=index){
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }
    void Delete(){
        if(size==0){
            cout<<"Heap Underflow"<<endl;
            return;
        }
        cout<<"Deleted "<<arr[0]<<" from the heap"<<endl;
        arr[0]=arr[size-1]; // replace root with last element
        size--;
        if(size==0) return;
        // bubble down the root element to maintain heap property
        heapify(0);
    }
    void printHeap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap h(10);
    h.insert(4);
    h.insert(14);
    h.insert(11);
    h.Delete();
    h.printHeap();
    h.insert(114);
    h.insert(24);
    h.insert(1);
    h.Delete();
    h.Delete();
    h.Delete();
    h.printHeap(); 
    h.Delete();
    // h.insert(20);
    // h.insert(15);
    // h.insert(30);
    // h.insert(40);
    // h.insert(10);
    // h.printHeap(); // Expected output: 40 30 20 15 10
    return 0;
}