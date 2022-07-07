
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
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
//  recursive
Node* mergeTwoSortedLinkedListA(Node* head1 , Node* head2){
    Node* result = NULL;
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;

    if(head1->data <= head2->data){
        result = head1;
        result->next = mergeTwoSortedLinkedListA(head1->next ,head2);
    }
    else{
        result = head2;
        result->next = mergeTwoSortedLinkedListA(head1 , head2->next);
    }
    return result;
}

Node* merge(Node* head1, Node* head2){
    if (head1==NULL)
    {
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* fh = NULL;
    Node* ft = NULL;
    while(head1!=NULL&&head2!=NULL){
        if (fh==NULL)
        {
            if (head1->data<head2->data)
            {
                fh = head1;
                head1=head1->next;
            }else {
                fh = head2;
                head2=head2->next;
            }
            ft = fh;
        }
        else {
              if (head1->data<head2->data)
            {
                ft->next = head1;
                ft=ft->next;
                head1=head1->next;
            }else {
                ft->next = head2;
                ft=ft->next;                
                head2=head2->next;
            }
        }
    }
    if (head1!=NULL)
    {
        ft->next = head1;
    }
   else if (head2!=NULL)
    {
        ft->next = head2;
    }
    return fh;
}

int main(){

    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    Node* result = merge(head1 , head2);
    cout<<"Recursive O n space ";
    printList(result);
    cout<<endl;


}