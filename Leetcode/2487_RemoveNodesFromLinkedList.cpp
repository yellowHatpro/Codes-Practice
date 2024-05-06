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
  ListNode *removeNodes(ListNode *head) {
    if (!head)
      return head;
    ListNode *smallerAns = removeNodes(head->next);
    if (head && !smallerAns) {
      return head;
    }
    if (head && smallerAns && head->val >= smallerAns->val) {
      head->next = smallerAns;
      return head;
    } else
      return smallerAns;
  }
};
