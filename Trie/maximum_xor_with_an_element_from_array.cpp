#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
public:
    void insert(int num){
        Node* node = root;
        for(int i =31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getmax(int num){
        Node* node = root;int maxi= 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            int toggle = 1-bit;
            if(node->containsKey(toggle)){
                maxi = maxi | (1<<i);
                node=node->get(toggle);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi;
    }  
}; 
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>>oq;
        int q = queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        int idx =0;
        int n = nums.size();
        Trie trie;
        for(int i=0;i<q;i++){
            int ai= oq[i].first;
            int xi=oq[i].second.first;
            int qidx= oq[i].second.second;
        while(idx<n && nums[idx]<=ai ){
           trie.insert(nums[idx++]);
        }
        if(idx==0) ans[qidx] = -1;
        else ans[qidx] =  trie.getmax(xi);
        }
        return ans;
    }

int main(){
    vector<int> nums = {3,0,7,2};
    vector<vector<int>> queries = {{1,3},{2,3},{3,3}};   
    vector<int>ans = maximizeXor(nums,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}