#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* giveNthNodeFromEnd(ListNode* head, int n){
		ListNode* start = new ListNode();
		start -> next = head;
		ListNode* slow = start;
		ListNode* fast = start;
		for (int i = 0; i < n; ++i)
		{
			fast = fast->next;
		}
		while(fast->next!=nullptr){
			fast=fast->next;
			slow=slow->next;
		}
		return slow->next;
	}

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        for (int i = 0; i<k-1;i++){
            start = start->next;
        }
        ListNode* end = giveNthNodeFromEnd(head,k);
				int temp = start->val;
				start->val = end->val;
				end->val = temp;
			return head;
    }
};