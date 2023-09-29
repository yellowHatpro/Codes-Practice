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

Node *delAddLastNode(Node *head) {
  Node *temp = head;
  if (!head || !head->next)
    return head;
  while (temp->next->next) {
    temp = temp->next;
  }
  Node *newHead = temp->next;
  temp->next = nullptr;
  newHead->next = head;
  return newHead;
}
