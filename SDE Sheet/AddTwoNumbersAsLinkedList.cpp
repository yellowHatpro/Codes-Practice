#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ans = new ListNode();
      ListNode* sum = ans;
      int carry = 0;
      while(l1&&l2){
        sum->next = new ListNode((l1->val+l2->val+carry)%10);
        sum=sum->next;
        carry = (l1->val + l2->val + carry)/10;
        l1 = l1->next;
        l2 = l2->next;
      }
      while(l1){
        sum->next = new ListNode((l1->val + carry)%10);
        sum=sum->next;
        carry = (l1->val + carry)/10;
        l1 = l1->next;
      }
      while(l2){
        sum->next = new ListNode((l2->val + carry)%10);
        sum = sum->next;
        carry = (l2->val + carry)/10;
        l2 = l2->next;
      }
      while(carry){
      sum->next = new ListNode(carry);
    }
      return ans->next;
    }
};
