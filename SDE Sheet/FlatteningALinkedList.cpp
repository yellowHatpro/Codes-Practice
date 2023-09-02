#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* merge(Node* a, Node* b){
  Node* dummy = new Node(0);
  Node* temp = dummy;
  while(a && b){
    if (a->data < b->data) {
      temp->bottom = a;
      temp = temp->bottom;
      a = a->bottom;
    } else {
      temp->bottom = b;
      temp = temp->bottom;
      b = b->bottom;
    }
  }
  if (a) temp->bottom = a; 
  else temp->bottom = b;
  return dummy->bottom;
}

Node *flatten(Node *root) {
  if (!root || !root) return root;
  root->next = flatten(root->next);
  root = merge(root, root->next);
  return root;
}

