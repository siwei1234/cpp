#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (int i = 0; i < numRows; i++)
		{
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][i] = 1;
		}
		for (int i = 1; i < numRows; i++)
		{
			for (int j = 1; j < vv[i].size() - 1; j++)
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};
int main()
{
	vector<vector<int>> vv= Solution().generate(10);
	for (auto e : vv)
	{
		for (auto f : e)
		{
			cout << f;
		}
		cout << endl;
	}
	return 0;
}