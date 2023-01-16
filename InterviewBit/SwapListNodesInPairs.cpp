#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* A) {
    if(A==nullptr || A->next==nullptr){
        return A;
    }
    ListNode* dummy = new ListNode(0);
    ListNode* current = A;
    dummy->next = current;
    ListNode* prev = dummy;
    while (current!=NULL || current->next!=NULL){
        ListNode* currentNext = current->next;
        ListNode* currentNextNext = current->next->next;
        prev->next = currentNext;
        currentNext->next = current;
        current->next = currentNextNext;

        prev = current;
        current = currentNextNext;

    }
    return dummy->next;
}
