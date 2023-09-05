#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      Node* temp = head;
      while(temp){
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
      temp = head;
      while(temp){
        if (temp->random) temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
      Node* dummy = new Node(0);
      Node* oldList = head;
      Node* newList = dummy;
      Node* nextOldPointer;
      while(oldList){
        nextOldPointer = oldList->next->next;
        newList->next = oldList->next;
        oldList->next = nextOldPointer;
        oldList=oldList->next;
        newList=newList->next;
    }
    return dummy->next;
  }
};
