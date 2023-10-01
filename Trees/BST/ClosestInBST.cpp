#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

int findClosestInBST(Node *root, int target) {
  if (!root)
    return target;
  int closest;
  int diff = INT_MAX;
  Node *temp = root;
  while (temp) {
    int current_diff = abs(temp->data - target);
    if (current_diff == 0) {
      return temp->data;
    }
    if (current_diff < diff) {
      diff = current_diff;
      closest = temp->data;
    }
    if (target > temp->data) {
      temp = temp->right;
    } else {
      temp = temp->left;
    }
  }
  return closest;
}
