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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* oddH = dummy;
        ListNode* oddT = dummy;
        ListNode* evenH = dummy;
        ListNode* evenT = dummy;
        if (head == NULL || head->next==NULL) return head;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val%2==0){
                if (evenH == dummy)
                {
                    evenH = dummy->next;
                    evenT = dummy->next;
                }else{
                    evenT->next = temp;
                    evenT = evenT->next;
                }
            }
            else{
                if (oddH == dummy)
                {
                    oddH = dummy->next;
                    oddT = dummy->next;
                }else{
                    oddT->next = temp;
                    oddT = oddT->next;
                }
            }
            temp=temp->next;
        }
        oddT->next = evenH;
        return dummy->next;
    }
};