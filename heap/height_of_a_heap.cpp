#include<bits/stdc++.h>
using namespace std;
// problem statement : Find the height of a heap given the number of nodes in it. return the longest path from root to leaf node.
int height_of_heap(int n) {
    if (n <= 0) return -1; // Height of an empty heap is defined as -1
    if(n == 1) return 1; // Height of a heap with one node is 1
    // return floor(log2(n)) + 1; // Height calculation
    int height = 0;
    while(n > 1) {
        n = n / 2;
        height++;
    }   
    return height; // return log2(n);
}
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Height of the heap is: " << height_of_heap(n) << endl;
    return 0;
}