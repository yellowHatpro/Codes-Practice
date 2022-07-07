#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

Node* reverseListRecursive(Node* head){
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	Node* smallAns = reverseListRecursive(head->next);
	Node* ans = smallAns;
	while(smallAns->next!=NULL){
		smallAns=smallAns->next;
	}
	smallAns->next = head;
	head->next = NULL;

	return ans;
}

int main(){
	
	return 0;
}