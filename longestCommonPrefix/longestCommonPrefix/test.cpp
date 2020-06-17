#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string ret = strs[0];
		for (int i = 0; i < strs.size(); i++)
		{
			ret = _longestCommonPrefix(ret, strs[i]);
			if (ret.empty())
				break;
		}
		return ret;
	}
	string _longestCommonPrefix(string& str1, string& str2)
	{
		int minlen = ::min(str1.size(), str2.size());
		int index = 0;
		while (index < minlen && str1[index] == str2[index])
		{
			++index;
		}
		return str1.substr(0, index);
	}
};

int main()
{
	vector<string> str{ "flower","flow","flight" };
	string ret = Solution().longestCommonPrefix(str);
	cout << ret;
	return 0;
}