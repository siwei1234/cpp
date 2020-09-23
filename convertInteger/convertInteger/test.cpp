#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
class Solution {
public:
	int convertInteger(int A, int B) {
		unsigned int a = (unsigned int)A;
		unsigned int b = (unsigned int)B;
		unsigned int x = a ^ b;
		int ret = 0;
		while (x != 0)
		{
			x &= (x - 1);
			ret++;
		}
		return ret;
	}
};

int main()
{
	cout << Solution().convertInteger(100, 50) << endl;
	return 0;
}