#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string getDigits(string& s, size_t& index)
	{
		string ret;
		while (isdigit(s[index]))
			ret += s[index++];
		return ret;
	}
	string getString(vector<string>& v)
	{
		string ret;
		for (auto e : v)
			ret += e;
		return ret;
	}
	string decodeString(string s) {
		vector<string> vs;
		size_t index = 0;
		while (index < s.size())
		{
			char cur = s[index];
			if (isdigit(cur))
			{
				string digits = getDigits(s, index);
				vs.push_back(digits);
			}
			else if (isalpha(cur) || cur == '[')
			{
				vs.push_back(string(1, s[index++]));
			}
			else
			{
				++index;
				vector<string> sub;
				while (vs.back() != "[")
				{
					sub.push_back(vs.back());
					vs.pop_back();
				}
				reverse(sub.begin(), sub.end());
				vs.pop_back();
				int val = stoi(vs.back());
				vs.pop_back();
				string t, o = getString(sub);
				while (val)
				{
					--val;
					t += o;
				}
				vs.push_back(t);
			}
		}
		return getString(vs);
	}
};


int main()
{
	string s = "3[a2[c]]";
	cout << Solution().decodeString(s) << endl;
	return 0;
}