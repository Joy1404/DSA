#include<bits/stdc++.h>
using namespace std;
int maxconsecutiveOne(int arr[],int n){
    int maxi=0,cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }else{
            cnt=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum consecutive ones are: "<<maxconsecutiveOne(arr,n)<<endl;
    return 0;
}