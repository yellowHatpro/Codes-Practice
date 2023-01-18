#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

	ListNode* reverse(ListNode* head){
		ListNode* prev = NULL;
		ListNode* curr = head;
		while(curr!=NULL){
			ListNode* temp = curr->next;
			curr->next = temp;
			temp->next = curr;
			prev = curr;
			curr = curr->next;
		}
		return prev;
	}

    void reorderList(ListNode* head) {
        if (head == NULL || head->next==NULL){
        	return;
        }
        ListNode* fast = head;
       	ListNode* slow = head;
       	while (fast->next!=NULL && fast->next->next!=NULL){
       		slow = slow->next;
       		fast = fast->next->next;
       	}
       	ListNode* headRev = slow->next;
       	slow->next = NULL;
       	headRev= reverse(headRev);
       	ListNode* temp = head;
       	ListNode* dummy = NULL;
       	while(temp!=NULL && headRev!=NULL){
       		dummy->next = temp;
       		temp=temp->next;
       		dummy=dummy->next;
       		dummy->next = headRev;
       		dummy=dummy->next;
       		headRev=headRev->next;
       	}
       	if (temp!=NULL){
       		dummy->next = temp;
       		dummy=dummy->next;
       		dummy->next = NULL;
       	} 
    }
};