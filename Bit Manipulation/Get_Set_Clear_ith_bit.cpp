#include <bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i) {
  int mask = 1 << i;
  return (n & mask) > 0 ? 1 : 0;
}

// set is to set the ith bit to 1
int setIthBit(int n, int i) {
  int mask = 1 << i;
  return n | mask;
}

int clearIthBit(int n, int i) {
  int mask = 1 << i;
  mask = ~(mask);
  n = n & mask;
  return n;
}

int updateIthBit(int n, int i, int v) {
  clearIthBit(n, i);
  int mask = v << i;
  return n | mask;
}

int clearLastIBits(int n, int i) {
  int mask = (-1 << i);
  return n & mask;
}

int clearBitsInRange(int n, int j, int i) {
  int a = (-1) << (j + 1);
  int b = 1 << (i - 1);
  int mask = a | b;
  return n & mask;
}

int replaceBits(int n, int m, int i, int j) {
  int newN = clearBitsInRange(n, i, j);
  int mask = m << i;
  return n | mask;
}

void evenOrOdd(int n) {
  if ((n & (n - 1)) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return;
}

int countSetBits(int n) {
  int cnt = 0;
  while (n > 0) {
    if ((n & 1) == 1) {
      cnt++;
    }
    n = n >> 1;
  }
  return cnt;
}

int countSetBits_Faster(int n) {
  int cnt = 0;
  while (n > 0) {
    n = n & (n - 1);
    cnt++;
  }
  return cnt;
}

// and of the number and it's 2's complement
int rightmostSetBitMask(int n) { return n & -n; }

int fastExponentiation(int a, int b) {
  int ans = 1;
  while (b > 0) {
    int last_bit = b & 1;
    if (last_bit) {
      ans *= a;
    }
    a = a * a;
    b = b >> 1;
  }
  return ans;
}

int main() {
  int n = 15;
  cout << fastExponentiation(n, 2) << endl;
  return 0;
}
