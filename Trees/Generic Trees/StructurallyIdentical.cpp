#include "Generic_Tree.h"


bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2) { 
	if (root1==NULL && root2==NULL)
	{
		return true;
	}
	 if( (root1==NULL && root2!=NULL) || (root1 && !root2))
	{
		return false;
	}
	
	bool a1 = root1->data==root2->data;
    if (!a1 )
	{
		return false;
	}

	bool a = false;
	for (int i = 0; i < root1->children.size(); ++i)
	{
		a = areIdentical(root1->children[i],root2->children[i]);
		if (!a)
		{
			return false;
		}
		
	}

	return true;
}