#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
//brute force approach to find leaders in an array
//time complexity: O(n^2)
//space complexity: O(1) as we are not using any extra space except for the output vector
vector<int> findLeadersBruteForce(const vector<int>& arr) {
    vector<int> ans;
    for (int i = 0; i < arr.size(); ++i) {
        bool isLeader = true;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] <= arr[j]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
//optimal approach to find leaders in an array
// A leader is an element that is greater than all the elements to its right in the array.
// Time Complexity: O(n)
// Space Complexity: O(n) for storing the leaders
vector<int> findLeaders(const vector<int>& arr) {
    vector<int> ans;
    int maxi = INT32_MIN;
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);

    cout << "Leaders in the array are: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}