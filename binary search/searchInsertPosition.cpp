#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1,ans=arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6};
    int target = 4;
    int lb = searchInsertPosition(arr, target);
    cout << "Search insert position of " << target << " is at index: " << lb << endl;
    return 0;
}