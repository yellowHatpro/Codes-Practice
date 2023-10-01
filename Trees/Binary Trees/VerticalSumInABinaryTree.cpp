// Using Hashmap
/*

      1
    /   \
  2      3
 / \    / \
4   5  6   7

 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

class Solution {

private:
  void verticalSumHelper(map<int, int> &hashMap, int currentNode, Node *root) {
    if (!root)
      return;
    verticalSumHelper(hashMap, currentNode - 1, root->left);
    hashMap[currentNode] += root->data;
    verticalSumHelper(hashMap, currentNode + 1, root->right);
    return;
  }

public:
  vector<int> verticalSum(Node *root) {
    map<int, int> hashmap;
    vector<int> ans;
    int currentNode = 0;
    verticalSumHelper(hashmap, currentNode, root);
    map<int, int>::iterator it;
    for (it = hashmap.begin(); it != hashmap.end(); it++) {
      ans.push_back(it->second);
    }
    return ans;
  }
};
