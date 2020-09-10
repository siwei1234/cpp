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
	TreeNode* dfs(vector<int>& nums, int L, int R)
	{
		if (L > R)
			return nullptr;
		int mid = (L + R) >> 1;
		auto* root = new TreeNode(nums[mid]);
		root->left = dfs(nums, L, mid - 1);
		root->right = dfs(nums, mid + 1, R);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return dfs(nums, 0, nums.size() - 1);
	}
};

int main()
{
	return 0;
}