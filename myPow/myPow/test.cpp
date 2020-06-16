#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1 || n == 0)
			return 1;
		long sum = n;
		double ret = 1;
		if (sum < 0)
		{
			sum = -sum;
			x = 1 / x;
		}
		while (sum)
		{
			if (sum & 1)
			{
				ret *= x;
			}
			x *= x;
			sum >>= 1;
		}
		return ret;
	}
};

int main()
{
	cout << Solution().myPow(1.1, 10) << endl;
	return 0;
}