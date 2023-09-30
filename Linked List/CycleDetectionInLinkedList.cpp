#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  // Create fast and Slow pointer
  ListNode *fast = head;
  ListNode *slow = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}
