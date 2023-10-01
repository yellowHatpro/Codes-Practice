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

Node *createBSTfromSortedArrayH(vector<int> v, int l, int r) {
  if (l > r)
    return NULL;
  int mid = r - (r - l) / 2;
  Node *root = new Node(v[mid]);
  root->left = createBSTfromSortedArrayH(v, l, mid - 1);
  root->right = createBSTfromSortedArrayH(v, mid + 1, r);
  return root;
}

Node *createBSTfromSortedArray(vector<int> &v) {

  return createBSTfromSortedArrayH(v, 0, v.size() - 1);
}

int main() { return 0; }
