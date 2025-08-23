#include <bits/stdc++.h>
using namespace std;
// brute force
int reversePairs(vector<int>& arr){
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((long long)arr[i]>(2*(long long)arr[j])) 
            cnt++;
        }
    }
    return cnt;
    }


//optimal with global variable
int cnt = 0;
void merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}
void countpairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && (long long)arr[i] > 2 * (long long)arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    int cnt = 0;
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    countpairs(arr, left, mid, right);
    merge(arr, left, mid, right);
}

int reversePairs(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    return cnt;
}


// optimal without global variable
void merge(vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}
int countpairs1(vector<int>&arr,int low,int mid,int high){
    int right = mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<= high && (long long)arr[i]>2*(long long)arr[right]) right++;
        cnt+=(right-(mid+1));

    }
    return cnt;

}
int mergeSort1(vector<int>& arr, int left, int right) {
    int cnt =0;
    if (left >= right) return cnt;
    int mid = (left + right) / 2;
    cnt+= mergeSort1(arr, left, mid);
    cnt+= mergeSort1(arr, mid + 1, right);
    cnt+= countpairs1(arr,left,mid,right);
     merge(arr, left, mid, right);
     return cnt;
}

    int reversePairs(vector<int>& arr) {
      return  mergeSort1(arr, 0, arr.size() - 1);
       
    }

int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};
    cout << reversePairs(arr);
    return 0;
}