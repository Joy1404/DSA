#include<iostream>
#include<unordered_map>
using namespace std;
// brute force approach
// time complexity: O(n^2)
// it is based on counting the occurrences of each element
int majorityelement(int arr[], int n){
    int cnt;
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt > n/2){
            return arr[i];
        }

    }
    return -1;
}
//better approach
// time complexity: O(nlogn)
//using hashing
int majorityelement(int arr[], int n){
    unordered_map<int, int> countMap;
    for(int i = 0; i < n; i++){
        countMap[arr[i]]++;
    }
    for(auto it : countMap){
        if(it.second > n / 2){
            return it.first;
        }
    }
    return -1;
}
// optimal approach
// time complexity: O(n)
//using Boyer-Moore Voting Algorithm
// it works by maintaining a count of the current candidate for majority element
int majorityelement(int arr[], int n){
    int cnt=0,el;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt=1;
            el = arr[i];
        }else if(el == arr[i]){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i] == el){
            cnt1++;
        }
    }
    if(cnt1 > n/2){
        return el;
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = majorityelement(arr, n);
    if(result != -1){
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No Majority Element" << endl;
    }
    return 0;
}
