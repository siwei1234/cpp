#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<stack>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	int kthLargest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->right;
			}
			TreeNode* top = st.top();
			st.pop();
			if (--k == 0)
				return top->val;
			cur = top->left;
		}
		return root->val;
	}
};

int main()
{
	return 0;
}