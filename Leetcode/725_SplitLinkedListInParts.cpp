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
  int length(ListNode *head) {
    int cnt = 0;
    while (head) {
      cnt++;
      head = head->next;
    }
    return cnt;
  }

  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int n = length(head);
    int splitSize = n / k;
    int extraspace = n % k;
    ListNode *temp = head;
    vector<ListNode *> v;
    while (k--) {
      ListNode *newHead = nullptr;
      ListNode *newTail = nullptr;
      int sz = splitSize + (extraspace > 0);
      for (int i = 0; i < sz; i++) {
        if (!newHead) {
          newHead = temp;
          newTail = temp;
        } else {
          newTail->next = temp;
          newTail = newTail->next;
        }
        if (temp) {
          temp = temp->next;
        }
      }
      if (newTail)
        newTail->next = nullptr;
      v.push_back(newHead);
      extraspace = max(0, extraspace - 1);
    }

    return v;
  }
};
