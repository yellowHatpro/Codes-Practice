#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode*  reverseList(ListNode* head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //at the end prev will be the last not null node, so it will act as head
    return prev;
}

ListNode* reorderList(ListNode* head) {
    //Find the mid point
    ListNode* slow = head;
    ListNode* fast = slow->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //2. Split the linked list in two halves
    ListNode* head1 = head;
    ListNode* head2 = slow->next;
    slow->next = NULL;

    ListNode* head2Reversed = reverseList(head2);

    head = new ListNode(0);
    ListNode* temp = head;
    while(head1||head2Reversed){
        if (head1){
            temp->next = head1;
        temp=temp->next;
        head1=head1->next;    
        } 
        if (head2Reversed){
            temp->next = head2Reversed;
            temp=temp->next;
            head2Reversed=head2Reversed->next;
        }
        
    }
    return head->next;
}


