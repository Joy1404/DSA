#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
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
            // moves to the refered node
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
int maximumXOR(vector<int>& nums){
   Trie* trie = new Trie();
    for(int i=0;i<nums.size();i++){
        trie->insert(nums[i]);
    }
    int maxi = 0;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,trie->getmax(nums[i]));
    }
    return maxi;
} 
int main(){
    vector<int> nums = {3,0,7,2};   
    cout<<maximumXOR(nums)<<endl;
    return 0;
}