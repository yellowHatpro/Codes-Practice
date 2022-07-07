#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

Node* reverseLinkedListRecursiveOptimisedABit(Node* head){
	if (head==NULL || head->next==NULL)
	{
		return head;
	}

	Node* tail = head->next;
	Node* smallAns = reverseLinkedListRecursiveOptimisedABit(head->next);
	tail->next = head;
	head->next = NULL;
	return smallAns;

}