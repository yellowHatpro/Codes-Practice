#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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
//Recursive
LinkedListNode<int> *reverseLinkedListRecursive(LinkedListNode<int> *head) 
{
  if (!head || !head->next) return head;
  LinkedListNode<int>* end = head->next;
  LinkedListNode<int>* newNode = reverseLinkedListRecursive(head->next);
  end->next = head;
  head->next = NULL;
  return newNode;
}
//Iterative
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head){
  if (!head || !head->next) return head;
  LinkedListNode<int>* prev = NULL;
  LinkedListNode<int>* curr = head;
  LinkedListNode<int>* next = NULL;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
} 
