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
    Node* left;
    Node* right;
};

vector<int> reverseLevelOrder(Node *root)
{
  stack<vector<int>> s;
  vector<int> v;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    vector<int> currRow;
    for(int i=0; i<n;i++){
      auto node = q.front();
      q.pop();
      currRow.push_back(node->data);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    s.push(currRow);
  }
  while(!s.empty()){
    auto stop = s.top();
    for (auto itr  : stop ) {
      v.push_back(itr); 
    }
    s.pop();
  }
  return v;
}
