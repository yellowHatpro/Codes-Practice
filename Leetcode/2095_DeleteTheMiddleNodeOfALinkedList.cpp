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
    ListNode* deleteMiddle(ListNode* head) {
    	if (head->next==nullptr)
    	{
    		return nullptr;
    	}
        ListNode* hare = head->next->next;
        ListNode* turtle = head;
        while(hare!=NULL && hare->next!=NULL){
        	
        	hare=hare->next->next;        		
        	turtle=turtle->next;
        }
        turtle->next = turtle->next->next;
        return head;
    }
};