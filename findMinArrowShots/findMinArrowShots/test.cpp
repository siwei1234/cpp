#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty())
			return 0;
		sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v)
		{
			return u[1] < v[1];
		});
		int pos = points[0][1];
		int ret = 1;
		for (auto& i : points)
		{
			if (i[0] > pos)
			{
				pos = i[1];
				ret++;
			}
		}
		return ret;
	}
};


int main()
{
	vector<vector<int>> points = { {10, 16},{2, 8},{1, 6},{7, 12} };
	cout << Solution().findMinArrowShots(points) << endl;
	return 0;
}