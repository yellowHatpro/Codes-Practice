#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//1->2->3->4->5  2, 4
//Res : 1->4->3->2->5

ListNode* reverseBetween(ListNode* head, int left, int right) {
 if(head->next==NULL || left==right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* Lprev = dummy;
        ListNode* curr = head;
        for (int i = 0; i < left-1; ++i)
        {
            Lprev=Lprev->next;
            curr=curr->next;
        }
        ListNode* prev = NULL;
        for (int i = 0; i < right-left+1; ++i)
        {   
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
      
        }
        Lprev->next->next = curr;
        Lprev->next = prev;
        return dummy->next;

}
