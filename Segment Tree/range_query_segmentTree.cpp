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
int rangeQuery(int i, int l, int r, int start, int end, int arr[], int segment[]){
    if(end<l || start>r){
        return 0;
    }
    if(l>=start && r<=end){
        return segment[i];
    }
    int mid = (l+r)/2;
    return rangeQuery(2*i + 1, l, mid, start, end, arr, segment) + rangeQuery(2*i + 2, mid + 1, r, start, end, arr, segment);
}
int main(){
    int n;
    cin>>n;
    int arr[n], segment[4*n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    buildTree(0, 0, n-1, arr, segment);
    for(int i=0; i<4*n; i++){
        cout<<segment[i]<<" ";
    }
    cout<<endl;
    cout<<rangeQuery(0, 0, n-1, 1, 3, arr, segment)<<endl;
    return 0;
}