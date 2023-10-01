#include <bits/stdc++.h>
using namespace std;

//"Hello world" -> "Hello%20world"

int main() {
  // 1. calculate all the spaces
  string str = "Hello world";
  int cnt_space = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == ' ') {
      str.replace(i, 1, "%20");
    }
  }
  cout << str << endl;
  return 0;
}
