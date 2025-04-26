#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *A, ListNode *B) {
  if (A == NULL)
    return B;
  else if (B == nullptr)
    return A;
  int rem = 0;
  ListNode *res = new ListNode(0);
  ListNode *ans = res;
  while (A != NULL && B != NULL) {
    int a = 0;
    int b = 0;
    if (A != NULL) {
      a = A->val;
      A = A->next;
    }
    if (B != NULL) {
      b = B->val;
      B = B->next;
    }
    res->next = new ListNode((a + b + rem) % 10);
    rem = (a + b + rem) / 10;
    res = res->next;
  }
  while (A != NULL) {
    int a = A->val;
    a = (a + rem) % 10;
    rem = (A->val + rem) / 10;
    res->next = new ListNode(a);
    res = res->next;
    A = A->next;
  }
  while (B != NULL) {
    int b = B->val;
    b = (b + rem) % 10;
    rem = (B->val + rem) / 10;
    res->next = new ListNode(b);
    res = res->next;
    B = B->next;
  }
  if (rem != 0) {
    res->next = new ListNode(1);
  }
  return ans->next;
}
