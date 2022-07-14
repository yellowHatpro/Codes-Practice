#include <bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children;//children are understood here to have T data type, so no need to do this: vector<TreeNode<T>*> children..
    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); ++i)
        {
            delete children[i];
        }
    }
};