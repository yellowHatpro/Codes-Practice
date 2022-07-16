#include <iostream>
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* oddH = NULL;
        ListNode* oddT = NULL;
        ListNode* evenH = NULL;
        ListNode* evenT = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            if (temp->val%2==0)
            {
                if (evenH==nullptr)
                {
                    evenH = temp;
                    evenT = temp;
                }else{
                    evenT->next=temp;
                }
                evenT->next = NULL;
            }else{
                if (oddH==NULL)
                {
                    oddH = temp;
                    oddT==temp;
                }else{
                    oddT->next=temp;
                }
                oddT->next = NULL;
            }
           temp=temp->next; 
        }
        if (oddH==NULL)
        {
            return evenH;
        }
        oddT->next = evenH;
        return oddH;
    }
};