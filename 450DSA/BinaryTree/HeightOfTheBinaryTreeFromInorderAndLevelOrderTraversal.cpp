#include <bits/stdc++.h>
using namespace std;

class Temp {
public:
  int height;
  int left_index;
  int right_index;

  Temp(int h, int li, int ri) {
    height = h;
    left_index = li;
    right_index = ri;
  }
};

int heightOfTheTree(vector<int> &inorder, vector<int> &levelOrder, int N) {
  int maxHeight = 0;
  queue<Temp> q;
  if (N >= 1) {
    Temp temp(0, 0, N - 1);
    q.push(temp);
  }
  unordered_map<int, int> m;
  for (int i = 0; i < N; i++) {
    m[inorder[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    Temp temp = q.front();
    q.pop();
    maxHeight = max(temp.height, maxHeight);
    int li = temp.left_index;
    int ri = temp.right_index;
    int root_index;
    root_index = m[levelOrder[i]];
    if (root_index - 1 >= li) {
      Temp left_sub_tree(temp.height + 1, li, root_index - 1);
      q.push(left_sub_tree);
    }
    if (root_index + 1 <= ri) {
      Temp right_sub_tree(temp.height + 1, root_index + 1, ri);
      q.push(right_sub_tree);
    }
  }
  return maxHeight;
}
