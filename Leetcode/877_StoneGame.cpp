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

class SolutionO1 {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

class Solution {
  public:
    bool stoneGame(vector<int>& piles) {
      int n = piles.size();
      vector dp(n, vector(n,-1));
      function <int(int,int)> f = [&](int l, int r) -> int {
        if (l>r) return 0;
        if (dp[l][r]!=-1) return dp[l][r];
        int left = ((r-l)%2) ? piles[l] : 0;
        int right= ((r-l)%2) ? piles[r] : 0;
        return dp[l][r] = max(left+f(l+1,r), right+f(l,r-1));
      };
      return f(0,n-1);
  }
};
