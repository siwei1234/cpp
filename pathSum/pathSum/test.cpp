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

	void _pathSum(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int> tmp)
	{
		if (root == NULL)
			return;
		sum -= root->val;
		tmp.push_back(root->val);
		if (sum == 0 && root->left == NULL && root->right == NULL)
		{
			ret.push_back(tmp);
		}
		_pathSum(root->left, sum, ret, tmp);
		_pathSum(root->right, sum, ret, tmp);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> tmp;

		_pathSum(root, sum, ret, tmp);
		return ret;
	}
};


int main()
{
	return 0;
}