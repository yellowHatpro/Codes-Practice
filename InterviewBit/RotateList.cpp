#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int B) {
	if (head==NULL) {
		return head;
	}
	int count = 1 ;
	ListNode* temp = head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	int newCount = B%count;
	ListNode* prev = head;
	ListNode* prevHead = prev;
	while(newCount--){
		prev = prev->next;
	}
	ListNode* newHead = prev->next;
	prev->next = NULL;
	newHead->next = prevHead;
	return newHead;
}
