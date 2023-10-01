#include <cstring>
#include <iostream>
using namespace std;

int dp[100005][3];
int solve(int **arr, int n, int abc) {
  if (n == 0) {
    if (abc == 'a') {
      return arr[0][0];
    } else if (abc == 'b') {
      return arr[0][1];
    } else if (abc == 'c') {
      return arr[0][2];
    } else
      return 0;
  }
  if (dp[n][abc] != -1) {
    return dp[n][abc];
  }

  if (abc == 'a') {

    int ans2 = solve(arr, n - 1, 'b') + arr[n][0];
    int ans3 = solve(arr, n - 1, 'c') + arr[n][0];
    return dp[n][abc] = max(ans2, ans3);
  }
  if (abc == 'b') {

    int ans1 = solve(arr, n - 1, 'a') + arr[n][1];
    int ans3 = solve(arr, n - 1, 'c') + arr[n][1];
    return dp[n][abc] = max(ans1, ans3);
  }
  if (abc == 'c') {

    int ans1 = solve(arr, n - 1, 'a') + arr[n][2];
    int ans2 = solve(arr, n - 1, 'b') + arr[n][2];

    return dp[n][abc] = max(ans2, ans1);
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  int **arr = new int *[n];
  int a, b, c;
  for (int i = 0; i < n; i++) {
    arr[i] = new int[3];
    cin >> a >> b >> c;
    arr[i][0] = a;
    arr[i][1] = b;
    arr[i][2] = c;
  }
  memset(dp, -1, sizeof(dp));
  int x = solve(arr, n - 1, 'a');
  int y = solve(arr, n - 1, 'b');
  int z = solve(arr, n - 1, 'c');
  int res = max(x, (max(y, z)));
  cout << res << endl;
}
