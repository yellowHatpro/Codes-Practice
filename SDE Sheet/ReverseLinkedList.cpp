#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
       ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class SolutionRecursive {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* tail = head->next;
      ListNode* newHead = reverseList(head->next);
      tail->next = head;
      head->next = NULL;
      return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* prev = NULL;
      ListNode* curr = head;
      ListNode* next = head->next;
      while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next) next= next->next;
      }
      return prev;      
    }
};
