#include<bits/stdc++.h>
using namespace std;
//brute approach t.c=O(n^2) s.c=0(1)
// int missingnumber(int arr[],int n){
//     for(int i=1;i<=n;i++){
//         int flag=0;
//         for(int j=0;j<n-1;j++){
//             if(arr[j]==i){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0) return i;
//     }
// }
//better approach
// t.c=0(2n),s.c=0(n)
// int missingnumber(int arr[],int n){
//     int hash[n+1]={0};
//     for(int i=0;i<n-1;i++)
//       hash[arr[i]]=1;
       
//         for(int j=1;j<=n;j++){
//             if(hash[j]==0){
                
//                 return j;
//             }
//         }
    
// }
//optimal approach 1
// t.c=0(n) s.c=0(1)
// int missingnumber(int arr[],int n){
//     int sum=n*(n+1)/2;
//    int s2=0;
//    for(int i=0;i<n-1;i++){
//     s2+=arr[i];
//    }
//    return(sum-s2);

// }
//optimal approach 2 better than optimal 1 because if n is large sum will be very large
// t.c=0(n) s.c=0(1)
int missingnumber(int arr[],int n){
    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1=xor1^(i+1);
        xor2=xor2^arr[i];
    }
    xor1=xor1^n;
    return(xor1^xor2);
}
int main() {
    int n=5;
    int arr[5]={1,2,4,5};
    
    cout << "The missing element is: " << missingnumber(arr,n) << endl;
    return 0;
}