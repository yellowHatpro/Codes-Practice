#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    vector<int> evenNumbers, oddNumbers; // Containers for even and odd numbers

    // Separate even and odd numbers
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0)
        evenNumbers.push_back(nums[i]); // Even number found
      else
        oddNumbers.push_back(nums[i]); // Odd number found
    }

    // Combine even and odd numbers, placing even numbers first
    for (int num : oddNumbers) {
      evenNumbers.push_back(num);
    }

    return evenNumbers; // Return the sorted array
  }
};
