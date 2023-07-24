#include <bits/stdc++.h>
#include <string>
using namespace std;

template <typename T>
class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void f(vector<string>& v, string s, BinaryTreeNode<int>* root){
    if (!root) return;
    if (!root->left && !root->right) {
      v.push_back(s+to_string(root->data));
      return;
    }
    f(v,s+to_string(root->data)+" ",root->left);
    f(v,s+to_string(root->data)+" ",root->right); 
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
  vector<string> v;
  if (!root) return {};
  f(v,"",root);
  return v;
}

//another problem, add the path to from root to x.

bool getPath(BinaryTreeNode<int>* root, vector<int>& arr, int x){
  if (!root) return false;
  arr.push_back(root->data);
  if (root->data==x) return true;
  bool a = getPath(root->left, arr,x);
  bool b = getPath(root->right, arr, x);
  if (a||b){
    return true;
  } else {
    arr.pop_back();
    return false;
  }
}
