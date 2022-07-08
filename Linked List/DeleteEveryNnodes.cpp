#include <bits/stdc++.h>
#include "LinkedList.h"

Node *skipMdeleteN(Node *head, int M, int N){
	if (head==NULL || N==0)
	{
		return head;
	}
	if (M==0)
	{
		return NULL;
	}
	int cnt = 0;
	int cnt2 = 0;
	Node* temp = head;
	Node* temp2 = head;
	while(temp!=NULL){
		while(temp!=NULL && cnt<M-1){
		temp=temp->next;
		cnt++;
	}
	if (temp!=NULL) temp2 = temp->next;
	while (temp2!=NULL && cnt2<N){
		temp2=temp2->next;
		cnt2++;
	}
	if (temp!=NULL)
	{
		temp->next = temp2;
		temp=temp->next;

	}
	cnt=0;
	cnt2=0;

	}
	return head;
}
using namespace std;
int main(){
	
	return 0;
}