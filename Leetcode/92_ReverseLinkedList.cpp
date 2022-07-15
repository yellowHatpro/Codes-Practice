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

/*Create a dummy node , very helpful
Dummy next will point to head of the result linked list.
It also saves from edge case like if we have to reverse linked list from left=1
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
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
};