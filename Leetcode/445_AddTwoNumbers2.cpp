#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
      if (!head || !head->next) return head;
      ListNode* prev = nullptr;
      ListNode* curr = head;
      ListNode* next = head->next;
      while(curr){
        curr->next = prev;
        prev=curr;
        curr=next;
        if(next) next = next->next;
      }
      return prev;
  }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* revl1 = reverse(l1);
      ListNode* revl2 = reverse(l2);
      ListNode* resMain = new ListNode();
      ListNode* res = resMain; 
      int rem = 0;
      while(revl1&&revl2){
        int val = revl1->val+revl2->val+rem;
        int q = val%10;
        res->next = new ListNode(q);
        res=res->next;
        rem = val/10;
        revl1=revl1->next;
        revl2=revl2->next;
      }
      while(revl1){
        int val = revl1->val+rem;
        int q = val%10;
        res->next=new ListNode(q);
        res=res->next;
        revl1=revl1->next;
        rem=val/10;
      }
      while(revl2){
        int val = revl2->val+rem;
        int q = val%10;
        res->next=new ListNode(q);
        rem=val/10;
        res=res->next;
        revl2=revl2->next;
      }
      if(rem){
        res->next = new ListNode(rem);
        res=res->next;
    }
      ListNode* ans = reverse(resMain->next);
      return ans;
    }
};
