#include <bits/stdc++.h>
#include <LinkedList.h>
using namespace std;
class StackUsingLinkedList{
	Node* head;
	int size;
public:
	StackUsingLinkedList(){
		head = NULL;
		data = 0;
	}

	int getSize(){
		return size; 
	}
	bool isEmpty(){
		return (head==NULL);
	}

	void push(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head=newNode;
		size++;
	}
	int pop(){
		if (isEmpty())
		{
			return 0;
		}
		Node* temp = head;
		int res = temp->data;
		size--;
		head=head->next;
		delete temp;
		return res;
	}
	int top(){
		if (isEmpty())
		{
			return 0;
		}
		return head->data;
	}
};