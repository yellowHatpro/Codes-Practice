#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
 //O(n^2)
    Node* reverseLLRecursive(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* smallAns = reverseLLRecursive(head->next);
        Node* temp = smallAns;
        while(temp->next != NULL){
            temp = temp->next;//traverse till the end
        }
        temp->next = head;
        head->next = NULL;
        return smallAns;
    }
    
    
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    reverseLLRecursive(head);
    
    
    return 0;
}


