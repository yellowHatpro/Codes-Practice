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

int findIntersection(Node *firstHead, Node *secondHead) {
  Node *temp1 = firstHead;
  Node *temp2 = secondHead;
  if (!temp1 || !temp2)
    return -1;
  while (temp1 != temp2) {
    temp1 = (temp1) ? temp1->next : secondHead;
    temp2 = (temp2) ? temp2->next : firstHead;
  }
  return (!temp1) ? -1 : temp1->data;
}
