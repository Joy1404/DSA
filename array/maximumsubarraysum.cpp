#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
// Brute force technique to find the maximum subarray sum
// Time complexity: O(n^3)
int maxsubArraySum( vector<int>& arr){
    int maxx=INT32_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxx=max(maxx,sum);
        }
    }
    return maxx;
}
//better approach to find the maximum subarray sum
// Time complexity: O(n^2)
int maxSubArraySumBetter( vector<int>& arr) {
    int maxx = INT32_MIN;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            maxx = max(maxx, sum);
        }
    }
    return maxx;
}
//optimal approach using Kadane's algorithm
// Time complexity: O(n)
int maxSubArraySumOptimal( vector<int>& arr) {
    int ansstart=-1, ansend=-1;
    int sum=0,maxx=INT32_MIN,start;
    for(int i=0;i<arr.size();i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxx){
            maxx=sum;
            ansstart=start;
            ansend=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxx>0 ? maxx : 0; // Return 0 if all elements are negative
    // To return the subarray, you can use ansstart and ansend
    // return vector<int>(arr.begin() + ansstart, arr.begin() + ansend + 1);
    
}
//optimization technique to find the maximum subarray sum
int maxSubArraySum( vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, -1, 5, -4};
    cout << "Maximum Subarray Sum: " << maxSubArraySum(arr) << endl;
    return 0;
}