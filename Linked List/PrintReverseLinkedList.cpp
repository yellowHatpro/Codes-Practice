#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

void printReverse(Node *head){
if (head==NULL)
{
	return;
}
printReverse(head->next);
cout<<head->data<<" ";
return;
}

int main(){
	
	return 0;
}