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

Node *addTwoNumbers(Node *head1, Node *head2) {
  Node *newNode = new Node(0);
  Node *temp = newNode;
  int rem = 0;
  while (head1 && head2) {
    int sum = head1->data + head2->data + rem;
    rem = sum / 10;
    sum %= 10;
    temp->next = new Node(sum);
    temp = temp->next;
    head1 = head1->next;
    head2 = head2->next;
  }
  while (head1) {
    int sum = head1->data + rem;
    rem = sum / 10;
    sum %= 10;
    temp->next = new Node(sum);
    temp = temp->next;
    head1 = head1->next;
  }
  while (head2) {
    int sum = head2->data + rem;
    rem = sum / 10;
    sum %= 10;
    temp->next = new Node(sum);
    temp = temp->next;
    head2 = head2->next;
  }
  if (rem != 0) {
    temp->next = new Node(rem);
  }
  return newNode->next;
}
