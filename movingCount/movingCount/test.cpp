#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 * �ƶ��Ĵ���
	 * @param m int����
	 * @param n int����
	 * @param k int����
	 * @return int����
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