#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	string sortString(string s) {
		vector<int> num(26, 0);
		for (auto& i : s)
			num[i - 'a']++;
		string ret;
		while (ret.size() < s.size())
		{
			for (int i = 0; i < 26; i++)
			{
				if (num[i])
				{
					ret += (i + 'a');
					num[i]--;
				}
			}
			for (int i = 25; i >= 0; i--)
			{
				if (num[i])
				{
					ret += (i + 'a');
					num[i]--;
				}
			}
		}
		return ret;
	}
};

int main()
{
	string s = "dashdajshdjashu";
	cout << Solution().sortString(s) << endl;
	return 0;
}