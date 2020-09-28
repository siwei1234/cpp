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
	TreeNode* ret = new TreeNode(0), *cur = ret;
	void inOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		inOrder(root->left);
		root->left = NULL;
		cur->right = root;
		cur = root;
		inOrder(root->right);
	}
	TreeNode* convertBiNode(TreeNode* root) {
		inOrder(root);
		return ret->right;
	}
};

int main()
{
	return 0;
}