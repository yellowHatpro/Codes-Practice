#include <iostream>

/*
 * 1 -> i: +1,-1, j:+1,-1
 * 2 -> j: +1,-1
 * 3 -> i: +1,-1
 * 4 -> i: +1, j: +1
 * 5 -> i: +1, j: -1
 * 6 -> i: -1, j: -1
 * 7 -> i: -1, j: +1
 * */

int up[8] = {0, 1, 1, 0, 1, 0, 0, 1};
int down[8] = {0, 1, 1, 0, 0, 1, 1, 0};
int left[8] = {0, 1, 0, 1, 0, 0, 1, 1};
int right[8] = {0, 1, 0, 1, 1, 1, 0, 0};

struct Pair {
  int first;
  int second;
  int distance;
  Pair() {
    first = 0;
    second = 0;
    distance = 0;
  }
  Pair(int f, int s, int d) {
    first = f;
    second = s;
    distance = d;
  }
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
    frontIdx = backIdx = -1;
    sizeArr = 0;
  }
  bool full() { return sizeArr == cap; }
  bool empty() {
    if (frontIdx == -1 and backIdx == -1)
      return true;
    else
      return false;
  };
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

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int ans = 0;
    int n, m, r, c, l;
    std::cin >> n >> m >> r >> c >> l;
    int **arr = new int *[n];
    int **vis = new int *[n];
    for (int i = 0; i < n; i++) {
      arr[i] = new int[m];
      vis[i] = new int[m];
      for (int j = 0; j < m; j++) {
        vis[i][j] = 0;
        std::cin >> arr[i][j];
      }
    }
    Queue<Pair> q;
    if (arr[r][c] != 0) {
      q.push(Pair(r, c, 1));
      vis[r][c] = 1;
    }
    while (!q.empty()) {
      Pair pair = q.front();
      q.pop();
      int a = pair.first;
      int b = pair.second;
      int dist = pair.distance;
      if (dist > l)
        continue;
      ans++;
      if (a - 1 >= 0 and up[arr[a][b]] and down[arr[a - 1][b]] and
          !vis[a - 1][b]) {
        vis[a - 1][b] = 1;
        q.push(Pair(a - 1, b, dist + 1));
      }
      if (a + 1 < n and down[arr[a][b]] and up[arr[a + 1][b]] and
          !vis[a + 1][b]) {
        vis[a + 1][b] = 1;
        q.push(Pair(a + 1, b, dist + 1));
      }
      if (b - 1 >= 0 and left[arr[a][b]] and right[arr[a][b - 1]] and
          !vis[a][b - 1]) {
        vis[a][b - 1] = 1;
        q.push(Pair(a, b - 1, dist + 1));
      }
      if (b + 1 < m and right[arr[a][b]] and left[arr[a][b + 1]] and
          !vis[a][b + 1]) {
        vis[a][b + 1] = 1;
        q.push(Pair(a, b + 1, dist + 1));
      }
    }
    std::cout << ans << std::endl;
  }
}
