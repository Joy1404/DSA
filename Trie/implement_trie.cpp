#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;
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
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
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
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node = root;
        for(int i =0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("app");
    obj->insert("bananafull");
    cout<<obj->search("apple")<<endl;
    cout<<obj->search("app")<<endl;
    cout<<obj->search("ap")<<endl;
    cout<<obj->startsWith("app")<<endl;
    cout<<obj->startsWith("ap")<<endl;
    cout<<obj->startsWith("a")<<endl;
    cout<<obj->startsWith("b")<<endl;
    cout<<obj->startsWith("banana")<<endl;
    cout<<obj->search("banana")<<endl;
    return 0;
}