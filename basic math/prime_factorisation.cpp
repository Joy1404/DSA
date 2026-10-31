#include<bits/stdc++.h>
using namespace std;
 vector<int> printprimefactoroptimal(int n){
    vector<int>list;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
         list.push_back(i);
                n = n/i;
        }
    }
        if(n>1) list.push_back(n);
       return list;
 }
 // brute
 void getprimefactor(vector<int>&queries){
    int n = queries.size();
    for(int i=0;i<n;i++){
        vector<int>ans= printprimefactoroptimal(queries[i]);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 }
 //optimal
 void getprimefactoroptimal(vector<int>&queries){
   int n = queries.size();
   vector<int>spf(1e5+1);
   for(int i=0;i<1e5+1;i++) spf[i] = i;
   for(int i=2;i*i<=1e5;i++){
    if(spf[i]==i){
        for(int j=i*i;j<=1e5;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
   }
   for(int i=0;i<n;i++){
    int q = queries[i];
    while(q!=1){
        cout<<spf[q]<<" ";
        q/=spf[q];
    }
   }
   
 }
 int main(){
    int n;
    cin>>n;
    vector<int>queries(n);
    for(int i=0;i<n;i++) cin>>queries[i];
    getprimefactoroptimal(queries);
    
 }