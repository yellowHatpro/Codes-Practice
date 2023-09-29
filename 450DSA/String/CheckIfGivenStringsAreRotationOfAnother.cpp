#include <bits/stdc++.h>
using namespace std;

int isCyclicRotation(string &p, string &q) {
  string pp = p + p;
  if (pp.find(q) == pp.npos)
    return 0;
  return 1;
}
