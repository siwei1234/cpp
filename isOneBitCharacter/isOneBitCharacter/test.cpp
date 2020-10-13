#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int i = 0;
		for (; i < bits.size() - 1; i++)
		{
			if (bits[i] == 1)
				i++;
		}
		if (i == bits.size() - 1)
			return true;
		return false;
	}
};

int main()
{
	vector<int> bits = { 1, 0, 0 };
	cout << Solution().isOneBitCharacter(bits);
	return 0;
}