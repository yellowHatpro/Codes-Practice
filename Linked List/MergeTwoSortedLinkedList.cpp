
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
    if (!head1) return head2;
    if (!head2) return head1;
    if (head1->data>head2->data) swap(head1,head2);
    Node* res = head1; //res points to the smaller list
    while(head1 && head2){
        Node* temp = NULL; 
        while (head1 && head1->data<=head2->data){
            temp = head1; //temp points to head1 till the time its smaller than head2
            head1=head1->next;
        }
        temp->next = head2;
        swap(head1, head2);
    }
    return res;
 
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
    cout<<"Iterative O 1 space ";
    printList(result);
    cout<<endl;


}