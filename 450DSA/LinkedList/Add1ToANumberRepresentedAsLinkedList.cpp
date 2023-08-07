#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    
    Node* reverse(Node* head){
      if (!head || !head->next) return head;
      Node* curr = head;
      Node* prev = nullptr;
      Node* next = nullptr;
      while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      return prev;
    }
  
    Node* addOne(Node *head) {
      Node* temp = reverse(head);
      Node* chain = temp;
      Node* prev = nullptr;
      int flag = 1;
      while(chain){
        chain->data +=flag;
        if (chain->data>9){
          chain->data %=10;
          flag = 1;
        } else {
          flag = 0;
          break;
        }
        prev = chain;
        chain=chain->next;
      }
      if (flag==1){
        prev->next = new Node(1);
      }
      return reverse(temp);
    }
};
