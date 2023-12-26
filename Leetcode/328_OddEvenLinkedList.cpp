#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode *oddDummy = new ListNode(0);
    ListNode *evenDummy = new ListNode(0);
    ListNode *temp = head;
    ListNode *tempO = oddDummy;
    ListNode *tempE = evenDummy;
    int cnt = 0;
    while (temp != nullptr) {
      cnt++;
      if (cnt % 2 != 0) {
        tempO->next = temp;
        tempO = tempO->next;
      } else {
        tempE->next = temp;
        tempE = tempE->next;
      }
      temp = temp->next;
      tempO->next = nullptr;
      tempE->next = nullptr;
    }
    tempO->next = evenDummy->next;
    return oddDummy->next;
  }
};
