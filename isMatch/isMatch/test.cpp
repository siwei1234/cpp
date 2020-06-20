#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool _isMatch(const char* s, const char* p)
	{
		if (!*p) return !*s;
		if (*(p + 1) != '*')
		{
			if (*s == *p || (*p == '.' && *s != '\0'))
			{
				return _isMatch(s + 1, p + 1);
			}
			else
				return false;
		}
		else
		{
			if (*s == *p || (*p == '.' && *s != '\0'))
			{
				return _isMatch(s, p + 2) || _isMatch(s + 1, p);
			}
			else
			{
				return _isMatch(s, p + 2);
			}
		}
	}
	bool isMatch(string s, string p) {
		return _isMatch(s.c_str(), p.c_str());
	}
};


int main()
{
	string s = "aab";
	string p = "c*a*b";
	cout << Solution().isMatch(s, p) << endl;
	return 0;
}