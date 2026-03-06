#include<bits/stdc++.h>
using namespace std;
// approach 3: using two pointers and two variables to store the max height of the bar from 0 to i and from n-1 to i and then find the min of the two and subtract the height of the current bar from it and add it to the answer always move the pointer which has the smaller height of the bar because the water trapped will be limited by the smaller height of the bar
// time complexity: O(n) and space complexity: O(1)
int trapoptimal(vector<int>&arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    int leftmax = 0;
    int rightmax = 0;
    int ans = 0;
    while(left<right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=leftmax){
                leftmax = arr[left];
            }
            else{
                ans += leftmax - arr[left];
            }
            left++;
        }
        else{
            if(arr[right]>=rightmax){
                rightmax = arr[right];
            }
            else{
                ans += rightmax - arr[right];
            }
            right--;
        }
    }
    return ans;
}  
// approach 1: using prefix and suffix max arrays find the max height of the bar from 0 to i and from i to n-1 and then find the min of the two and subtract the height of the current bar from it and add it to the answer  
// time complexity: O(n) and space complexity: O(n)
int trap(vector<int>&arr){
    int n = arr.size();
    vector<int> prefixmax(n);
    vector<int> suffixmax(n);
    // prefixmax[i] = max height of the bar from 0 to i
    // suffixmax[i] = max height of the bar from i to n-1
    prefixmax[0] = arr[0];
    for(int i=1;i<n;i++){
        prefixmax[i] = max(prefixmax[i-1], arr[i]);
    }
    suffixmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixmax[i] = max(suffixmax[i+1], arr[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int leftmax = prefixmax[i];
        int rightmax = suffixmax[i];
        ans += min(leftmax, rightmax) - arr[i];
    }
    return ans;
}
// approach 2: using only suffix max array and a variable to store the max height of the bar from 0 to i and then find the min of the two and subtract the height of the current bar from it and add it to the answer
// time complexity: O(n) and space complexity: O(n)
int trap2(vector<int>&arr){
    int n = arr.size();
    vector<int> suffixmax(n);
    suffixmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixmax[i] = max(suffixmax[i+1], arr[i]);
    }
    int ans = 0;
    int leftmax = arr[0];
    for(int i=0;i<n;i++){
        leftmax = max(leftmax, arr[i]);
        int rightmax = suffixmax[i];
        ans += min(leftmax, rightmax) - arr[i];
    }
    return ans;
}
int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trapoptimal(arr)<<endl;
    return 0;
}