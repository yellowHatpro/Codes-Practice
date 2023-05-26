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
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2) {
  Node* temp1 = head1;
  Node* temp2 = head2;
  Node* dummy = new Node(0);
  Node* temp = dummy;
  while(temp1 && temp2){
      if (temp1->data==temp2->data){
      temp->next = new Node(temp1->data);
      temp = temp->next;
      temp1 = temp1->next;
      temp2 = temp2->next;
    } else if (temp1->data<temp2->data){
      temp1 = temp1->next;
    } else {
      temp2 = temp2->next;
    }
  }
  return dummy->next;
}
