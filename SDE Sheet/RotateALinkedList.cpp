#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head || k==0) return head;
      int n = 1;
      ListNode* temp = head;
      while(temp->next){
        n++;
        temp = temp->next;  
      }
      temp->next = head;
      k = k%n;
      int sz = n-k;
      for(int i=0; i<sz; i++){
        temp=temp->next;
    }
      ListNode* newHead = temp->next;
      temp->next = nullptr;
      return newHead; 
  }
};
