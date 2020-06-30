#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> m;
		int ret = 0, r = 0, l = 0;
		while (r < s.size())
		{
			if (m.find(s[r]) != m.end())
			{
				l = max(l, m[s[r]] + 1);
			}
			m[s[r++]] = r;
			ret = max(r - l, ret);
		}
		return ret;
	}
};

int main()
{
	string s = "abcabcbb";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
	return 0;
}