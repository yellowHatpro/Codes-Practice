#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 
 };
ListNode* removeNthFromEnd2Passes(ListNode* A, int B) {
	if (A==NULL) return NULL;
	int cnt = 0;
	ListNode* cntr = A;
	while(cntr!=NULL){
		cnt++;
		cntr=cntr->next;
	}	
	int pos = cnt - B;
	ListNode* dummy = A;
	if (cnt==1) return nullptr;
	if (cnt == B ||B > cnt) return A->next;

	for (int i = 1; i < pos; ++i)
		{
			dummy=dummy->next;
		}	
	dummy->next = dummy->next->next;
	return A;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
	if (!head) return head;
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* slow = dummy;
	ListNode* fast = dummy;
	for (int i = 0; i < n; ++i){
		fast = fast->next;
	}
	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	return dummy->next;
}
