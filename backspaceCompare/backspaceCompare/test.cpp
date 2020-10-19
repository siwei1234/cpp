#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s, t;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '#')
			{
				if (s.empty())
					continue;
				s.pop_back();
			}
			else
			{
				s += S[i];
			}
		}
		for (int i = 0; i < T.size(); i++)
		{
			if (T[i] == '#')
			{
				if (t.empty())
					continue;
				t.pop_back();
			}
			else
			{
				t += T[i];
			}
		}
		if (s == t)
			return true;
		return false;
	}
};

int main()
{
	string S = "a##c";
	string T = "#a#c";
	Solution().backspaceCompare(S, T);
	return 0;
}