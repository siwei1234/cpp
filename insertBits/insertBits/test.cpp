#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
	int insertBits(int N, int M, int i, int j) {
		for (int k = i; k <= j; k++)
		{
			if (N & (1 << k))
			{
				N -= (1 << k);
			}
		}
		N += (M << i);
		return N;
	}
};

int main()
{
	cout << Solution().insertBits(50, 10, 2, 5) << endl;
	return 0;
}