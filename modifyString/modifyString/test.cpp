#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string modifyString(string s) {
		char prev = ' ';
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '?')
			{
				char tmp = 'a';
				while (tmp == prev || tmp == s[i + 1])
					tmp++;
				s[i] = tmp;
			}
			prev = s[i];
		}
		return s;
	}
};

int main()
{
	string s = "?zs";
	cout << Solution().modifyString(s) << endl;
	return 0;
}