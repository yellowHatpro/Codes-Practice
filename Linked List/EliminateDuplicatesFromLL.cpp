#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;

Node *removeDuplicates(Node *head) {
  if (head == NULL) {
    return head;
  }
  int current = head->data;
  Node *temp = head;
  while (temp->next != NULL) {
    if (temp->next->data == temp->data) {
      temp->next = temp->next->next;
    } else {
      current = temp->data;
      temp = temp->next;
    }
  }
  return head;
}
int main() { return 0; }
