#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

Node* reverseLinkedList(Node* head){
	if (head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* current = head;
	Node* prev = NULL;
	Node* next = head->next;
	while(current!=NULL){
		current->next = prev;
		prev = current;
		current = next;
		if (current!=NULL)
		{
		next=current->next;
			
		}
	}
	return prev;
}


int main(){
	
	return 0;
}