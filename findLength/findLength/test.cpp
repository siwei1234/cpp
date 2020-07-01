#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int _findLength(vector<int>& A, vector<int>& B, int i, int j, int len)
	{
		int ret = 0, tmp = 0;
		for (int k = 0; k < len; k++)
		{
			if (A[i + k] == B[j + k])
				tmp++;
			else
				tmp = 0;
			ret = max(ret, tmp);
		}
		return ret;
	}
	int findLength(vector<int>& A, vector<int>& B) {
		int n = A.size();
		int m = B.size();
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			int len = min(m, n - i);
			int tmp = _findLength(A, B, i, 0, len);
			ret = max(ret, tmp);
		}
		for (int i = 0; i < m; i++)
		{
			int len = min(n, m - i);
			int tmp = _findLength(A, B, 0, i, len);
			ret = max(ret, tmp);
		}
		return ret;
	}
};

int main()
{
	vector<int> A{ 0,0,0,0,1 };
	vector<int> B{ 1,0,0,0,0 };
	cout << Solution().findLength(A, B) << endl;
	return 0;
}