#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *firstNode(Node *head){
	Node* fast = head;
	Node* slow = head;
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
		if (fast==slow){
			slow = head;
		while(slow!=fast){
			fast = fast->next;
			slow = slow->next;
			}
			return slow;		
		}
	}
	return nullptr;
}