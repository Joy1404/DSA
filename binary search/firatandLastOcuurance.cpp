#include<bits/stdc++.h>
using namespace std;

// brute force
pair<int,int> firstAndLastOccurance(vector<int>& arr, int x) {
    int first = -1, last = -1;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == x) {
            if( first == -1 ){
                first = i;
            }
            last = i;
        }
    }
    return make_pair(first, last);
}
// better
int lowerBound(vector<int>& arr, int target) {
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
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1,ans=arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int,int> firstAndLastOccurancebetter(vector<int>& arr, int x) {
    int first = lowerBound(arr, x);
    int last = upperBound(arr, x) - 1;
    if(first == arr.size() || arr[first] != x) {
        return make_pair(-1, -1);
    }
    return make_pair(first, last);
}

//optimal

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

pair<int,int> firstandlastoccurrence(vector<int>& arr, int x) {
    int first = firstoccurance(arr, x);
    if (first == -1) {
        return make_pair(-1, -1); // Element not found
    }
    int last = lastoccurance(arr, x);
    return make_pair(first, last);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 2, 6};
    pair<int,int> result = firstandlastoccurrence(arr, 2);
    cout << "First Occurrence: " << result.first << endl;
    cout << "Last Occurrence: " << result.second << endl;
    return 0;
}