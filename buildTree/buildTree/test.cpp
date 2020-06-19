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

	TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posi, int inbegin, int inend)
	{
		if (inbegin > inend)
			return NULL;
		TreeNode* root = new TreeNode(postorder[posi]);
		int rooti = inbegin;
		while (rooti < inend)
		{
			if (inorder[rooti] == postorder[posi])
				break;
			rooti++;
		}
		if (rooti + 1 <= inend)
			root->right = _buildTree(inorder, postorder, --posi, rooti + 1, inend);
		if (inbegin <= rooti - 1)
			root->left = _buildTree(inorder, postorder, --posi, inbegin, rooti - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int posi = postorder.size() - 1;
		int inbegin = 0;
		int inend = inorder.size() - 1;
		return _buildTree(inorder, postorder, posi, inbegin, inend);
	}
};


int main()
{
	return 0;
}