#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {
		vector<int> bit(10001, 0);
		for (int i = 0; i < 10001; i++)
			bit[i] = bit[i >> 1] + (i & 1);
		sort(arr.begin(), arr.end(), [&](int x, int y)
		{
			if (bit[x] < bit[y])
				return true;
			if (bit[x] > bit[y])
				return false;
			return x < y;
		});
		return arr;
	}
};


int main()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8 };
	vector<int> ret = Solution().sortByBits(v);
	for (auto& i : ret)
		cout << i << " ";
	cout << endl;
	return 0;
}