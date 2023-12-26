#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  bool is_word;
  TrieNode *children[26];
  TrieNode() {
    is_word = false;
    for (int i = 0; i < 26; ++i) {
      children[i] = NULL;
    }
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    int wordLen = word.size();
    int k = 0;
    TrieNode *temp = root;
    for (int i = 0; i < wordLen; ++i) {
      k = word[i] - 'a';
      if (!temp->children[k])
        temp->children[k] = new TrieNode();
      temp = temp->children[k];
    }
    temp->is_word = true;
  }

  bool search(string word) {
    int wordLen = word.size();
    int k = 0;
    TrieNode *temp = root;
    for (int i = 0; i < wordLen; ++i) {
      k = word[i] - 'a';
      temp = temp->children[k];
      if (!temp)
        return false;
    }
    return temp->is_word;
  }

  bool startsWith(string prefix) {
    int wordLen = prefix.size();
    int k = 0;
    TrieNode *temp = root;
    for (int i = 0; i < wordLen; ++i) {
      k = prefix[i] - 'a';
      temp = temp->children[k];
      if (!temp)
        return false;
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
