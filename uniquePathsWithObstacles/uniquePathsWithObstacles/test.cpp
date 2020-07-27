#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<int> ret(m);
		ret[0] = (obstacleGrid[0][0] == 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					ret[j] = 0;
					continue;
				}
				if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
				{
					ret[j] += ret[j - 1];
				}
			}
		}
		return ret.back();
	}
};

int main()
{
	vector<vector<int>> nums{ {0,0,0},{0,0,0},{0,0,0} };
	cout << Solution().uniquePathsWithObstacles(nums) << endl;
	return 0;
}