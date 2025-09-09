#include<bits/stdc++.h>
using namespace std;
// check if it is possible to place cows with minimum distance dist
bool ispossible(int dist, int cows, vector<int> &a){
    int cowcount = 1;
    int lastpos = a[0];
    for(int i=1; i<a.size(); i++){
        if(a[i]-lastpos >= dist){
            cowcount++;
            if(cowcount == cows){
                return true;
            }
            lastpos = a[i];
        }
    }
    return false;
}
// brute force approach
// time complexity O(nlogn) + O(n^2)
/// space complexity O(1)
// aggresive cows problem
// find the largest minimum distance between the cows
int aggresivecows(vector<int> &a, int cows){
    sort(a.begin(), a.end());
  int maxx= *max_element(a.begin(), a.end());
  int minn = *min_element(a.begin(), a.end());
  for(int i=1;i<=maxx-minn;i++){
      if(ispossible(i,cows,a)){
        continue;
      }
      else{
          return i-1;
      }
  }
    return maxx-minn;
}
//optimal approach
// time complexity O(nlogn) + O(nlogm)
// space complexity O(1)
int aggresivecows_optimal(vector<int> &a, int cows){
    sort(a.begin(), a.end());
    int start = 1;
    int end = a[a.size()-1] - a[0];
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(ispossible(mid, cows, a)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans; // return the largest minimum distance   return high;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int cows;
    cin>>cows;
    cout<<aggresivecows(a,cows)<<endl;
    return 0;
}