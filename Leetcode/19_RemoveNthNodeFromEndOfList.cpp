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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode * temp = new ListNode();
        temp = head;
        while(temp!=nullptr){
        	cnt++;
        	temp=temp->next;
        }
     
        if (cnt==1) return nullptr;
	int trv = cnt - n;
	ListNode *temp2 = new ListNode();
	temp2 = head;
        if (cnt == n) return head->next;
	for (int i = 1; i < trv; ++i)
	        {   
            temp2=temp2->next;
	        	
	        }    
           
	        temp2->next = temp2->next->next;
	        return head;
    }
};

class SolutionSlowFastPtr{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n){
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
		slow->next = slow->next->next;
		return start->next;
	}
};