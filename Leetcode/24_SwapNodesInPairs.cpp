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
    ListNode* swapPairs(ListNode* head) {
    	if (head == NULL || head->next == NULL){
    		return head;
    	}
    	ListNode* dummy = new ListNode();
    	dummy->next = head;
    	ListNode* current = head;
    	ListNode* prev = dummy;
    	while(current != nullptr && current->next!=nullptr){
	    	ListNode* currentNext = current->next;
    		ListNode* temp = current->next->next;

    		prev->next = currentNext;
    		currentNext->next = current;
    		current->next = temp;

    		prev = current;
    		current = temp;

    	}
    	return dummy->next;

    }
};