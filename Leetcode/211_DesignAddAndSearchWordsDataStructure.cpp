#include <bits/stdc++.h>
using namespace std;


class TrieNode{
public:
    bool is_word;
    TrieNode* children[26];

    TrieNode(){
        is_word = false;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        m.clear(); // maybe we added a word which was false in map
        int len = word.size();
        int k = 0;
        TrieNode* temp = root;
        for (int i = 0; i < len; ++i)
        {
            k = word[i]-'a';
            if (!temp->children[k]) temp->children[k] = new TrieNode();
            temp = temp->children[k];
        }
        temp->is_word = true;
    }
    
    bool search(string word) {
        if (m.count(word)) return m[word]; 
        int len = word.size();
        TrieNode* temp = root;
        return m[word] = search(word,0,temp);
    }
private:
    map<string,bool> m;
    bool search(string word, int i, TrieNode* node){
        int k = word.size();
        if (!node) return false;
        if (i==k) return node->is_word;
        if (word[i]=='.'){
            for (int j = 0; j < 26; ++j)
            {
                if (search(word, i+1,node->children[j])) return true;   
            }
            return false;
        } else {
            return search(word,i+1,node->children[word[i]-'a']);
            
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */