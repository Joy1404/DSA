#include<bits/stdc++.h>
using namespace std;
void buildTree(int i, int l, int r, int arr[], int segment[]){
    if(l==r){
        segment[i] = arr[r];
        return;
    }
    int mid = (l+r)/2;
    buildTree(2*i+1, l, mid, arr, segment);
    buildTree(2*i + 2, mid + 1, r, arr, segment);
    segment[i] = segment[2*i + 1] + segment[2*i + 2];
}
int main(){
    int n;
    cin>>n;
    int arr[n], segment[2*n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    buildTree(0, 0, n-1, arr, segment);
    for(int i=0; i<2*n; i++){
        cout<<segment[i]<<" ";
    }
    return 0;
}