#include "Generic_Tree.h"
#include <bits/stdc++.h>
using namespace std;

bool isPresent(TreeNode<int> *root, int x) {
  if (!root) {
    return false;
  }
  bool isIt = false;
  for (int i = 0; i < root->children.size(); ++i) {
    if (isIt) {
      return true;
    }
    isIt = isPresent(root->children[i], x);
  }
  if (isIt || root->data == x) {
    return true;
  }
  return isIt;
}

int main() { return 0; }
