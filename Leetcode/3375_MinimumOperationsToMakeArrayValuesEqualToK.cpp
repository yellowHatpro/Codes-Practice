#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto itr : nums) {
      if (itr < k)
        return -1;
      if (itr != k)
        m[itr]++;
    }
    return m.size();
  }
};
