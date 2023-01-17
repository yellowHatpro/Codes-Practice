#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
	if (A==NULL){
		return B;
	}
	if(B==NULL){
		return A;
	}
	ListNode* res = NULL;
	if (A->val<=B->val){
		res = A;
		res->next = mergeTwoLists(A->next,B);
	} else {
		res = B;
		res->next = mergeTwoLists(A,B->next);
	}
	return res;
}
