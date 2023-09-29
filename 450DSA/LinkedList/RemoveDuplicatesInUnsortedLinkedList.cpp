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
  if (!head)
    return head;
  unordered_map<int, int> m;
  Node *temp = head;
  while (temp && temp->next) {
    m[temp->data]++;
    if (m[temp->next->data] > 0)
      temp->next = temp->next->next;
    else
      temp = temp->next;
  }
  return head;
}
