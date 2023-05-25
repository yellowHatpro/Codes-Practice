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
