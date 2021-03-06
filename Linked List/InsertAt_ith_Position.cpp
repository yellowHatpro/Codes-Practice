#include "LinkedList.h"
#include "LinkedListTakeInput.h"

void insertNode(Node* head , int i , int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 0;
    if(i==0){
        newNode->next = head;
        head = newNode;
    }
    while(temp!=NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
    Node* temp2 = temp->next;
    temp->next = newNode;
    newNode->next = temp2;
    /* or
    newNode->next = temp->next;
    temp->next = newNode;

    */
    }
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = takeInput();
    insertNode(head , 2 , 10);
}