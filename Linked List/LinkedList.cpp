#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//Printing a LL
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(Node* head){
    int cnt = 0 ;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}  

