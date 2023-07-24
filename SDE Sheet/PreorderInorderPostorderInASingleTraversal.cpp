#include <bits/stdc++.h>
using namespace std;
    template <typename T>
    class BinaryTreeNode
    {
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
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
  if (!root) return {};
  stack<pair<BinaryTreeNode<int>*,int>> s;
  vector<int> pre;
  vector<int> in;
  vector<int> post;
  s.push({root,1});
  while(!s.empty()){
    BinaryTreeNode<int>* node = s.top().first;
    int flag = s.top().second;
    s.pop();
    if (flag==1){
    //pre
      pre.push_back(node->data);
      s.push({node,flag+1});
      if (node->left) s.push({node->left,1});
    } else if (flag==2){
      //in
      in.push_back(node->data);
      s.push({node,flag+1});
      if (node->right) s.push({node->right,1});
    } else {
      //post
      post.push_back(node->data);
    }
  }
  return {in,pre,post};
}
