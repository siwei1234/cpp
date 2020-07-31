#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		int low = 1;
		int high = 2;
		while (low < high)
		{
			int total = (low + high) * (high - low + 1) / 2;
			if (sum == total)
			{
				vector<int> tmp;
				for (int i = low; i <= high; i++)
				{
					tmp.push_back(i);
				}
				ret.push_back(tmp);
				high++;
			}
			else if (sum > total)
				high++;
			else
				low++;
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> ret = Solution().FindContinuousSequence(100);
	for (auto& i : ret)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}