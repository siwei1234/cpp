#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> left(n);
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && ratings[i] > ratings[i - 1])
				left[i] = left[i - 1] + 1;
			else
				left[i] = 1;
		}
		int right = 0, ret = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (i < n - 1 && ratings[i] > ratings[i + 1])
				right++;
			else
				right = 1;
			ret += max(left[i], right);
		}
		return ret;
	}
};

int main()
{
	vector<int> r = { 1,2,2 };
	cout << Solution().candy(r) << endl;
	return 0;
}