#include <bits/stdc++.h> 
struct Node{
    Node* link[26];
    int ce = 0;
    int cp = 0;

    bool containsKey(char ch){
        return link[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    void increaseEnd(){
        ++ce;
    }
    void increasePrefix(){
        ++cp;
    }
    void deleteEnd(){
        --ce;
    }
    void reducePrefix(){
        --cp;
    }
    int getEnd(){
        return ce;
    }
    int getPrefix(){
        return cp;
    }
};
class Trie{
    private: Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); ++i){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); ++i){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); ++i){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }

        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); ++i){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};
