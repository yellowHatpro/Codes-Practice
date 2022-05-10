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
	ListNode* reverseList(ListNode* head){
		ListNode* pre = NULL;
		ListNode* nex = NULL;
		while(head!=NULL){
			nex = head->next;
			head->next= pre;
			pre = head;
			head = nex;
		}
		return pre;
	}
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
        	return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
        	slow=slow->next;
        	fast=fast->next->next;
        }
          ListNode *temp = slow -> next;
        slow -> next = NULL;
        //now we reverse the second half of the linked list 
        ListNode *temp2 = reverseList (temp);
        
        while (temp2 != NULL) {
            if (head -> val == temp2 -> val) {
                head = head -> next;
                temp2 = temp2 -> next;
            }
            else {
                return false;
            }
        }
        return true;
    }
};