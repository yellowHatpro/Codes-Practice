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
 
 ListNode* merge(ListNode* h1, ListNode* h2){
 	if (!h1) return h2;
 	if (!h2) return h1;
 	ListNode* res = NULL;
 	if  (h1->val>h2->val){
 		res = h1;
 		res->next= 	merge(h1->next,h2);
 } else {
 	res = h1;
 	res->next = merge(h1,h2->next);
 }  
 return res;
}


 ListNode* mid(ListNode* head){
 	ListNode* slow = head;
 	ListNode* fast = head;
 	while(fast->next && fast->next->next){
 		slow = slow->next;
 		fast = fast->next->next;
 	}
 	return slow;
 }
 ListNode* sortList(ListNode* head){
 	if (!head || !head->next) return head;
 	ListNode* h1 = head;
 	ListNode* h2 = mid(head)->next;
 	return merge(h1,h2);
	}
};