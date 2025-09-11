#include<bits/stdc++.h>
using namespace std;
// problem states that we have to place k gas stations in such a way that the maximum distance between two gas stations is minimised
// brute force approach is to place one gas station at a time in the largest gap between two gas stations
// and repeat this process k times
// time complexity is O(n*k) where n is the number of gas stations and k is the number of gas stations to be placed
// space complexity is O(n) for storing the number of gas stations placed between two gas stations
long double minimiseMaxDistanceBruteForce(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int>howmany(n-1);
    for(int gasstation=0;gasstation<=k;gasstation++){
        long double maxsectionlength = -1;
        int maxindex = -1;
        for(int i=0;i<n-1;i++){
            long double diff = arr[i+1]-arr[i];
            long double sectionlength = diff/(long double)(howmany[i]+1);
            if(sectionlength>maxsectionlength){
                maxsectionlength = sectionlength;
                maxindex = i;
            }
        }
        howmany[maxindex]++;
    }
    long double ans = -1;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1]-arr[i];
        long double sectionlength = diff/(long double)(howmany[i]+1);
        ans = max(ans,sectionlength);
    }
    return ans;
}
// using priority queue to optimise the brute force approach
// time complexity is O(nlogn + klogn) where n is the number of gas stations and k is the number of gas stations to be placed
// space complexity is O(n) for storing the number of gas stations placed between two gas stations
long double minimiseMaxDistanceBetter(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int>howmany(n-1);
    priority_queue<pair<long double,int>>pq;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1]-arr[i];
        pq.push({diff,i});
    }
    for(int gasstation=0;gasstation<=k;gasstation++){
      auto top = pq.top();
      pq.pop();
      int sectionindex = top.second;
        howmany[sectionindex]++;
        long double inidiff = arr[sectionindex+1]-arr[sectionindex];
        long double newsectionlength = inidiff/(long double)(howmany[sectionindex]+1);
        pq.push({newsectionlength,sectionindex});
    }
        
    return pq.top().first;
}
// using binary search to optimise the brute force approach
// time complexity is O(nlogn + nlogm) where n is the number of gas stations and m is the maximum distance between two gas stations
// space complexity is O(1)
long double minimisemaxdistanceoptimal1(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    long double left = 0;
    long double right = arr[n-1]-arr[0];
    long double ans = right;
    while(left<=right){
        long double mid = left + (right-left)/2;
        int count = 0;
        for(int i=0;i<n-1;i++){
            long double diff = arr[i+1]-arr[i];
            count += (diff/mid);
        }
        if(count>k){
            left = mid + 1e-6;
        }
        else{
            ans = mid;
            right = mid - 1e-6;
        }
    }
    return ans;
}
//function to calculate number of gas stations needed to be placed such that the maximum distance between two gas stations is less than or equal to mid
int numberofgasstations(vector<int>& arr, long double mid) {
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n-1;i++){
        int numinbetween = (arr[i+1]-arr[i])/mid;
       if((arr[i+1]-arr[i])/mid==numinbetween*mid){
           numinbetween--;
       }
        count +=numinbetween;
    }
    return count;
}
//optimal approach is to use binary search
long double minimisemaxdistanceoptimal2(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    long double low = 0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high = max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff = 1e-6;
    while(high-low>diff){
        long double mid = low + (high-low)/2;
       int count = numberofgasstations(arr,mid);
        if(count>k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 9;
    cout<<minimisemaxdistanceoptimal1(arr,k)<<endl;
    return 0;
}

   