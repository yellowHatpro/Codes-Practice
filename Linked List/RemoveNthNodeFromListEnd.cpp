#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 
 };
ListNode* removeNthFromEnd(ListNode* A, int B) {
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
