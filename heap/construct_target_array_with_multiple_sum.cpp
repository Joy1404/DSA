#include<bits/stdc++.h>
using namespace std;
// brute force will give TLE
// approach : use maxheap to get the maximum element
// then we can find the previous element by subtracting the sum of rest of the elements from the maximum element
// we repeat this process until the maximum element becomes 1
 bool isPossible(vector<int>& target) {
        // maxheap
        priority_queue<int>pq;
        int sum = 0;
        for(int i =0;i<target.size();i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        int maxel,remsum,element;
        while(pq.top()!=1){
            maxel = pq.top();
            pq.pop();
            remsum = sum - maxel;
            // maxel = remsum + element
            // edge case
            if(remsum<=0 || remsum>=maxel) return 0;
            element = maxel-remsum;
            sum= remsum + element;
            pq.push(element);
        }
        return true;
    }
    // optimized approach
     bool isPossibleoptimised(vector<int>& target) {
        // maxheap
        priority_queue<int>pq;
        int sum = 0;
        for(int i =0;i<target.size();i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        int maxel,remsum,element;
        while(pq.top()!=1){
            maxel = pq.top();
            pq.pop();
            remsum = sum - maxel;
            // maxel = remsum + element
            // edge case
            if(remsum<=0 || remsum>=maxel) return 0;
            // optimized step to find previous element
            element = maxel%remsum;
            if(element==0){
                if(remsum!=1) return false;
                else return true;
            }
            sum= remsum + element;
            pq.push(element);
        }
        return true;
    }
int main(){
    vector<int> target = {9,3,5};
    cout<<isPossibleoptimised(target);
    return 0;
}