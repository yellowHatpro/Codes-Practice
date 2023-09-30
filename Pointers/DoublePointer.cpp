#include <bits/stdc++.h>
using namespace std;

void increment1(int **p) { p++; }

void increment2(int **p) { (*p)++; }

void increment3(int **p) { (**p)++; }

int main() {
  int i = 10;
  int *ptr = &i;
  int **dptr = &ptr;
  cout << "double pointer address" << dptr << endl;
  cout << "pointer address" << ptr << endl;

  cout << "double pointer value" << *dptr << endl; // same as pointer

  cout << "double pointer containing address of pointer having value " << **dptr
       << endl;

  cout << "increment functions" << endl;
  increment1(dptr);
  cout << **dptr << endl; // no changes
  increment2(dptr);
  cout << **dptr << endl; // changes the pointer so garbage value acc to new
                          // memory location, but value changes
  increment3(dptr);
  cout << **dptr << endl; // directly affects the integer value so changes ofc
  return 0;
}
