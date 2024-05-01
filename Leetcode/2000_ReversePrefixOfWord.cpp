#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reversePrefix(string word, char ch) {
    int i = 0;
    while (i < word.size() and word[i] != ch) {
      i++;
    }
    if (word[i] == ch)
      reverse(word.begin(), word.begin() + i + 1);
    return word;
  }
};
