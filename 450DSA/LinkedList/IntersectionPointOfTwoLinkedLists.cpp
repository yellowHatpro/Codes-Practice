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

class Node{
  public:
    int data;
    Node *next;
    Node(int data)
    {
      this->data = data;
      this->next = NULL;
    }
  };

int findIntersection(Node *firstHead, Node *secondHead){
  Node* temp1 = firstHead;
  Node* temp2 = secondHead;
  if (!temp1 || !temp2) return -1;
  while (temp1 != temp2){
    temp1 = (temp1) ? temp1->next : secondHead;
    temp2 = (temp2) ? temp2->next : firstHead;
  }
  return (!temp1) ? -1 : temp1->data;
}
