#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(Node* head1, Node* head2){  
    if (!head1) return head2;
    if (!head2) return head1;
    if (head1->data>head2->data) swap(head1,head2);
    Node* res = head1;
    while (head1 && head2){
        Node* temp = nullptr;
        while(head1 && head1->data<=head2->data){
            temp = head1;
            head1=head1->next;
        }
        temp->next = head2;
        swap(head1,head2);
    }
    return res;
}  