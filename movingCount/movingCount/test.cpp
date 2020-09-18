#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 移动的次数
	 * @param m int整型
	 * @param n int整型
	 * @param k int整型
	 * @return int整型
	 */
	int addSum(int i, int j)
	{
		int ret = 0;
		while (i || j)
		{
			ret += i % 10;
			ret += j % 10;
			i /= 10;
			j /= 10;
		}
		return ret;
	}
	void dfs(vector<vector<bool>>& flag, int& ret, int i, int j, int k)
	{
		int iaj = addSum(i, j);
		if (iaj > k)
			return;
		if (i >= 0 && i < flag.size() && j >= 0 && j < flag[i].size() && flag[i][j] == false)
		{
			flag[i][j] = true;
			ret++;
			dfs(flag, ret, i - 1, j, k);
			dfs(flag, ret, i, j - 1, k);
			dfs(flag, ret, i + 1, j, k);
			dfs(flag, ret, i, j + 1, k);
		}
	}

	int movingCount(int m, int n, int k) {
		// write code here
		int ret = 0;
		vector<vector<bool>> flag(m, vector<bool>(n, false));
		dfs(flag, ret, 0, 0, k);
		return ret;
	}
};


int main()
{
	int ret = Solution().movingCount(2, 3, 1);
	cout << ret << endl;
	return 0;
}