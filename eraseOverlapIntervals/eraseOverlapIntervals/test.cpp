#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

	struct cmp
	{
		bool operator()(const vector<int>& a, const vector<int>& b)
		{
			return a[0] < b[0];
		}
	};
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return 0;

		sort(intervals.begin(), intervals.end(), cmp());

		int k = 0, ret = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[k][1] > intervals[i][0])
			{
				if (intervals[k][1] > intervals[i][1])
					k = i;
				ret++;
			}
			else
			{
				k = i;
			}
		}
		return ret;
	}
};


int main()
{
	vector<vector<int>> intervals = { {1, 2},{2, 3},{3, 4},{1, 3}, {3,4} };
	cout << Solution().eraseOverlapIntervals(intervals) << endl;
	return 0;
}