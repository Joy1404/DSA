#include<bits/stdc++.h>
using namespace std;
// approach: use two max heaps to find k1th and k2th smallest elements
// then sum the elements between them
// first max-heap to find k1th smallest element
// second max-heap to find k2th smallest element
// finally sum the elements between k1th and k2th smallest elements
// time complexity: O(n log k2)
// space complexity: O(k2)
long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2) {
     priority_queue<long long>p1;
        priority_queue<long long>p2;
        
        for(long long i =0;i<k1;i++) p1.push(A[i]);
        for(long long i =0;i<k2-1;i++) p2.push(A[i]);
        
        for(long long i =k1;i<N;i++){
            if(A[i]<p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        for(long long i =k2-1;i<N;i++){
            if(A[i]<p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        long long sum1=0,sum2=0;
        while(!p1.empty()){
            sum1+=p1.top();
            p1.pop();
        }
        while(!p2.empty()){
            sum2+=p2.top();
            p2.pop();
        }
        return sum2 - sum1;
    }
int main(){
    long long arr[] = {20, 8, 22, 4, 12, 10, 14};
    long long n = sizeof(arr)/sizeof(arr[0]);
    long long k1 = 3, k2 = 6;
    cout << "Sum of elements between " << k1 << "th and " << k2
            << "th smallest elements is: " 
            << sumBetweenTwoKth(arr, n, k1, k2) << endl;
    return 0;
}