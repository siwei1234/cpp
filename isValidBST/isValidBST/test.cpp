#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> ans;

	void inorder(TreeNode* root)
	{
		if (root)
		{
			inorder(root->left);
			ans.push_back(root->val);
			inorder(root->right);
		}
	}

	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		inorder(root);
		for (int i = 0; i < ans.size() - 1; i++)
		{
			if (ans[i + 1] <= ans[i])
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}