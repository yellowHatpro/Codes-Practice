#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    class node{
      public:
      int key;
      int val;
      node* next;
      node* prev;
      node(int k, int v){
        key = k;
        val = v;
    }
  };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int size;
    map<int,node*> cache;
    LRUCache(int capacity) {
      size = capacity;
      head->next = tail;
      tail->prev = head;
    }

    void addNode(node* newNode){
      node* temp = head->next;
      newNode->next = temp;
      newNode->prev = head;
      head->next = newNode;
      temp->prev = newNode;
    }

    void deleteNode(node* delNode){
      node* delprev = delNode->prev;
      node* delnext = delNode->next;
      delprev->next = delnext;
      delnext->prev = delprev;
  }
    
    int get(int key) {
      if(cache.count(key)){
        node* curr = cache[key];
        int currval = curr->val;
        cache.erase(key);
        deleteNode(curr);
        addNode(curr);
        cache[key] = head->next;
        return currval;
      }
      return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)){
          node* curr = cache[key];
          cache.erase(key);
          deleteNode(curr);
        }
        if (cache.size()==size){
          cache.erase(tail->prev->key);
          deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        cache[key]=head->next;
      }
};

