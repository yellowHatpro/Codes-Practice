#include <bits/stdc++.h>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
   if (A==NULL || B==NULL) return NULL;
   ListNode* a = A;
   ListNode* b = B;
   while(a!=b){
   	a = (a) ? a->next : B;
   	b = (b) ? b->next : A;
   }
   return a;
}
