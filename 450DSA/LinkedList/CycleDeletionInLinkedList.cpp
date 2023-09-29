#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

bool detectAndRemoveCycle(Node *head) {
  if (!head || !head->next)
    return false;
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      if (slow == head) {
        while (fast->next != slow) {
          fast = fast->next;
        }
      } else {
        slow = head;
        while (slow->next != fast->next) {
          slow = slow->next;
          fast = fast->next;
        }
      }
      fast->next = NULL;
      return true;
    }
  }
  return false;
}
