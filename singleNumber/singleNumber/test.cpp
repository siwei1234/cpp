#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int tmp[32] = { 0 };
		for (auto e : nums)
		{
			for (size_t i = 0; i < 32; i++)
			{
				if (e & (1 << i))
					tmp[i]++;
			}
		}
		size_t ret = 0;
		for (size_t i = 0; i < 32; i++)
		{
			if ((tmp[i] % 3) != 0)
				ret += pow(2, i);
		}
		return (int)ret;
	}
};

int main()
{
	int a[] = { 0,1,0,1,0,1,99 };
	vector<int> v(a, a + 7);
	cout << Solution().singleNumber(v) << endl;
	return 0;
}