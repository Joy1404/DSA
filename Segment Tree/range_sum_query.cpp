#include<bits/stdc++.h>
using namespace std;
void buildtree(int l, int r, int i,vector<int>&arr,vector<int>&seg){
      if(l==r){
          seg[i]=arr[l];
          return;
      }
      int mid = (l+r)/2;
      buildtree(l,mid,2*i+1,arr,seg);
      buildtree(mid+1,r,2*i+2,arr,seg);
      seg[i] = seg[2*i+1] + seg[2*i+2];
  }
  int rangeQuery(int i, int l, int r, int start, int end, vector<int>&arr,vector<int>&segment){
      if(end<l || start>r){
          return 0;
      }
      if(l>=start && r<=end){
          return segment[i];
      }
      int mid = (l+r)/2;
      return rangeQuery(2*i + 1, l, mid, start, end, arr, segment) + rangeQuery(2*i + 2, mid + 1, r, start, end, arr, segment);
  }
    vector<int> querySum(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>seg(4*n);
        vector<int>ans;
        buildtree(0,n-1,0,arr,seg);
        for(int i=0;i<queries.size();i++){
            // 1-indexed queries, so we need to subtract 1 from the indices
           ans.push_back(rangeQuery(0,0,n-1,queries[i][0]-1,queries[i][1]-1,arr,seg));
        }
        return ans;
        
    }

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>seg(4*n);
    buildtree(0,n-1,0,arr,seg);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<rangeQuery(0,0,n-1,l-1,r-1,arr,seg)<<endl;
    }
}