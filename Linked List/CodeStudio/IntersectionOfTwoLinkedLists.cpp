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

int findIntersection(Node *a, Node *b) {
  Node *firstHead = a;  // This imp
  Node *secondHead = b; // We should keep track of heads
  if (!firstHead || !secondHead)
    return -1;
  while (firstHead != secondHead) {
    if (!firstHead) {
      firstHead = b;
    } else
      firstHead = firstHead->next;
    if (!secondHead) {
      secondHead = a;
    } else
      secondHead = secondHead->next;
  }
  return (!firstHead && !secondHead) ? -1 : firstHead->data;
}
