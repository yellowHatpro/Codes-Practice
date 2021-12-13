#include <iostream>
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
//O n
Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(!data==-1){
       Node* newNode = new Node(data);
       if(head==NULL){
      head =newNode;
      tail=head;}
      else{
      tail->next = newNode;
      tail= tail->next;
      //or tail = newNode;
    }
      cin>>data;
    }
    return head;
}