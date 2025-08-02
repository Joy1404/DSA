#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int>p1, pair<int, int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.second == p2.second) return p1.first > p2.first;
    return false;
}
void extra(){ 
    vector<int>v;
    // sort(a,a+n);  for array starting from a to a+n
    // sort(a,a+n,greater<int>()); // for descending order
    // sort(a+2,a+5); // for array starting from a+2 to a+5 it will be sorted
    sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), greater<int>()); // for descending order
    pair<int, int>a[]={{1, 2}, {2, 1}, {4, 1}};
    //sorted according to second element
    //if second element is same then sort according to first element but in descending order
    sort(a, a + 3, comp);

    int num=7;
    int cnt=__builtin_popcount(num);
    // __builtin_popcount(num) gives the number of set bits in num
    // __builtin_popcountll(num) gives the number of set bits in num for long long
    string s="123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));
    // next_permutation(s.begin(), s.end()) gives the next permutation of s in lexicographical order
    // prev_permutation(s.begin(), s.end()) gives the previous permutation of s in lexicographical order

    int maxi=*max_element(a, a + 3);
    // *max_element(a, a + 3) gives the maximum element in the array a from a to a+3

}