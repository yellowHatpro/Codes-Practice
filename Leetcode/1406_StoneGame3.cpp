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
#include <limits.h>
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
    string stoneGameIII(vector<int>& stoneValue) {
      // (p, i ) -> alice score
      int n = stoneValue.size();  
      int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
      vector dp(n+1, -1);
      function <int(int)> f = [&](int i) -> int {
        if (i>=n) return 0;
        if (dp[i]!=-1) return dp[i];
        int take = 0;
        int ans = INT_MIN;
        for (int j = i ; j < min(n,i+3); j++) {
          take+=stoneValue[j];
          ans = max(ans,take + min({f(j+2),f(j+3),f(j+4)}));
        }
      return dp[i]= take;
    }; 
    int aliceSum =  f(0);
    if (sum-aliceSum > aliceSum ) return "Bob";
    else if (sum-aliceSum < aliceSum) return "Alice";
    else return "Tie";
    }
};
