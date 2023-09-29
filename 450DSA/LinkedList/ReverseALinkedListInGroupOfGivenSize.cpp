#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;
  node(int x) {
    data = x;
    next = NULL;
  }
};

// Solution valid when for <k also, we will reverse the list.
class Solution {
public:
  struct node *reverse(struct node *head, int k) {
    if (!head)
      return head;
    node *curr = head;
    node *prev = nullptr;
    node *next = nullptr;
    int cnt = 1;
    while (curr && cnt <= k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      cnt++;
    }
    if (curr)
      head->next = reverse(curr, k);
    return prev;
  }
};

// This is valid when we dont reverse the list if the length is less than k
class Solution2 {
public:
  struct node *reverse(struct node *head, int k) {
    if (!head)
      return head;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    int cnt = 1;
    while (cnt <= k && curr) {
      if (!curr)
        reverse(prev, cnt - 1);
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      cnt++;
    }
    if (next)
      head->next = reverse(next, k);
    return prev;
  }
};
