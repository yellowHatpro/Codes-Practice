#include <iostream>
using namespace std;
#define QS 1000005

struct point {
  int x, y;
};

template <class T> class Queue {
private:
  int frontIdx;
  int backIdx;
  T *arr;
  int sizeArr;
  int cap = 4;

public:
  Queue() {
    arr = new T[cap];
    sizeArr = 0;
    frontIdx = backIdx = -1;
  }
  bool full() { return sizeArr == cap; }
  bool empty() {
    if (frontIdx == -1 and backIdx == -1)
      return true;
    else
      return false;
  }
  void push(T ele) {
    if (full()) {
      cap *= 2;
      T *temp = new T[cap];
      for (int i = 0, j = frontIdx; i < sizeArr; i++) {
        temp[i] = arr[j];
        j = (j + 1) % sizeArr;
      }
      frontIdx = 0;
      backIdx = sizeArr - 1;
      delete[] arr;
      arr = temp;
    }
    if (empty()) {
      frontIdx = backIdx = 0;
      arr[backIdx] = ele;
      sizeArr++;
      return;
    }
    backIdx = (backIdx + 1) % cap;
    arr[backIdx] = ele;
    sizeArr++;
    return;
  }
  void pop() {
    if (frontIdx == backIdx) {
      frontIdx = backIdx = -1;
      sizeArr--;
      return;
    }
    frontIdx = (frontIdx + 1) % cap;
    sizeArr--;
    return;
  }
  T front() { return arr[frontIdx]; };
  int capacity() { return cap; }
  int size() { return sizeArr; }
};

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

int n, sx, sy, tx, ty;
int mat[105][105], dis[105][105], vis[105][105];

bool isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < n); }

void f() {
  Queue<point> q;
  q.push(point(sx, sy));
  vis[sx][sy] = 1;
  dis[sx][sy] = 0;
  while (!q.empty()) {
    int a = q.front().x;
    int b = q.front().y;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newX = a + dirX[i];
      int newY = b + dirY[i];
      if (isValid(newX, newY) and mat[newX][newY] != 0 and !vis[newX][newY]) {
        if (i == 0 or i == 2) {
          dis[newX][newY] = dis[a][b];
        } else if (i == 1 or i == 3) {
          dis[newX][newY] = 1 + dis[a][b];
        }
        vis[newX][newY] = 1;
        q.push(point(newX, newY));
      }
    }
  }
  cout << dis[tx][ty];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      vis[i][j] = 0;
      dis[i][j] = 0;
    }
  }
  cin >> sx >> sy >> tx >> ty;
  f();
}
