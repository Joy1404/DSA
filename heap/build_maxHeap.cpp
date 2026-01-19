#include<bits/stdc++.h>
using namespace std;

// function to heapify a subtree rooted with node i which is an index in arr[].
// n is size of heap
// This function assumes that the subtrees are already heapified
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursive stack space
void heapify(int arr[], int n, int i){
    int largest=i; // assume root is largest
    int left=2*i+1; // left child index
    int right=2*i+2; // right child index

    // check if left child is larger than root
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }

    // check if right child is larger than largest so far
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    // if largest is not root
    if(largest!=i){
        swap(arr[i],arr[largest]);
        // recursively heapify the affected sub-tree
        heapify(arr,n,largest);
    }
}
// time complexity of BuildMaxHeap is O(n)
//  space complexity is O(1)
void BuildMaxHeap(int arr[], int n){
    // step down approach
    // start from the last non-leaf node and heapify each node
    // last non-leaf node = n/2 -1
    for(int i=n/2-1;i>=0;i--){
     heapify(arr,n,i);
    }
}
void printHeap(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    printHeap(arr,10);
}