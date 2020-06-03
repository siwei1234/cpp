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
	bool istrue(TreeNode* A, TreeNode* B)
	{
		if (B == NULL)
			return true;
		if (A == NULL)
			return false;
		if (A->val != B->val)
			return false;
		return istrue(A->left, B->left) && istrue(A->right, B->right);
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		return istrue(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};


int main()
{
	return 0;
}