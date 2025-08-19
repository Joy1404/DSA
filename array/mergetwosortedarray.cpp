#include<bits/stdc++.h>
using namespace std;
// brute force
// time complexity: O(n + m)
// space complexity: O(n + m)
// it is based on checking each element of both arrays
// we can also use a two pointer approach
void mergesortedarray(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < arr1.size()) {
        arr3[k++] = arr1[i++];
    }
    while (j < arr2.size()) {
        arr3[k++] = arr2[j++];
    }
    arr3.resize(k);
    for(int i=0; i<arr3.size(); i++) {
       if(i<arr1.size()) arr1[i] = arr3[i];
       else arr2[i-arr1.size()] = arr3[i];
    }
}
// optimal approach with no extra space
void mergetwosortedarrayoptimal1(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int n = arr1.size();
    int m = arr2.size();
    int left = n - 1, right = 0;
    while(left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        } else {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
// optimal 2
// this is based on the gap method
// The idea is to use a gap to compare elements in the two arrays
// If the elements are out of order, we swap them
// time complexity: O(log(n + m))
void swapIfgreater(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
    if (arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}
void mergetwosortedarrayoptimal2(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
   int len = n + m;
   int gap = (len) / 2 + (len % 2);
   while (gap > 0) {
       int left = 0, right = left + gap;
       while (right < len) {
        // Compare elements in the two arrays
           if (left < n && right >= n) {
                swapIfgreater(arr1, arr2, left, right - n);
           }
           // arr2 and arr2
           else if(left>=n){
               swapIfgreater(arr2, arr2,left-n, right - n);
           }
           // arr1 and arr1
           else{
               swapIfgreater(arr1, arr1, left, right);
           }
           left++;
           right++;
       }
       if(gap == 1) {
           break; // No need to reduce gap further
       }
       gap = gap / 2 + (gap % 2);
   }
}
int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> arr3(arr1.size() + arr2.size());
    
    mergesortedarray(arr1, arr2, arr3);
    
    cout << "Merged Sorted Array: ";
    for (int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    return 0;
}