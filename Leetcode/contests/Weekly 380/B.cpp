#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rabinKarp(const string &text, const string &pattern) {
    const int p = 31;
    const int m = 1e9 + 9;

    int tLen = text.length();
    int sLen = pattern.length();

    vector<long long> pPow(max(sLen, tLen));
    pPow[0] = 1;

    for (int i = 1; i < pPow.size(); ++i)
      pPow[i] = (pPow[i - 1] * p) % m;

    vector<long long> hashText(tLen + 1);

    for (int i = 0; i < tLen; ++i)
      hashText[i + 1] = (hashText[i] + (text[i] - 'a' + 1) * pPow[i]) % m;

    long long hashPattern = 0;

    for (int i = 0; i < sLen; ++i)
      hashPattern = (hashPattern + (pattern[i] - 'a' + 1) * pPow[i]) % m;

    vector<int> occurences;

    for (int i = 0; i + sLen - 1 < tLen; ++i) {
      long long currHash = (hashText[i + sLen] + m - hashText[i]) % m;

      if (currHash == hashPattern * pPow[i] % m)
        occurences.push_back(i);
    }

    return occurences;
  }

  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> ib = rabinKarp(s, b), res;
    for (int i : rabinKarp(s, a)) {
      auto it = upper_bound(begin(ib), end(ib), i);
      if (it != end(ib) && abs(i - *it) <= k)
        res.push_back(i);
      else if (it != begin(ib) && abs(*prev(it) - i) <= k)
        res.push_back(i);
    }
    return res;
  }
};
