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

bool detectCycle(Node *head) {
  if (!head || !head->next)
    return false;
  Node *fast = head->next;
  Node *slow = head;
  while (fast && fast->next && slow != fast) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow == fast;
}
