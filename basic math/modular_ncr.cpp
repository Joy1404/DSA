#include<bits/stdc++.h>
using namespace std;
long long power(long long a , long long b , long long mod){
    long long res = 1;
    while(b>0)
    {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return res;
}
long long modinverse(long long n , long long mod){
    return power(n , mod-2 , mod);
}

long long modNcr(long long n , long long r , long long mod)
{
    if(r<0 || r>n) return 0;
    if(r == 0 || r==n) return 1;
    if(r>n/2) r= n-r;

    long long fact[n+1];
    fact[0] = 1;
    for(int i=1 ; i<=n ; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    return ((fact[n]*modinverse(fact[r],mod))%mod * modinverse(fact[n-r],mod))%mod;
}
int main(){
    long long n,r;
    cin>>n>>r;
    long long mod = 1e9+7;
    cout<<modNcr(n,r,mod)<<endl;
    return 0;
}