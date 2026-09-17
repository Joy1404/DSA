#include<bits/stdc++.h>
using namespace std;

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
	int rangeQuery(int i, int l, int r, int start, int end, vector<int>&arr, vector<int>&segment) {
		if (end<l || start>r) {
			return -1;
		}
		if (l >= start && r <= end) {
			return segment[i];
		}
		int mid = (l + r)/2;
		int leftidx= rangeQuery(2*i + 1, l, mid, start, end, arr, segment);
		int rightidx= rangeQuery(2*i + 2, mid + 1, r, start, end, arr, segment);
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
	vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>> & queries) {
		int n = arr.size();
		vector<int>seg(4*n);
		vector<int>ans;
		buildtree(0, n - 1, 0, arr, seg);
		for (int i = 0; i<queries.size(); i++) {
			ans.push_back(rangeQuery(0, 0, n - 1, queries[i][0], queries[i][1], arr, seg));
		}
		return ans;
		
	}

int main(){
    vector<int>arr = {1, 3, 2, 7, 9, 11};
    vector<vector<int>> queries = {{1, 2}, {2, 4}, {0, 5}, {3, 3}};
    vector<int> ans = rangeMinQuery(arr, queries);
    for (int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}