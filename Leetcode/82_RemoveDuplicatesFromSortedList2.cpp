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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next == NULL){
        	return head;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        while(head!=NULL){
        	bool dupl = false;
        	while(head->next!=nullptr && head->next->val == head->val){
        		head = head->next;
				dupl = true;
        	}
        	if (dupl){
        		prev->next = head->next;
        	}else {
        		prev = prev->next;
        	}
        	head = head->next;
        }
        return dummy->next;
    }
};