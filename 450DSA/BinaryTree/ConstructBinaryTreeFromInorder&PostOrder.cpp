#include <bits/stdc++.h>
using namespace std;
  
template  <class T>
class TreeNode { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };

TreeNode<int>* f(map<int,int>& inMap, vector<int>& po, int pS, int pE, vector<int>& in, int iS, int iE){
  if (iS>iE || pS > pE) return nullptr;
  TreeNode<int>* root = new TreeNode<int>(po[pE]);
  int inorderRootIndex = inMap[root->data];
  int inorderLeftRange = inorderRootIndex - iS;
  root->left = f(inMap, po, pS, pS+inorderLeftRange-1, in, iS, inorderRootIndex-1);
  root->right = f(inMap, po, pS+inorderLeftRange, pE-1, in, inorderRootIndex+1, iE);
  return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
  map<int,int> inMap;
  for (int i = 0; i < inOrder.size(); i++) {
    inMap[inOrder[i]] = i;
  }
  return f(inMap, postOrder, 0, postOrder.size()-1, inOrder, 0, inOrder.size()-1);
}

