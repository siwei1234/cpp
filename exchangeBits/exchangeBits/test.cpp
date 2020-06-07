#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	int exchangeBits(int num) {
		int ret = 0;
		for (int i = 0; i < 30; i += 2)
		{
			int a = num & (1 << i);
			int b = num & (1 << (i + 1));
			ret |= (a << 1);
			ret |= (b >> 1);
		}
		return ret;
	}
};

int main()
{
	cout << Solution().exchangeBits(87) << endl;
	return 0;
}