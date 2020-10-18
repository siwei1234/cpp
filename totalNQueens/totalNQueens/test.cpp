#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	void dfs(vector<pair<int, int>>& solution, int& ret, int row, int n)
	{
		if (row == n)
		{
			ret++;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (isvalid(solution, row, i))
			{
				solution.push_back(make_pair(row, i));
				dfs(solution, ret, row + 1, n);
				solution.pop_back();
			}
		}
	}

	bool isvalid(vector<pair<int, int>>& solution, int row, int col)
	{
		for (auto& i : solution)
		{
			if (col == i.second || i.first + i.second == row + col || i.first - i.second == row - col)
				return false;
		}
		return true;
	}

	int totalNQueens(int n) {
		vector<pair<int, int>> solution;
		int ret = 0;
		dfs(solution, ret, 0, n);
		return ret;
	}
};


int main()
{
	cout << Solution().totalNQueens(4) << endl;
	return 0;
}