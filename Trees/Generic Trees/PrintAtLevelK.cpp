//print nodes at kth depth
#include <Generic_Tree.h>

void printAtLevelK(TreeNode<int>* root, int k){
	if (!root)
	{
		return;
	}
	if (k==0)
	{
		cout<<root->data;
		return;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{
		printAtLevelK(root->children[i],k-1);
	}
	return;
}

int main(){
	
	return 0;
}

