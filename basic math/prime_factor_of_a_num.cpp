#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    // brute force
    void printprimefactor(int n){
 for(int i = 2 ; i <= n ; i++){
        if(n%i==0 and isprime(i)) cout<<i<<" ";
    }
    }
    // better brute
     void printprimefactorbrute(int n){
 for(int i = 2 ; i*i <= n ; i++){
        if(n%i==0){
            if(isprime(i)) cout<<i<<" ";
          if(n/i!=i && isprime(n/i)) cout<<n/i<<" ";
        }
    }
    }
    // better
       void printprimefactorbetter(int n){
        for(int i=2;i<=n;i++){
            if(n%i==0) cout<<i<<" ";
            while(n%i==0) n = n/i;
        }
       }
       //optimal
        void printprimefactoroptimal(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) cout<<i<<" ";
            while(n%i==0) n = n/i;
        }
        if(n!=1) cout<<n<<" ";
       }
int main(){
    int n;
    cin>>n;
   printprimefactoroptimal(n);
    return 0;
}