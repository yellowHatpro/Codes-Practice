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
  ListNode *reverse(ListNode *list) {
    if (!list or !list->next)
      return list;
    ListNode *tail = list->next;
    ListNode *smallerAns = reverse(list->next);
    tail->next = list;
    list->next = nullptr;
    return smallerAns;
  }
  ListNode *doubleIt(ListNode *head) {
    ListNode *reversedHead = reverse(head);
    ListNode *dummy = new ListNode(0, reversedHead);
    ListNode *temp = dummy->next;
    int carry = 0;
    while (temp) {
      int tempVal = temp->val;
      temp->val = ((temp->val * 2) + carry) % 10;
      carry = ((tempVal * 2) + carry) / 10;
      if (!temp->next) {
        if (carry >= 1) {
          temp->next = new ListNode(carry);
        }
        break;
      }
      temp = temp->next;
    }

    return reverse(dummy->next);
  }
};
