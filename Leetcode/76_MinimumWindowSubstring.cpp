#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.length() < t.length())
      return "";

    unordered_map<char, int> tCount;
    for (char c : t) {
      tCount[c]++;
    }

    int needCount = tCount.size();
    int haveCount = 0;
    int left = 0;
    pair<int, int> idxResultWindow = {0, INT_MAX};
    unordered_map<char, int> windowCount;

    for (int right = 0; right < s.length(); right++) {
      char currentChar = s[right];
      windowCount[currentChar]++;

      if (windowCount[currentChar] == tCount[currentChar]) {
        haveCount++;
      }

      while (haveCount == needCount) {
        if (right - left < idxResultWindow.second - idxResultWindow.first) {
          idxResultWindow = {left, right};
        }

        // Slide the left window pointer to minimize the solution
        windowCount[s[left]]--;
        if (windowCount[s[left]] < tCount[s[left]]) {
          haveCount--;
        }
        left++;
      }
    }
    return idxResultWindow.second == INT_MAX
               ? ""
               : s.substr(idxResultWindow.first,
                          idxResultWindow.second - idxResultWindow.first + 1);
  }
};
