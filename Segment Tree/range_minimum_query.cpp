#include<bits/stdc++.h>
using namespace std;

void buildtree(int l, int r, int i, vector<int>&arr, vector<int>&seg) {
		if (l == r) {
			seg[i] = arr[l];
			return;
		}
		int mid = (l + r)/2;
		buildtree(l, mid, 2*i + 1, arr, seg);
		buildtree(mid + 1, r, 2*i + 2, arr, seg);
		seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
	}
	int rangeQuery(int i, int l, int r, int start, int end, vector<int>&arr, vector<int>&segment) {
		if (end<l || start>r) {
			return INT_MAX;
		}
		if (l >= start && r <= end) {
			return segment[i];
		}
		int mid = (l + r)/2;
		return min(rangeQuery(2*i + 1, l, mid, start, end, arr, segment), rangeQuery(2*i + 2, mid + 1, r, start, end, arr, segment));
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