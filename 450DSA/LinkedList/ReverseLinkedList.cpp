#include <bits/stdc++.h>
template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if (!head || !head->next) return head;
    LinkedListNode<int>* end = head->next;
    LinkedListNode<int>* newList = reverseLinkedList(head->next);
    end->next = head;
    head->next = nullptr;
    return newList;
}
