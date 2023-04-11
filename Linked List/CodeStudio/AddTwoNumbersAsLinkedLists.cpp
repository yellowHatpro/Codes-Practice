#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int remainder = 0;
    while(head1 && head2){
    	int sum = head1->data + head2->data + remainder;
    	head1 = head1->next;
    	head2 = head2->next;
		int a = sum%10;
		temp->next = new Node(a);    	
		remainder = sum/10;
		temp = temp->next;
    }
    while(head1){
    	int sum = head1->data + remainder;
    	int a = sum%10;
    	head1=head1->next;
    	temp->next = new Node(a);
    	remainder = sum/10;
    	temp = temp->next;
    }
    while(head2){
		int sum = head2->data + remainder;
		int a = sum%10;
		head2=head2->next;
		temp->next = new Node(a);
		remainder = sum/10;
		temp = temp->next;
	}
	if (remainder!=0){
		temp->next = new Node(remainder);
	}
	return dummy->next;
}