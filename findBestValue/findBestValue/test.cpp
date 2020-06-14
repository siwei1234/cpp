#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		if (arr.empty())
			return 0;
		sort(arr.begin(), arr.end());
		int sum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			int x = (target - sum) / (arr.size() - i);
			if (arr[i] > x)
			{
				double t = ((double)(target - sum)) / (arr.size() - i);
				if (t - x > 0.5)
					return x + 1;
				else
					return x;
			}
			sum += arr[i];
		}
		return arr.back();
	}
};

int main()
{
	vector<int> arr{ 3,4,5,6,7 };
	cout << Solution().findBestValue(arr, 25) << endl;
	return 0;
}