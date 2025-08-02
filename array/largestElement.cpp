#include<bits/stdc++.h>
using namespace std;

//brute force solution to find the largest element in an array
// int main(){
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
//     int largest = arr[n - 1]; // The last element after sorting is the largest
//     cout << "The largest element is: " << largest << endl;
//     return 0;
// }
// optimal solution to find the largest element in an array
// Time complexity: O(n)
// Space complexity: O(1)
// This program finds the largest element in an array of integers.
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "The largest element is: " << largest << endl;
    return 0;
}