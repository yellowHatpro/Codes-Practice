#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head==NULL || head->next==NULL){
		return head;
	}
	ListNode* temp = head;
	while(temp->next!=NULL){
		if (temp->next!=NULL && temp->next->val == temp->val){
			ListNode* curr = temp;
			while(curr->next!=NULL && curr->next->val==curr->val){
				curr=curr->next;
			}
			temp->next = curr->next;
		} else {
			temp=temp->next;
		}
	}
	return head;
}
