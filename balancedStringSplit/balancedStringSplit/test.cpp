#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;




class Solution {
public:
	int balancedStringSplit(string s) {
		int ret = 0;
		int balance = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
				balance++;
			if (s[i] == 'L')
				balance--;
			if (balance == 0)
				ret++;
		}
		return ret;
	}
};

int main()
{
	string s = "RLRRLLRLRL";
	cout << Solution().balancedStringSplit(s) << endl;
	return 0;
}