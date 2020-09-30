#define _CRT_SECURE_NO_WARNINGS 1




#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:

	int depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int leftdepth = depth(root->left);
		int rightdepth = depth(root->right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
	}

	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int leftdepth = depth(root->left);
		int rightdepth = depth(root->right);
		if (abs(leftdepth - rightdepth) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};

int main()
{

	return 0;
}