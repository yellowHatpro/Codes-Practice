#include <bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
  
    ListNode* reverse(ListNode* head){
      if (!head|| !head->next) return head;
      ListNode* prev = nullptr;
      ListNode* curr = head;
      ListNode* next = head->next;
      while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next) next=next->next;
    }
    return prev;
  }

    bool isPalindrome(ListNode* head) {
      if (!head|| !head->next) return head;
      ListNode* slow = head;
      ListNode* fast = head;
     while(fast->next!=NULL&&fast->next->next!=NULL){
        	slow=slow->next;
        	fast=fast->next->next;
        }
     ListNode *temp = slow -> next;     
     slow->next = nullptr;
     ListNode* head2 = reverse(temp);
     while(head2){
        if (head->val != head2->val) return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
  }
};
