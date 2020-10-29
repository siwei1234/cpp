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
	int _sumNumbers(TreeNode* root, int sum)
	{
		if (root == NULL)
			return 0;
		sum = sum * 10 + root->val;
		if (root->left == NULL && root->right == NULL)
			return sum;
		else
			return _sumNumbers(root->left, sum) + _sumNumbers(root->right, sum);
	}
	int sumNumbers(TreeNode* root) {
		return _sumNumbers(root, 0);
	}
};


int main()
{
	return 0;
}