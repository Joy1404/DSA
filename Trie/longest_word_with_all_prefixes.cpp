#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;

    bool containskey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containskey(word[i])){
              node = node->get(word[i]);
              if(!node->isEnd()){
                return false;
              }
            }
            else{
                return false;
            }
            
        }
        return true;
    }
    // bool checkIfPrefixExists(string word){
    //     Node* node = root;
    //     bool flag = true;
    //     for(int i = 0; i < word.size() && flag; i++){
    //         if(node->containskey(word[i])){
    //           node = node->get(word[i]);
    //           flag = flag & (node->isEnd());
    //         }
    //         else{
    //             return false;
    //         }
            
    //     }
    //     return flag;
    // }
};
string completestring(int n, vector<string>& words){
  Trie trie;
  for(auto &word : words){
    trie.insert(word);
  }
  string longest = "";
  for(auto &word : words){
    if(trie.checkIfPrefixExists(word)){
      if(word.size() > longest.size()){
        longest = word;
      }
      else if(word.size() == longest.size() && word < longest){
        longest = word;
      }
    }
  }
  return longest;
}

int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin>>words[i];
    }
    cout<<completestring(n, words)<<endl;
    return 0;
}
