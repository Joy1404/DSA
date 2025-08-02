#include<iostream>
#include<vector>
using namespace std;
// brute force approach
// time complexity O(n)
// space complexity O(n)
vector<int> rearrangearrayelementbysign(vector<int> arr) {
    vector<int> pos, neg;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        arr[i*2]=pos[i];
        arr[i*2+1]=neg[i];
    }
    return arr;
}
//optimal approach
// time complexity O(n)
// space complexity O(1)
vector<int> rearrangearrayelementbysignOptimal(vector<int> arr) {
    int n = arr.size();
    vector<int> result(n);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            result[posIndex] = arr[i];
            posIndex += 2;
        } else {
            result[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return result;
}
// if the number of positive and negative elements are not equal, then we can fill the remaining positions with zeros or any other value as needed.
vector<int> rearrangearrayelementbysignWithFill(vector<int> arr) {
    int n = arr.size();
    vector<int> result(n);
    vector<int> pos, neg;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size() > neg.size()) {
        for(int i=0;i<neg.size();i++){
            result[i*2]=pos[i];
            result[i*2+1]=neg[i];
        }
        int index = 2*neg.size();
        for(int i=neg.size();i<pos.size();i++){
            result[index]=pos[i];
            index++;
        }
    } else {
        for(int i=0;i<pos.size();i++){
            result[i*2]=pos[i];
            result[i*2+1]=neg[i];
        }
        int index = 2*pos.size();
        for(int i=pos.size();i<neg.size();i++){
            result[index]=neg[i];
            index++;
        }
    }
    for(int i=0;i<n/2;i++){
        arr[i*2]=pos[i];
        arr[i*2+1]=neg[i];
    }
    return result;
}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4,5};
    vector<int> rearranged = rearrangearrayelementbysignWithFill(arr);

    cout << "Rearranged array: ";
    for (int i : rearranged) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}