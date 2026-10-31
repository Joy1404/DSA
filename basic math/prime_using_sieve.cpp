#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int n) {
        vector<bool>isprime(n+1,true);
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
            for(int j=2;i*j<=n;j++){
                isprime[i*j] = false;
            }
            }
        }
        vector<int>result;
        for(int i=2;i<=n;i++){
            if(isprime[i]){
                result.push_back(i);
            }
        }
       return result; 
    }
int main(){
    vector<int> primes = sieve(100);
    for(int p : primes){
        cout << p << " ";
    }
    return 0;
}