#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<string, int> newmap;
  newmap["abc"] = 1;
  newmap["abc1"] = 2;
  newmap["abc2"] = 3;
  newmap["abc3"] = 4;
  newmap["abc4"] = 5;
  newmap["abc5"] = 6;
  newmap["abc6"] = 7;
  unordered_map<string, int>::iterator itr;
  itr = newmap.begin();
  while (itr != newmap.end()) {
    cout << "Key: " << itr->first << " Value: " << itr->second << endl;
    itr++;
  }
  cout << endl;
  return 0;
}
