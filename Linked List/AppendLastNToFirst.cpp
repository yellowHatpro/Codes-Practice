#include <bits/stdc++.h>
#include <LinkedList.h>

using namespace std;
 
int length(Node* head){
	int cnt = 0;
	Node* temp = head;
	while (temp!=NULL){
		cnt++;
		temp= temp->next;
	}
	return cnt;
}

Node *appendLastNToFirst(Node *head, int n)
	{
	int nn = length(head);
	int nnn = nn-n;
	if (nnn==0 || head == NULL)
	{
		return head;
	}
	Node* temp = head;
	for (int i = 0; i <nnn-1; ++i)
	{	if (temp->next!=NULL)
			{
				temp = temp->next;
			}
	}

	Node* temp2 = temp;
	while(temp->next!=NULL){
		temp= temp->next;
	}
	temp->next = head;
	head = temp2->next;
	temp2->next = NULL;
	return head;

}

int main(){
	
	return 0;
}