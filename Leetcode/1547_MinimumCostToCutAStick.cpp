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

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
      int m = cuts.size();
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(), cuts.end());
      vector dp(m+1, vector<int>(m+1,-1));
      function <int(int,int)> f = [&](int i, int j) -> int {
        if (i>j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int cost = 0;
        int mini = INT_MAX;
        for(int idx = i; idx<=j; idx++){
          cost = cuts[j+1] - cuts[i-1] + f(i, idx-1) + f(idx+1, j);
        mini = min(mini, cost);
      }
      return dp[i][j] = mini;
    };
    return f(1,m);
  }
}; 
