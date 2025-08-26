#include<bits/stdc++.h>
using namespace std;


int firstoccurance(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            ans = mid;
            high = mid - 1; // continue searching in the left half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int lastoccurance(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            ans = mid;
            low = mid + 1; // continue searching in the right half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int countOccurence(vector<int>& arr, int x) {
    int first = firstoccurance(arr, x);
    if (first == -1) {
        return 0; // Element not found
    }
    int last = lastoccurance(arr, x);
    return last - first + 1;
}
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;
    int count = countOccurence(arr, x);
    cout << "Number of occurrences of " << x << " is: " << count << endl;
    return 0;
}
