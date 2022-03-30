#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* ans = new ListNode(0);
      	ListNode* res = ans;
      	int r = 0;

      	while(l1!=NULL &&l2!=NULL){
      		int l1_data = l1->val;
      	 	int l2_data = l2->val;
      	 	int val = (l1_data+l2_data+r)%10;
      	 	res->next = new ListNode(val);
      	 	r = (l1_data+l2_data+r)/10;
      	 	res=res->next;
      	 	l1=l1->next;
      	 	l2=l2->next;
      	}
      	while(l1!=NULL){
      		int l1_val = (l1->val+r)%10;
      		r = (l1->val + r)/10;
      		res->next = new ListNode(l1_val);
      		res=res->next;
      		l1 = l1->next;
      	}
      	while(l2!=NULL){
      		int l2_val = (l2->val+r)%10;
      		r = (l2->val + r)/10;
      		res->next = new ListNode(l2_val);
      		res=res->next;
      		l2 = l2->next;
      	}
        if(r!=0){
            res->next = new ListNode(1);
        }
      	return ans->next;
    }
};