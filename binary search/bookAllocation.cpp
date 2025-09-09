#include<bits/stdc++.h>
using namespace std;
//book allocation problem
// check if it is possible to allocate books such that the maximum number of pages allocated to a student is less than or equal to mid

// returns the number of students required to allocate books such that the maximum number of pages allocated to a student is less than or equal to pages
// if it is not possible to allocate books such that the maximum number of pages allocated to a student is less than or equal to pages, return false
//condition: each student must be allocated at least one book
// all books must be allocated
// books are allocated in contiguous manner
// a[i] = number of pages in the ith book
// students = number of students
// pages = maximum number of pages allocated to a student

// similar problem: painters partition problem and split array largest sum
int ispossible(int pages, int students, vector<int> &a){
    int studentcount = 1;
    int pagesum = 0;
    for(int i=0; i<a.size(); i++){
        if(pagesum + a[i] <= pages){
            pagesum += a[i];
        }
        else{
            studentcount++;
            pagesum = a[i];
        }
    }
    return studentcount;
}
//brute force approach
// time complexity O(sum of pages - max pages)*O(n)
// space complexity O(1)
int bookAllocation(vector<int> &a, int students){
    int maxx = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    for(int i=maxx; i<=sum; i++){
        int cntstudent = ispossible(i, students, a);
        if(cntstudent == students){
            return i;
        }
    }
    return -1;
}
//optimal approach
// time complexity O(nlog(sum of pages - max pages))
// space complexity O(1)
int bookAllocation_optimal(vector<int> &a, int students){
    int maxx = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    int start = maxx;
    int end = sum;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        int cntstudent = ispossible(mid, students, a);
        if(cntstudent <= students){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int students;
    cin>>students;
    cout<<bookAllocation_optimal(a, students)<<endl;
    return 0;
}