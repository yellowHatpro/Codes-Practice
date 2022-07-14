#include <Generic_Tree.h>

TreeNode<int>* getNextLargerElement(TreeNode<int> *root, int n) {
	if (!root)
	{
		return NULL;
	}
	TreeNode<int>* ans = NULL;
	if (root->data>n)
	{
		ans = root;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{
		TreeNode<int>* newNode = getNextLargerElement(root->children[i],n);
		if (!ans)
		{
			ans = newNode;
		}else{
			if (newNode->data<ans->data && newNode->data>n)
			{
				ans = newNode;
			}
		}
	}
	return ans;

}