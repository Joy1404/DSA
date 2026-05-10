#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
   int cntEndwith = 0;
   int cntPrefix = 0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        // put the new node in place of ch
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
   void incCntEndWith(){
    cntEndwith++;
   }
   void incCntPrefix(){
    cntPrefix++;
   }
   void decCntPrefix(){
    cntPrefix--;
   }
   void decCntEndWith(){
    cntEndwith--;
   }
   int getCntEndWith(){
    return cntEndwith;
   }
   int getCntPrefix(){
    return cntPrefix;
   }
};
class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            // moves to the refered node
            node = node->get(word[i]);
            node->incCntPrefix();
        }
        node->incCntEndWith();
    }
    int countWordsEqualTo(string word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getCntEndWith();
    }
    int countWordsStartingWith(string prefix){
        Node* node = root;
        for(int i =0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->getCntPrefix();
    }
    void erase(string word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node = node->get(word[i]);
            node->decCntPrefix();
        }
        node->decCntEndWith();
    }
};
int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("app");
    obj->insert("bananafull");
    cout<<obj->countWordsEqualTo("apple")<<endl;
    cout<<obj->countWordsEqualTo("app")<<endl;
    cout<<obj->countWordsEqualTo("ap")<<endl;
    cout<<obj->countWordsStartingWith("app")<<endl;
    cout<<obj->countWordsStartingWith("ap")<<endl;
    cout<<obj->countWordsStartingWith("a")<<endl;
    obj->erase("apple");
    cout<<obj->countWordsEqualTo("apple")<<endl;
    cout<<obj->countWordsStartingWith("app")<<endl;
    return 0;
}