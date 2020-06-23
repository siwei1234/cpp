#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	string tree2str(TreeNode* t) {
		string ret;
		if (t == NULL)
			return ret;
		ret += to_string(t->val);
		if (t->left != NULL)
		{
			ret += '(';
			ret += tree2str(t->left);
			ret += ')';
		}
		else if (t->right != NULL)
		{
			ret += "()";
		}
		if (t->right != NULL)
		{
			ret += '(';
			ret += tree2str(t->right);
			ret += ')';
		}
		return ret;
	}
};

int main()
{
	return 0;
}