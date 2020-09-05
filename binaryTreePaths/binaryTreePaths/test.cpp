#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
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
	void _binaryTreePaths(TreeNode* root, string tmp, vector<string>& ret)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			tmp += to_string(root->val);
			ret.push_back(tmp);
			return;
		}

		tmp += to_string(root->val);
		tmp += "->";
		_binaryTreePaths(root->left, tmp, ret);
		_binaryTreePaths(root->right, tmp, ret);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		_binaryTreePaths(root, "", ret);
		return ret;
	}
};

int main()
{
	return 0;
}