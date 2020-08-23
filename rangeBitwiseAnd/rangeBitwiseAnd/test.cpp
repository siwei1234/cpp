#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int offset = 0;
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			++offset;
		}
		return n << offset;
	}
};

int main()
{
	cout << Solution().rangeBitwiseAnd(5, 10) << endl;
	return 0;
}