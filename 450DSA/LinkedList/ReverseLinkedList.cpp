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
// Recursive
LinkedListNode<int> *reverseLinkedListRecursive(LinkedListNode<int> *head) {
  if (!head || !head->next)
    return head;
  LinkedListNode<int> *end = head->next;
  LinkedListNode<int> *newNode = reverseLinkedListRecursive(head->next);
  end->next = head;
  head->next = NULL;
  return newNode;
}
// Iterative
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
  if (!head || !head->next)
    return head;
  LinkedListNode<int> *prev = NULL;
  LinkedListNode<int> *curr = head;
  LinkedListNode<int> *next = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
