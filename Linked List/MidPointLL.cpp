#include "LinkedList.h"
Node* midPoint(Node* head){
    if (head==NULL) return head;
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
}   
return slow;
}
//Tutle Rabbit Approach
