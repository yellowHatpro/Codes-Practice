#include <bits/stdc++.h>
#include "LinkedList.h"

class Pair{
public:
	Node* head;
	Node* tail;
	Pair(Node* head, Node* tail){
		this->head = head;
		this->tail = tail;
	}
};

//T(n) = T(n-1) + k
//O(n.k) ~~ O(n)
Pair reverseLinkedList(Node* head){
	if (head==NULL || head->next == NULL)
	{
		Pair a = Pair(head,head);
		return a;
	}

	Pair pair= reverseLinkedList(head->next);
	pair.tail->next = head;
	head->next = NULL;
	Pair res = Pair(pair.head,head);
	return res;
}

Pair reverseLinkedListBetter(Node* head){
	return reverseLinkedList(head).head;
}

using namespace std;
int main(){
	
	return 0;
}