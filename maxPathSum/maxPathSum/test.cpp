#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
	int ret = INT_MIN;
public:
	int _maxPathSum(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = max(0, _maxPathSum(root->left));
		int right = max(0, _maxPathSum(root->right));
		int newpath = root->val + left + right;
		ret = max(ret, newpath);
		return root->val + max(left, right);
	}
	int maxPathSum(TreeNode* root) {
		_maxPathSum(root);
		return ret;
	}
};

int main()
{
	return 0;
}