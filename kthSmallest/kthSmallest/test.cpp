#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> ret;
		for (auto i : matrix)
		{
			for (auto j : i)
			{
				ret.push_back(j);
			}
		}
		sort(ret.begin(), ret.end());
		return ret[k - 1];
	}
};

int main()
{
	vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
	cout << Solution().kthSmallest(matrix, 8) << endl;
	return 0;
}