#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
	int islandPerimeter(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j])
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int kx = i + dir[k][0];
						int ky = j + dir[k][1];
						if (kx < 0 || kx >= n || ky < 0 || ky >= m || !grid[kx][ky])
							cnt++;
					}
					ret += cnt;
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> grid = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
	cout << Solution().islandPerimeter(grid) << endl;
	return 0;
}