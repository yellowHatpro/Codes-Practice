#include <bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* detectCycle(ListNode* A) {
	if (A==NULL) return NULL;
	ListNode* slow = A;
	ListNode* fast = A;
	while(fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
		if (fast==slow){
			break;
		}
	}
if (fast == slow){
		ListNode* head = A;
	while(head!=slow){
		head = head->next;
		slow = slow->next;
	}
	return head;
}
	return NULL;

 }