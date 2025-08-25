#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1, ans=-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1, ans=arr.size();
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
    int floorIndex = findFloor(arr, target);
    int ceilIndex = findCeil(arr, target);
    cout << "Floor of " << target << " is at index: " << floorIndex << endl;
    cout << "Ceil of " << target << " is at index: " << ceilIndex << endl;
    return 0;
}