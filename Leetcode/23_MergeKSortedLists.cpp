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

class Comparator{
public:
	bool operator() (ListNode* r1, ListNode* r2){
		return r1->val>r2->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int k = lists.size();
       priority_queue<ListNode*, vector<ListNode*>, Comparator> pq; // creating a min heap
       //push k listnodes, first from all ListNodes
       for(int i = 0; i<k;i++){
       		if (lists[i]) pq.push(lists[i]);
       } 
       //Create a dummy node, and a tail node
       ListNode* res = new ListNode();
       ListNode* tail = res;
       //While pq is not empty insert the top of priority queue, and insert its next into the pq
       while(!pq.empty()){
       	ListNode* temp = pq.top();
       	pq.pop();
       	tail->next = temp;
       	tail = tail->next;
       	if(temp->next) pq.push(temp->next); 
       }
       return res->next;
    }
};