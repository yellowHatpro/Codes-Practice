#include <iostream>
using namespace std;
class node{
public:
int data;
node* next;
node(int ele){
data = ele;
next = NULL;
}
};


void insertAtlast(node* &head,node* &last,int ele){
node* n = new node(ele);
if(head==NULL){
head = n;
last = n;
return;
}
last->next = n;
last = n;
}

void delete_i(node* &head,node* &last,int i){
if(head = NULL){
cout<<"Nothing to delete"<<endl;
return;
}
if(i==0){
node*todel = head;
head=head->next;
delete todel;
return;
}
node* temp=head;
int cnt=0;
while(cnt!=i-1){
temp=temp->next;
cnt++;
}
node* todelete = temp->next;
temp->next = temp->next->next;
todelete->next = NULL;
delete todelete;
}



void display(node* head){
if(head==NULL){
return;
}
node* t= head;
while(t!=NULL){
cout<<t->data<<" ";
t=t->next;
}
cout<<endl;
}
int main(){
node* n = new node(5);
node* head = n;
node* last =n;
insertAtlast(head,last,4);
display(head);
insertAtlast(head,last,87);
display(head);
return 0;
}