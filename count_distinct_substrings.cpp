#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];

    bool containskey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }
};
int countDistinctSubstrings(string s){
    Node* root = new Node();
    int n = s.size();
    int count = 1;
    for(int i = 0; i < n; i++){
        Node* node = root;
        for(int j = i; j < n; j++){
            if(!node->containskey(s[j])){
                node->put(s[j] , new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count;
}
int main(){
    string s;
    cin>>s;
    cout<<countDistinctSubstrings(s)<<endl;
    return 0;
}