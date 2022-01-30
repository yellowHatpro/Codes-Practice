#include "LinkedList.h"
Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
     Node *temp = head, *prev = NULL; 
    Node *node1 = NULL, *node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    int pos = 0;
    
    // if i and j are equal
    if(i == j) return head; //No changes
    
    while(temp != NULL) {
        if(pos == i) {
            node1_prev = prev; 
            node1 = temp;
        }
        else if(pos == j) {
            node2_prev = prev; node2 = temp;
        }
        prev = temp;
        temp = temp -> next; pos++; 
    }
    if(node1_prev != NULL) {
        node1_prev -> next = node2;
    }
    else { 
        head = node2;
    }
    if(node2_prev != NULL) { 
        node2_prev -> next = node1; 
    }
    else {
        head = node1;
    }
    Node *temp1 = node2 -> next;
    node2 -> next = node1 -> next; 
    node1 -> next = temp1;
    return head;
}