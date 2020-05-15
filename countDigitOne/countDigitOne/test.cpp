#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Solution {
public:
	int countDigitOne(int n) {
		int ret = 0;
		long i = 1;
		while (i <= n)
		{
			int high = n / (i * 10);
			int cur = (n / i) % 10;
			int low = n - (n / i) * i;
			if (cur == 0)
				ret += high * i;
			else if (cur == 1)
				ret += high * i + low + 1;
			else
				ret += high * i + i;
			i *= 10;
		}
		return ret;
	}
};

int main()
{
	cout << Solution().countDigitOne(5555) << endl;
	return 0;
}