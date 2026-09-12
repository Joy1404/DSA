#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
int n;
vector<int>segmentTree;
void buildtree(int i, int l, int r, vector<int>&arr,vector<int>&seg){
    if(l==r){
        seg[i]=arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    buildtree(2*i+1,l,mid,arr,seg);
    buildtree(2*i+2,mid+1,r,arr,seg);
    seg[i]= seg[2*i+1] + seg[2*i+2];
}
void updateval(int i, int l, int r, int idx, int val,
             vector<int>& segment) {

    if (l == r) {
        segment[i] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid) {
        updateval(2 * i + 1, l, mid, idx, val,  segment);
    }
    else {
        updateval(2 * i + 2, mid + 1, r, idx, val, segment);
    }

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
}
int rangeQuery(int i, int l, int r, int start, int end,vector<int>&segment){
      if(end<l || start>r){
          return 0;
      }
      if(l>=start && r<=end){
          return segment[i];
      }
      int mid = (l+r)/2;
      return rangeQuery(2*i + 1, l, mid, start, end, segment) + rangeQuery(2*i + 2, mid + 1, r, start, end, segment);
  }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildtree(0,0,n-1,nums,segmentTree);
    }
    
    void update(int index, int val) {
        updateval(0,0,n-1,index,val,segmentTree);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(0,0,n-1,left,right,segmentTree);
    }
};
int main(){
    vector<int>nums={1,3,5};
    NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0,2)<<endl;
    obj->update(1,2);
    cout<<obj->sumRange(0,2)<<endl;
    return 0;
}