#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;



int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

class Solution {
public:

	void dfs(vector<vector<char>>& grid, int row, int col, int i, int j, vector<vector<int>>& books)
	{
		books[i][j] = 1;
		for (int k = 0; k < 4; k++)
		{
			int ni = i + dir[k][0];
			int nj = j + dir[k][1];
			if (ni < 0 || ni >= row || nj < 0 || nj >= col)
				continue;
			if (grid[ni][nj] == '1' && books[ni][nj] == 0)
				dfs(grid, row, col, ni, nj, books);
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int ret = 0;
		int row = grid.size();
		int col = grid[0].size();

		vector<vector<int>> books(row, vector<int>(col, 0));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1' && books[i][j] == 0)
				{
					ret++;
					dfs(grid, row, col, i, j, books);
				}
			}
		}
		return ret;
	}
};


int main()
{
	vector<vector<char>> c = { {'1', '1', '1', '1', '0'},{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'} };
	cout << Solution().numIslands(c) << endl;
	return 0;
}