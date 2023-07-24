#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
  if (!root) return {};
  map<int,map<int,vector<int>>> m;
  queue<pair<TreeNode<int>*,pair<int,int>>> q;
  q.push({root,{0,0}});
  while(!q.empty()){
    TreeNode<int>* node = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();
    m[x][y].push_back(node->data);
    if (node->left) q.push({node->left,{x-1,y+1}});
    if (node->right) q.push({node->right,{x+1,y+1}});
  }
  vector<int> ans;
  for(auto x: m){
      for(auto y: x.second){
        for(auto z: y.second){
          ans.push_back(z);
      }
    }
  }
  return ans;
}
