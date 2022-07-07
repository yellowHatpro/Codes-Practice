#include <bits/stdc++.h>
#include <LinkedList.h>
using namespace std;

int findNode(Node* head , int n){
	if (head==NULL)
	{
		return -1;
	}
	Node* temp = head;
	int cnt = 0;
	while(temp!=NULL){
		if (temp->data==n)
		{
			return cnt;
		}
		else {
			cnt++;
		}  
		temp=temp->next;
	}
	return -1;
}

int main(){
	
	return 0;
}