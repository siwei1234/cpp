#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int m = A.size(), n = A[0].size();
		int ret = m * (1 << (n - 1));
		for (int j = 1; j < n; j++)
		{
			int ones = 0;
			for (int i = 0; i < m; i++)
			{
				if (A[i][0] == 1)
					ones += A[i][j];
				else
					ones += (1 - A[i][j]);
			}
			int k = max(ones, m - ones);
			ret += k * (1 << (n - j - 1));
		}
		return ret;
	}
};


int main()	
{
	vector<vector<int>> A = { {0, 0, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} };
	cout << Solution().matrixScore(A) << endl;
	return 0;
}