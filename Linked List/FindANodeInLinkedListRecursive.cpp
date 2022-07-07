#include <bits/stdc++.h>
#include <LinkedList.h>

using namespace std;

int findNodeRec(Node *head, int n){
if (head==NULL)
{
	return -1;
}
else if (head->data == n)
{
	return 0;
}
int smallAns = findNodeRec(head->next,n);
if (smallAns==-1)
{
	return -1;
}
else{
	return 1+smallAns;
}
}

int main(){
	
	return 0;
}