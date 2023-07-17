#include <bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution{
public:
  
  void reverse(ListNode* s, ListNode* e){
    ListNode* prev = NULL;
    ListNode* curr = s;
    ListNode* next = s->next;
    while(prev!=e){
      curr->next = prev;
      prev = curr;
      curr = next;
      if (next) next = next->next;
    }  
  }

  ListNode* reverseKGroupRecursive(ListNode* head, int k){
      if (!head || !head->next) return head;
      ListNode* s = head;
      ListNode* e = head;
      int n = k-1;
      while(n--){
        e = e->next;
        if (!e) return head;
      }
      ListNode* newHead = reverseKGroupRecursive(e->next, k);
      reverse(s,e);
      s->next = newHead;
      return e;
  }

  ListNode* reverseKGroup(ListNode* head, int k){
    if (!head || !head->next || k==1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* s = head;
    ListNode* e = head;
    ListNode* n = nullptr;
    int i = 0;
    while(e){
      i++;
      if (i%k==0){
        s = prev->next;
        n = e->next;
        reverse(s,e);
        prev->next = e;
        s->next = n;
        prev = s;
        e = n;
      } else e=e->next;
    }
    return dummy->next;
  }
};
