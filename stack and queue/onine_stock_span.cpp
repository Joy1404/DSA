#include<bits/stdc++.h>
using namespace std;
// approach : we will use two loops to find the number of consecutive days the price of the stock was less than or equal to the current price.
// time complexity : O(n^2) where n is the number of calls to the next
// space complexity : O(n) where n is the number of calls to the next function as we are storing the price of the stock in a vector.
class StockSpanner {
public:
   vector<int> arr;
    StockSpanner() {
       arr ={};
    }
    
    int next(int price) {
        arr.push_back(price);
        int count = 1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=price){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};
// approach : we will use a stack to store the price and the index of the price. we will pop the elements from the stack until we find a price which is greater than the current price. the answer will be the difference between the current index and the index of the price which is greater than the current price.
// time complexity : O(n) where n is the number of calls to the next function.
// space complexity : O(n) where n is the number of calls to the next function as we are storing the price and the index of the price in the stack.
class StockSpanner1 {
public:
    stack<pair<int,int>> st;
    int index = -1;
    StockSpanner1() {
        index = -1;
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        index++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans = index - (st.empty()?-1:st.top().second);
        st.push({price,index});
        return ans;
    }
};
int main(){
    StockSpanner* obj = new StockSpanner();
    cout<<obj->next(100)<<endl;
    cout<<obj->next(80)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(70)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(75)<<endl;
    cout<<obj->next(85)<<endl;
}