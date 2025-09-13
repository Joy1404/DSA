#include<bits/stdc++.h>
using namespace std;
// optimal approach
// time complexity O(log(min(n1,n2))) space complexity O(1)
int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=left-cut1;
        int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
        int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
        int r1=(cut1==n1)?INT_MAX:nums1[cut1];
        int r2=(cut2==n2)?INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1){
            if(n%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else{
                return max(l1,l2);
            }
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
// better approach
// time complexity O(min(n1,n2)) space complexity O(1)
int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
    int n1=nums1.size();
    int n2=nums2.size();
    int i=0,j=0;
    int n = n1+n2;
    int idx2=n/2;
    int idx1=idx2-1;
    int count=0;
    int idxel1=-1;
    int idxel2=-1;
    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(count==idx1) idxel1=nums1[i];
            if(count==idx2) {idxel2=nums1[i]; break;}
            i++;
        }
        else{
            if(count==idx1) idxel1=nums2[j];
            if(count==idx2) {idxel2=nums2[j]; break;}
            j++;
        }
        count++;
    }
    while(i<n1){
        if(count==idx1) idxel1=nums1[i];
        if(count==idx2) {idxel2=nums1[i]; break;}
        i++;
        count++;
    }
    while(j<n2){
        if(count==idx1) idxel1=nums2[j];
        if(count==idx2) {idxel2=nums2[j]; break;}
        j++;
        count++;
    }
    if(n%2) return idxel2;
   return (idxel1+idxel2)/2.0;
}
//time complexity O(n1+n2) space complexity O(n1+n2)
//brute force approach
int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
   vector<int>nums3(n1+n2);
   int i=0,j=0;
   while(i<n1 && j<n2){
     if(nums1[i]<nums2[j]){
        nums3.push_back(nums1[i++]);

     }
     else{
        nums3.push_back(nums2[j++]);
     }
   }
   while(i<n1){
       nums3.push_back(nums1[i++]);
   }
   while(j<n2){
       nums3.push_back(nums2[j++]);
   }
   int total=n1+n2;
   if(total%2==0){
       return (nums3[total/2-1]+nums3[total/2])/2;
   }
   return nums3[total/2];
}
int main(){
    vector<int>nums1={1,3};
    vector<int>nums2={2};
    cout<<findMedianSortedArrays(nums1,nums2);
    return 0;
}