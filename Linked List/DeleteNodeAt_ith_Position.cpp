#include "LinkedList.h"
using namespace std;
Node* deleteNode(Node* head , int i){
    if(head==NULL) return head;
    Node* temp = head;
    int count=0;
    if (i==0){
        head = head->next;
        delete temp;
        return head;
    }
    while(temp!=NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp !=NULL && temp->next!=NULL ){
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;}
     return head;
}