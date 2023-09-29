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

bool circularLL(Node *head) {
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
    if (temp->next == head)
      return true;
  }
  return false;
}
