#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool isSubsequence(string s, string t) {
		int n = s.size(), m = t.size();
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			if (s[i] == t[j])
			{
				i++;
			}
			j++;
		}
		return i == n;
	}
};

int main()
{
	string s = "abc";
	string t = "ahbgdc";
	cout << Solution().isSubsequence(s, t) << endl;
	return 0;
}