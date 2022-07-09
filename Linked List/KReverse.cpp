#include <bits/stdc++.h>
#include <LinkedList.h>

using namespace std;

Node* kReverse(Node* head, int k){
	if (head==NULL)
	{
		return head;
	}
	//reverse firk k nodes
	Node* prev = NULL;
	Node* current = head;
	Node* temp;
	int cnt = 1;
	while(cnt<=k and current!=NULL){
		//store next
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		cnt++;

	}

	if (temp!=NULL)
	{
		Node* smallAns = kReverse(temp,k);
		head->next=smallAns;
	}
	return prev;
}

int main(){
	
	return 0;
}