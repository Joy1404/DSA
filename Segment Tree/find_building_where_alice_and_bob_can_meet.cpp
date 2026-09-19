#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void buildtree(int l, int r, int i, vector<int>&arr, vector<int>&seg) {
		if (l == r) {
			seg[i] = l;
			return;
		}
		int mid = (l + r)/2;
		buildtree(l, mid, 2*i + 1, arr, seg);
		buildtree(mid + 1, r, 2*i + 2, arr, seg);
		int leftidx= seg[2*i + 1];
		int rightidx= seg[2*i + 2];
		if(arr[leftidx] <= arr[rightidx]){
			seg[i]=rightidx;
		}
		else{
			seg[i]=leftidx;
		}
	}
	int rmiq(int i, int l, int r, int start, int end, vector<int>&arr, vector<int>&segment) {
		if (end<l || start>r) {
			return -1;
		}
		if (l >= start && r <= end) {
			return segment[i];
		}
		int mid = (l + r)/2;
		int leftidx= rmiq(2*i + 1, l, mid, start, end, arr, segment);
		int rightidx= rmiq(2*i + 2, mid + 1, r, start, end, arr, segment);
        if(leftidx == -1){
            return rightidx;
        }
        if(rightidx == -1){
            return leftidx;
        }
		if(arr[leftidx] <= arr[rightidx]){
			return rightidx;
		}
		else{
			return leftidx;
		}
	}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int>seg(4*n);
        buildtree(0, n - 1, 0, heights, seg);
        vector<int>result;
        for(auto &query : queries){
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            if(min_idx==max_idx){
                 result.push_back(min_idx);
                 continue;
            }
            else if(heights[max_idx]> heights[min_idx]){
                 result.push_back(max_idx);
                 continue;
            }
            int l = max_idx+1;
            int r = n-1;
            int result_idx = INT_MAX;
            while(l<=r){
                int mid = l+(r-l)/2;
                int idx = rmiq(0,0,n-1,l,mid,heights,seg);
                if(heights[idx] > max(heights[min_idx], heights[max_idx])){
                    result_idx= min(result_idx,idx);
                    r= mid-1;
                }else{
                    l= mid+1;
                }
            }
            if(result_idx==INT_MAX) result.push_back(-1);
            else result.push_back(result_idx);
        }
        return result;
    }
};
int main(){
    vector<int> heights = {4,2,3,1,6,7};
    vector<vector<int>> queries = {{0,1},{1,3},{0,5}};
    Solution sol;
    vector<int> result = sol.leftmostBuildingQueries(heights, queries);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}