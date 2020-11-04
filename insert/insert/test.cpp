#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int left = newInterval[0];
		int right = newInterval[1];
		bool flag = false;
		vector<vector<int>> ret;
		for (auto& i : intervals)
		{
			if (i[0] > right)
			{
				if (!flag)
				{
					ret.push_back({ left, right });
					flag = true;
				}
				ret.push_back(i);
			}
			else if (i[1] < left)
			{
				ret.push_back(i);
			}
			else
			{
				left = min(left, i[0]);
				right = max(right, i[1]);
			}
		}
		if (!flag)
			ret.push_back({ left, right });
		return ret;
	}
};

int main()
{
	vector<vector<int>> insert = { {1, 3},{6, 9} };
	vector<int> newi = { 2,5 };
	vector<vector<int>> ret = Solution().insert(insert, newi);
	for (auto& i : ret)
		cout << i[0] << "-" << i[1] << endl;
	return 0;
}