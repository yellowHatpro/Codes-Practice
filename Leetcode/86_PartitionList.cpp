#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* current = head;  
        
        ListNode* lessDummy = new ListNode(0);    
        ListNode* lessTail = lessDummy;
        
        ListNode* greaterDummy = new ListNode(0); // Dummy node for nodes >= x
        ListNode* greaterTail = greaterDummy;     // Tail pointer for greater list
        
        // Traverse the original list
        while (current != nullptr) {
            if (current->val < x) {
                // Append current node to the less list
                lessTail->next = new ListNode(current->val);
                lessTail = lessTail->next; // Move the tail pointer
            } else {
                // Append current node to the greater list
                greaterTail->next = new ListNode(current->val);
                greaterTail = greaterTail->next; // Move the tail pointer
            }
            current = current->next; // Move to the next node
        }
        
        
        // Attach the greater list to the end of the less list
        lessTail->next = greaterDummy->next;
        
        // Return the modified list starting from the first node after the less dummy node
        return lessDummy->next;
    }
};

