#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	char findTheDifference(string s, string t) {
		int ret = 0;
		for (auto& ch : t)
		{
			ret += ch;
		}
		for (auto& ch : s)
		{
			ret -= ch;
		}
		return ret;
	}
};


int main()
{
	string s = "abcd";
	string t = "abced";
	cout << Solution().findTheDifference(s, t) << endl;
	return 0;
}