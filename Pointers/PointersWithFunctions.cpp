#include <bits/stdc++.h>
using namespace std;

void print(int *i) { cout << *i << endl; }

// By default arguments are passed by value
void incrementPointer(int *p) { p++; }

void increment(int *p) { (*p)++; }

int sum(int a[], int size) {
  // Inside function array is passed as a pointer, and not as an array
  // cout<<"size to tell if a is array or pointer "<<sizeof(a)<<endl;

  // That's why we can either give the args in the function as : int a[] or int*
  // a..
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += a[i];
    // sum+= *(a+i); will work fine as well..
  }

  return sum;
}

int main() {
  int x = 10;
  int *p = &x;
  //	print (p);
  cout << p << endl;
  incrementPointer(p);
  cout << p << endl;

  cout << "value before " << *p << endl;
  increment(p);
  cout << "value after " << *p << endl;

  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << sizeof(a) << endl;
  cout << sum(a, 10) << endl;
  // Since the array is passed as a pointer, we can pass the part of an array
  // like this:
  cout << sum(a + 3, 7) << endl;

  return 0;
}
