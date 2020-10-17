#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> count;
		for (auto c : s)
			++count[c];
		int ret = 0;
		for (auto c : count)
		{
			int t = c.second;
			ret += (t / 2) * 2;
			if (t % 2 == 1 && ret % 2 == 0)
				++ret;
		}
		return ret;
	}
};

int main()
{
	cout << Solution().longestPalindrome("abccccdd") << endl;
	return 0;
}