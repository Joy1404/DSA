#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>>& nums, int low, int high) {
    for(int i = 0; i < nums.size(); i++) {
        bool found = false;
        for(int j = 0; j < nums[i].size(); j++) {
            if(nums[i][j] >= low && nums[i][j] <= high) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}
// aproach 1: brute force
//t.c : O(n3k3) n is the number of lists and k is the average length of each list
// s.c : O(n2k2) for storing all elements in a single array
vector<int>smallestrange(vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.push_back(nums[i][j]);
        }
}
vector<int>temp;
int mini = INT_MAX;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        for(int j =i+1;j<ans.size();j++){
            int range = ans[j]-ans[i];
            if(check(nums,ans[i],ans[j]) && range<mini){
                mini = range;
                temp.clear();
                temp.push_back(ans[i]);
                temp.push_back(ans[j]);
            }
        }
    }
    return temp;
}
// approach 2: using min heap
// t.c : O(nk log(nk)) n is the number of lists and k
// s.c : O(nk) for storing all elements in the min heap
// approach : at first push the first element of each list into the min heap and keep track of the maximum element among them. then extract the minimum element from the heap and push the next element from the same list into the heap. update the range if the current range is smaller than the previous range. repeat this process until we have at least one element from each list in the heap.
vector<int>smallestrangeheap(vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
      pq.push({nums[i][0],{i,0}});
      mx = max(mx,nums[i][0]);
        }
    vector<int>ans(2);
    int mini;
    mini = pq.top().first;
    ans[0]=mini;
    ans[1]=mx;
    while(pq.size()==n){
       int minel = pq.top().first;
       int row = pq.top().second.first;
       int col = pq.top().second.second;
       pq.pop();
       if(col+1<nums[row].size()){
        pq.push({nums[row][col+1],{row,col+1}});
        mx = max(mx,nums[row][col+1]);
        mini = pq.top().first;
        if(mx-mini<ans[1]-ans[0]){
            ans[0]=mini;
            ans[1]=mx;
       }
  
}
}
        return ans;
}
int main(){
    vector<vector<int>> nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };
    vector<int> result = smallestrangeheap(nums);
    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}