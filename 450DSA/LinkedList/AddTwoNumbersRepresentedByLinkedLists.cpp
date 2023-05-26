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

class Node
  {
  public:
      int data;
    Node *next;
      Node(int data)
      {
          this->data = data;
          this->next = NULL;
      }
  };

Node *addTwoNumbers(Node *head1, Node *head2)
{
  Node* newNode= new Node(0);
  Node* temp = newNode;
  int rem = 0;
  while (head1 && head2){
    int sum = head1->data + head2->data + rem;
    rem = sum/10;
    sum %= 10;
    temp->next = new Node(sum);
    temp = temp->next;
    head1=head1->next;
    head2=head2->next;
  }
  while(head1){
    int sum = head1->data + rem;
    rem = sum/10;
    sum %=10;
    temp->next = new Node(sum);
    temp = temp->next;
    head1=head1->next;
  }
  while(head2){
    int sum = head2->data + rem;
    rem = sum/10;
    sum %=10;
    temp->next = new Node(sum);
    temp = temp->next;
    head2=head2->next;
  }
  if (rem!=0){
    temp->next = new Node(rem);
  }
  return newNode->next;

}
