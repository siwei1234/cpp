#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() == 0 && t.size() == 0)
			return true;
		if (s.size() != t.size())
			return false;

		for (int i = 0; i < s.size(); i++)
		{
			if (s.find(s[i]) != t.find(t[i]))
				return false;
		}
		return true;
	}
};

int main()
{
	string s = "egg";
	string t = "add";
	cout << Solution().isIsomorphic(s, t);
	return 0;
}