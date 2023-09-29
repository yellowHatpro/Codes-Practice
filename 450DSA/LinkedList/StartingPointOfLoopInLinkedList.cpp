#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

Node *firstNode(Node *head) {
  if (!head || !head->next)
    return nullptr;
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
  }
  return nullptr;
}
