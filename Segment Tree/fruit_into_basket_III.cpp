#include<bits/stdc++.h>
using namespace std;

// brute force
 int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!full[j] && baskets[j]>=fruits[i]){
                    baskets[j] = -1;
                    break;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
          if(baskets[i]!=-1)  cnt++;
        }
        return cnt;
    }
    void build(int i, int l, int r, vector<int>&baskets,vector<int>&segtree ){
        if(l==r){
            segtree[i] = baskets[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(2*i+1,l,mid,baskets,segtree);
        build(2*i+2,mid+1,r,baskets,segtree);
        segtree[i] =  max(segtree[2*i+1],segtree[2*i+2]);
    }
    bool querysegtree(int i, int l, int r, int fruit,vector<int>&segtree){
        if(segtree[i]<fruit) return false;
        if(l==r){
            segtree[i] =-1;
            return true;
        }
        int mid =l+(r-l)/2;
        bool placed = false;
        if(segtree[2*i+1]>=fruit){
            placed = querysegtree(2*i+1,l,mid,fruit,segtree);
        }else{
              placed = querysegtree(2*i+2,mid+1,r,fruit,segtree);
        }
        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);
        return placed;  
    }

     int numOfUnplacedFruitsoptimal(vector<int>& fruits, vector<int>& baskets) {
         int n = fruits.size();
         vector<int>segtree(4*n,-1);
         build(0,0,n-1,baskets,segtree);
         int unplaced = 0;
         for(int fruit : fruits){
            if(querysegtree(0,0,n-1,fruit,segtree)==false){
                unplaced++;
            }
         }
         return unplaced;
     }

 
int main(){
    int n;
    cin>>n;
    vector<int> fruits(n),baskets(n);
    for(int i=0;i<n;i++){
        cin>>fruits[i];
    }
    for(int i=0;i<n;i++){
        cin>>baskets[i];
    }
    cout<<numOfUnplacedFruits(fruits,baskets)<<endl;
    return 0;
    
}