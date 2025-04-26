#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int characterReplacement(string s, int k) {
    set<char> st;
    for (int i = 0; i < s.size(); ++i) {
      st.insert(s[i]);
    }
    int maxlen = 0;
    for (auto letter : st) {
      int l = 0;
      int cnt = 0;
      for (int r = 0; r < s.size(); ++r) {
        if (s[r] == letter) {
          cnt++;
        }
        while (r + 1 - l - cnt > k) {
          if (s[l] == letter)
            cnt--;
          l++;
        }
        maxlen = max(r - l + 1, maxlen);
      }
    }
    return maxlen;
  }
};

class SolutionUsingAllCharacters {
public:
  int characterReplacement(string s, int k) {
    int maxLen = 0;
    string allCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < allCharacters.length(); i++) {
      char mainCharacter = allCharacters[i];
      int l = 0;
      int allowedBadCharacters = 0;
      int localMaxima = 0;
      for (int r = 0; r < s.size(); r++) {
        if (s[r] != mainCharacter) {
          allowedBadCharacters++;
        }
        while (allowedBadCharacters > k) {
          if (s[l] != mainCharacter) {
            allowedBadCharacters--;
          }
          l++;
        }
        localMaxima = max(localMaxima, r - l + 1);
      }
      maxLen = max(maxLen, localMaxima);
    }
    return maxLen;
  }
};
