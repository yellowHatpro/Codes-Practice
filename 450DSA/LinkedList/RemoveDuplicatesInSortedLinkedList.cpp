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

Node *removeDuplicates(Node *head) {
  Node *temp = head;
  while (temp && temp->next) {
    while (temp && temp->next && temp->data == temp->next->data) {
      temp->next = temp->next->next;
    }
    temp = temp->next;
  }
  return head;
}
