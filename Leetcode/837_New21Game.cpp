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
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1);
        dp[0] = 1;
        double s = k > 0 ? 1 : 0;
        for (int i = 1; i<=n; i++) {
          dp[i] = s / maxPts;
          if (i<k) s+=dp[i];
          if (i-maxPts >= 0 && i-maxPts <k){
          s-= dp[i-maxPts];
      }
    }
    return accumulate(dp.begin()+k, dp.end(),0.0);
    }
};
