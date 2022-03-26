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
    int getDecimalValue(ListNode* head) {
    	string sum = "";
    	ListNode* temp = head;
    	while(temp!=nullptr){
    		sum+=to_string(temp->val);
    		temp=temp->next;
    	}
    	int dec = stoi(sum,nullptr,2);
    	return dec;
    }
};

//Another approach:

class Solution2{
public:
	int getDecimalValue(ListNode* head){
		int res=0;
		while(head!=NULL){
			res=res*2+(head->val);
			head=head->next;
		}
		return res;
	}
};