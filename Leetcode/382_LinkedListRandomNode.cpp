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
 //This q is still a todo
 //Reservoir sampling is still a black box to me
 
class Solution {
public:

    ListNode *head = nullptr;

    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = 0, i = 1;
        ListNode *p = this->head;
        while(p){
            if (rand() % i == 0) ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */