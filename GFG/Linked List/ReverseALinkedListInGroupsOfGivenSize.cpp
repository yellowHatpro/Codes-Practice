#include <bits/stdc++.h>
using namespace std;
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;

class Solution
{
    public:

    node* reverseUtil(node* head){
    	if (head==NULL || head->next == NULL){
    		return head;
    	}
    	node* prev = NULL;
    	node* curr = head;
    	node* next = NULL;
    	while(curr!=NULL){
    		next = curr->next;
    		curr->next = prev;
    		prev = curr;
    		curr = next;
    	}
    	return prev;
    }

    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (head==NULL || head->next==NULL || k==1){
        	return head;
        }
        node* dummy = new node(0);
        dummy->next = head;
        node* temp = dummy;
        node* prev = dummy;
        while(temp!=NULL){
        	int i = 0;
        	while(i<k){
        		if (temp==NULL){
        			break;
        		}
        		temp = temp->next;      	
        	}
        	node* next = temp->next; //null check
        	temp->next = NULL;
        	node* newList = reverseUtil(prev->next);
        	 
        }
    }
};