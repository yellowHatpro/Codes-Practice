#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
      pushAll(root);
    }
    
    int next() {    
      TreeNode* top = s.top();
      s.pop();
      int ans = top->val;
      if (top->right){
        pushAll(top->right);  
        }
      return ans;
    }
    
    bool hasNext() {
      return !s.empty();  
    }
    
    void pushAll(TreeNode* root) {
      while(root){
        s.push(root);
        root = root->left;
      }
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
