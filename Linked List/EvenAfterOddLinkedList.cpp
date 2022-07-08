#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

Node *evenAfterOdd(Node *head){
	if (head==NULL || head->next == NULL)
	{
		return head;
	}
	Node* evenList = NULL;
	Node* oddList = NULL;
	Node* oddListTail = NULL;
	Node* evenListTail = NULL;
	Node* temp = head;
	while (temp!=NULL){
		if (temp->data%2==0)
		{
			if (evenList == NULL)
			{
				evenList = temp;
				evenListTail = evenList;
				temp=temp->next;
				evenListTail->next = NULL;
			}
			else {
				evenListTail->next = temp;
				temp=temp->next;
				evenListTail=evenListTail->next;
				evenListTail->next = NULL;
			}
			
		}else {
			if (oddList==NULL)
			{	
				oddList = temp;
				oddListTail = oddList;
				temp=temp->next;
				oddListTail->next = NULL;
			}
			else {
				oddListTail->next = temp;
				temp=temp->next;
				oddListTail = oddListTail->next;
				oddListTail->next = NULL;
			}
		}
	}
	if (oddList == NULL)
	{
		return evenList;
	}
	oddListTail->next = evenList;
	return oddList;
}