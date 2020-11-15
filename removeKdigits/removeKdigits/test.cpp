#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> st;
		for (auto& i : num)
		{
			while (st.size() > 0 && st.back() > i && k)
			{
				st.pop_back();
				k -= 1;
			}
			st.push_back(i);
		}
		while (k > 0)
		{
			st.pop_back();
			k--;
		}
		string ret = "";
		bool iszero = true;
		for (auto& i : st)
		{
			if (iszero && i == '0')
				continue;
			iszero = false;
			ret += i;
		}
		return ret == "" ? "0" : ret;
	}
};

int main()
{
	string s = "1432219";
	string ret = Solution().removeKdigits(s, 3);
	cout << ret << endl;
	return 0;
}