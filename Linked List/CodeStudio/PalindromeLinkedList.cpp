#include <bits/stdc++.h>
using namespace std;

template <typename T> class LinkedListNode {
public:
  T data;
  LinkedListNode<T> *next;
  LinkedListNode(T data) {
    this->data = data;
    this->next = NULL;
  }
};

LinkedListNode<int> *reverse(LinkedListNode<int> *head) {
  LinkedListNode<int> *prev = nullptr;
  LinkedListNode<int> *curr = head;
  LinkedListNode<int> *next = head->next;
  while (curr) {
    curr->next = prev;
    prev = curr;
    curr = next;
    if (next)
      next = next->next;
  }
  return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
  if (!head || !head->next)
    return true;
  LinkedListNode<int> *slow = head;
  LinkedListNode<int> *fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = reverse(slow->next);
  slow = slow->next;
  LinkedListNode<int> *dum = head;
  while (dum && slow) {
    if (dum->data != slow->data)
      return false;
    dum = dum->next;
    slow = slow->next;
  }
  return true;
}
