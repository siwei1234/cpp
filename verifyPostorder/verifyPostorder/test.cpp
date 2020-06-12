#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		bool ret = true;
		ret = istrue(postorder, 0, postorder.size() - 1);
		return ret;
	}
	bool istrue(vector<int>& postorder, int left, int right)
	{
		if (postorder.empty() || left > right)
			return true;
		int root = postorder[right];
		int i = left;
		while (i < right && postorder[i] <= root)
		{
			i++;
		}
		for (int j = i; j < right; j++)
		{
			if (postorder[j] < root)
				return false;
		}
		bool lefttrue = true;
		if (i > left)
		{
			lefttrue = istrue(postorder, left, i - 1);
		}
		bool righttrue = true;
		if (i < right - 1)
		{
			righttrue = istrue(postorder, i, right - 1);
		}
		return lefttrue && righttrue;
	}
};

int main()
{
	vector<int> nums{ 1,2,5,10,6,9,4,3 };
	cout << Solution().verifyPostorder(nums) << endl;
	return 0;
}