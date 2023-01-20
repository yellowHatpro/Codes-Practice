#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverse(ListNode* head){
	if (head==NULL || head->next==NULL)
	{
		return head;
	}
	ListNode* current = head;
	ListNode* prev = NULL;
	ListNode* next = head->next;
	while(current!=NULL){
		current->next = prev;
		prev = current;
		current = next;
		if (current!=NULL)
		{
		next=current->next;
			
		}
	}
	return prev;
}

int lPalin(ListNode* A) {
	if (A==NULL || A->next == NULL){
		return 1;
	}
	ListNode* slow = A;
	ListNode* fast = A->next;
	while(fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* newHead = slow->next;
	slow->next = NULL;
	newHead = reverse(newHead);
	ListNode* head = A;
	while(head!=NULL && newHead!=NULL){
		if (head->val!=newHead->val){
			return 0;
		}
		head = head->next;
		newHead = newHead->next;
	}
	return 1;
}
