#include <iostream>
using namespace std;

int n;
int arr[100][100] = {0};

bool isBipartite(int node, int *color) {
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (arr[node][i] != 0) {
      if (color[i] == -1) {
        color[i] = 1 - color[node];
        flag = flag and isBipartite(i, color);
      } else if (color[i] == color[node]) {
        return false;
      }
    }
  }
  return flag;
}

int main() {
  cin >> n;
  int color[n];
  for (int i = 0; i < n; i++) {
    color[i] = -1;
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      if (!isBipartite(i, color)) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
}
