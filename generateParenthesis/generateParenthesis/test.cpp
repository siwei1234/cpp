#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		dfs("", 0, 0, n, ret);
		return ret;
	}

	void dfs(string tmp, int left, int right, int n, vector<string>& ret)
	{
		if (tmp.size() == 2 * n)
		{
			ret.push_back(tmp);
			return;
		}
		if (left < n)
			dfs(tmp + '(', left + 1, right, n, ret);
		if (right < left)
			dfs(tmp + ')', left, right + 1, n, ret);
	}
};

int main()
{
	vector<string> ret = Solution().generateParenthesis(3);
	
	for (auto& i : ret)
		cout << i << endl;

	return 0;
}