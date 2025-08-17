#include<bits/stdc++.h>
using namespace std;

int countsubarrayswithxorkbrute(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int curr_xor = 0;
            for (int k = i; k <= j; k++) {
                curr_xor ^= arr[k];
            }
            if (curr_xor == k) {
                count++;
            }
        }
    }
    return count;
}
int countsubarraysumwithxorkbetter(vector<int>&arr, int k){
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int curr_xor = 0;
        for (int j = i; j < n; j++) {
            curr_xor ^= arr[j];
            if (curr_xor == k) {
                count++;
            }
        }
    }
    return count;
}
int countsubarraysumwithxorkoptimised(vector<int>&arr, int k){
    int n = arr.size();
    int count = 0;
    int curr_xor = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        curr_xor ^= arr[i];
        if (curr_xor == k) {
            count++;
        }
        if (freq.find(curr_xor ^ k) != freq.end()) {
            count += freq[curr_xor ^ k]; // x = xr ^ k
        }
        freq[curr_xor]++;
    }
    return count;
}

int main() {
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    cout << countsubarrayswithxorkbrute(arr, k) << endl;
    cout << countsubarraysumwithxorkbetter(arr, k) << endl;
    return 0;
}