#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

Node* reverseList(Node* head){
	if (head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* smallAns = reverseList(head->next);
	Node* temp = smallAns;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallAns;
}


bool isPalindrome(Node *head){
	if (head==NULL||head->next==NULL)
	{
		return true;
	}
	Node* temp = head;
	Node* slow = head;
	Node* fast = head;
	while (fast->next!=NULL && fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	Node* newHead = slow->next;
	slow->next = NULL;
	Node* reversedList = reverseList(newHead);
	while(reversedList!=NULL){
		if (reversedList->data!=head->data)
		{
			return false;
		}
		reversedList=reversedList->next;
		head=head->next;
	}
	return true;

}

int main(){
	
	return 0;
}