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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* smallAns = reverseList(head->next);
        ListNode* temp = smallAns;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = head;
        head->next = NULL;
        return smallAns;
    }
};

class SolutionIterative {
public:
    ListNode* reverseList(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* prev = nullptr,curr = head, next = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next->next) next = next->next;
        }
        return prev;
    }
};