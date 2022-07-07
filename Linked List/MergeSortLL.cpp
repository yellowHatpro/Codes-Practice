#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

Node* merge(Node* head1, Node* head2){
	if (head1==NULL)
	{
		return head2;
	}
	if (head2==NULL)
	{
		return head1;
	}
	Node* res = NULL;
	if (head1->data<head2->data)
	{
		res = head1;
		res->next = merge(head1->next,head2);	
	}else{
		res = head2;
		res->next = merge(head1,head2->next);
	}
	return res;
}

Node* mid(Node* head){
	if (head == NULL||head->next==NULL)
	{
		return head;
	}
	Node* fast = head;
	Node* slow = head;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

Node* mergeSort(Node* head){
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	Node* h1 = head;
	Node* middle = mid(head);
	Node* h2 = middle->next;
	middle->next = NULL;
	Node* head1=mergeSort(h1);
	Node* head2=mergeSort(h2);
	return merge(head1,head2);

}

int main(){
	
	return 0;
}