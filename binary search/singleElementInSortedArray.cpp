#include<bits/stdc++.h>
using namespace std;
// optimal 
int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
    int low = 1, high = nums.size() - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // This line should never be reached
}
// optimal2
 int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        int st=0,end=n-1;
        while(st<=end){
            int mid =st+(end-st)/2;
            if(mid==0 && a[mid]!=a[1]) return a[mid];
            if(mid==n-1 && a[mid]!=a[n-2]) return a[mid];
            if(a[mid-1]!=a[mid] && a[mid]!=a[mid+1]) return a[mid];

            if(mid%2==0){
                if(a[mid-1]==a[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                if(a[mid-1]==a[mid]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
        
    }
// brute force
int singleNonDuplicateBruteForce(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    for(int i = 0; i < nums.size(); i ++) {
        if(i == 0) {
            if(nums[i] != nums[i + 1]) return nums[i];
}
       else if(i == nums.size() - 1) {
            if(nums[i] != nums[i - 1]) return nums[i];
        }else{
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
        }
    }
    return -1; // This line should never be reached
}


int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    cout << "The single non-duplicate element is: " << singleNonDuplicate(nums) << endl;
    return 0;
}