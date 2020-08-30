#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> q;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}
		static int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
		int ret = 0;
		while (!q.empty())
		{
			int n = q.size();
			int flag = 0;
			while (n--)
			{
				auto curpos = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int ni = curpos.first + dir[i][0];
					int nj = curpos.second + dir[i][1];
					if (ni < 0 || ni >= row || nj < 0 || nj >= col || grid[ni][nj] != 1)
						continue;
					flag = 1;
					grid[ni][nj] = 2;
					q.push(make_pair(ni, nj));
				}
			}

			if (flag)
				ret++;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> grid = { {2, 1, 1},{1, 1, 0},{0, 1, 1} };
	cout << Solution().orangesRotting(grid) << endl;
	return 0;
}