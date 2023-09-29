#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

Node *findIntersection(Node *head1, Node *head2) {
  Node *temp1 = head1;
  Node *temp2 = head2;
  Node *dummy = new Node(0);
  Node *temp = dummy;
  while (temp1 && temp2) {
    if (temp1->data == temp2->data) {
      temp->next = new Node(temp1->data);
      temp = temp->next;
      temp1 = temp1->next;
      temp2 = temp2->next;
    } else if (temp1->data < temp2->data) {
      temp1 = temp1->next;
    } else {
      temp2 = temp2->next;
    }
  }
  return dummy->next;
}
