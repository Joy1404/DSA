#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    if(nums1.size()>nums2.size()) return kthElement(nums2,nums1,k);
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    int low=max(0,k-n2),high=min(n1,k);
    int left=k;
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=left-cut1;
        int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
        int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
        int r1=(cut1==n1)?INT_MAX:nums1[cut1];
        int r2=(cut2==n2)?INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }
    return 0.0;
}
int main(){
    vector<int>nums1={2,3,6,7,9};
    vector<int>nums2={1,4,8,10};
    int k=5;
    cout<<"kth element is: "<<kthElement(nums1,nums2,k)<<endl;
    return 0;
}