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
  ListNode *removeZeroSumSublists(ListNode *temp) {
    map<int, ListNode *> m;
    ListNode *dummy = new ListNode(0);
    dummy->next = temp;
    m[0] = dummy;
    int cnt = 0;
    while (temp) {
      cnt += temp->val;
      if (m.find(cnt) != m.end()) {
        ListNode *start = m[cnt];
        ListNode *itr = start;
        int pSum = cnt;
        while (itr != temp) {
          itr = itr->next;
          pSum += itr->val;
          if (itr != temp) {
            m.erase(pSum);
          }
        }
        start->next = temp->next;
      } else {
        m[cnt] = temp;
      }
      temp = temp->next;
    }
    return dummy->next;
  }
};
