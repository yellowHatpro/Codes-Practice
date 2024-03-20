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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *dummy = new ListNode(0, list1);
    ListNode *l2head = list2;
    ListNode *l2tail = list2;
    while (l2tail and l2tail->next) {
      l2tail = l2tail->next;
    }
    ListNode *temp = dummy->next;
    int aa = a;
    while (--aa > 0) {
      temp = temp->next;
    }
    ListNode *toBedeletedH = temp->next;
    ListNode *toBedeleted = temp->next;
    int dltlen = b - a + 1;
    while (toBedeleted and dltlen--) {
      toBedeleted = toBedeleted->next;
    }
    temp->next = l2head;
    l2tail->next = toBedeleted->next;
    delete toBedeletedH;
    return dummy->next;
  }
};
