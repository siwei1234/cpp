#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b)->bool
		{
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
		});
		return { points.begin(), points.begin() + K };
	}
};

int main()
{
	vector<vector<int>> points = { {1, 3},{-2, 2} };
	vector<vector<int>> ret = Solution().kClosest(points, 1);
	for (auto& i : ret)
		cout << i[0]  << " "<< i[1] << endl;
	return 0;
}