#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int findTheLongestSubstring(string s) {
		int ret = 0;
		int status = 0;
		int len = s.size();
		vector<int> tmp(32, -1);
		tmp[0] = 0;
		for (int i = 0; i < len; i++)
		{
			if ('a' == s[i])
				status ^= 1;
			else if ('e' == s[i])
				status ^= 1 << 1;
			else if ('i' == s[i])
				status ^= 1 << 2;
			else if ('o' == s[i])
				status ^= 1 << 3;
			else if ('u' == s[i])
				status ^= 1 << 4;
			if (tmp[status] != -1)
				ret = max(ret, i + 1 - tmp[status]);
			else
				tmp[status] = i + 1;
		}
		return ret;
	}
};

int main()
{
	string s = "eleetmienicoworoep";
	cout << Solution().findTheLongestSubstring(s) << endl;
	return 0;
}