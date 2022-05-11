#include <bits/stdc++.h>
using namespace std;
int main(){
	
	return 0;
}

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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head==NULL||head->next==NULL||k==0) return head;
    	
        int cnt=1;
        ListNode* cntr = head;
        while(cntr->next!=NULL){
        	cntr=cntr->next;
        	cnt++;
        }
        cntr->next = head;
       	int newHeadPos = k%cnt;
       	newHeadPos = cnt-newHeadPos;
       	for (int i = 0; i <newHeadPos ; ++i)
       	{
       		cntr=cntr->next;
       	}
       	ListNode* newHead = cntr;
       	newHead=newHead->next;
       	cntr->next = NULL;
       	return newHead;
    }
};