#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int reverseBits(int num) {
		int ret = 0;
		int left = 0, right = 0;
		while (num)
		{
			if (num & 1)
			{
				left++;
			}
			else
			{
				ret = max(ret, left + right + 1);
				right = left;
				left = 0;
			}
			num >>= 1;
		}
		ret = max(ret, left + right + 1);
		return ret;
	}
};

int main()
{
	cout << Solution().reverseBits(41546854) << endl;
	return 0;
}