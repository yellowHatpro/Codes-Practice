#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 10;
  void *ptr = &i;
  // cout<<*ptr<<endl; // void pointers cant be dereferenced
  cout << *(int *)ptr << endl; // we need to explicitly typecast it
  return 0;
}
