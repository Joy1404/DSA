#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
vector<int> getsieve(int n) {
        vector<int>isprime(n+1,1);
          isprime[0] = 0;
          isprime[1] = 0;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j] = false;
            }
            }
        }
       return isprime;
    }
    // brute force
void printprimes(vector<vector<int>>&queries){
    int q = queries.size();
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r  = queries[i][1];
        int cnt = 0;
        for(int j=l;j<=r;j++){
            if(isprime(j)) cnt++;
        }
        cout<<cnt;
    }
}
  // better
void printprimesbetter(vector<vector<int>>&queries){
    vector<int>prime= getsieve(1e6);
    int q = queries.size();
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r  = queries[i][1];
        int cnt = 0;
        for(int j=l;j<=r;j++){
            if(prime[j]==1) cnt++;
        }
        cout<<cnt;
    }
}
// optimal
void printprimesoptimal(vector<vector<int>>&queries){
    vector<int>prime= getsieve(1e6+1);
    int cnt=0;
    for(int i=0;i<=1e6;i++){
        cnt+=prime[i];
        prime[i]= cnt;
    }
    int q = queries.size();
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r  = queries[i][1];
         cout<<prime[r]- prime[l-1]<<" ";
    }
}
int main(){ 
    int n;
    cin>>n;
    vector<vector<int>>queries(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    printprimesoptimal(queries);
    
    return 0;
}