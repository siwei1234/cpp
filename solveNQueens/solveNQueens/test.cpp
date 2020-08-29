#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:

	void dfs(vector<vector<pair<int, int>>>& solutions, vector<pair<int, int>>& solution, int currow, int n)
	{
		if (currow == n)
		{
			solutions.push_back(solution);
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (isvalid(solution, currow, i))
			{
				solution.push_back(make_pair(currow, i));
				dfs(solutions, solution, currow + 1, n);
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

	vector<vector<string>> trans(vector<vector<pair<int, int>>>& solutions, int n)
	{
		vector<vector<string>> ret;
		for (auto& i : solutions)
		{
			vector<string> tmp(n, string(n, '.'));
			for (auto& j : i)
			{
				tmp[j.first][j.second] = 'Q';
			}
			ret.push_back(tmp);
		}
		return ret;
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<pair<int, int>>> solutions;
		vector<pair<int, int>> solution;
		dfs(solutions, solution, 0, n);
		return trans(solutions, n);
	}
};



int main()
{
	vector<vector<string>> ret = Solution().solveNQueens(4);
	for (auto& i : ret)
	{
		for (auto& j : i)
			cout << j;
		cout << endl;
	}
	return 0;
}