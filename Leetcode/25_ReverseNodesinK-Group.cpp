#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
           if (head==nullptr){
           	return head;
           }
           ListNode* curr = head;
           ListNode* next = NULL;
           ListNode* prev = NULL;

           int cnt = 1;
           while(cnt<=k){
               if(curr==NULL) return reverseKGroup(prev,cnt-1);
           		next = curr->next;
           		curr->next = prev;
           		prev = curr;
           		curr = next;
           	
           		cnt++;
           }
        	if (next!=NULL)
        	{
        		head->next = reverseKGroup(next,k);
        	}
        	return prev;
    }
};