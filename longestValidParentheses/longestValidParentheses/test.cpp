#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
	int longestValidParentheses(string s) {
		int ret = 0;
		stack<int> st;
		st.push(-1);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				st.pop();
				if (st.empty())
				{
					st.push(i);
				}
				else
				{
					ret = max(ret, i - st.top());
				}
			}
		}
		return ret;
	}
};


int main()
{
	string s = ")()())";
	cout << Solution().longestValidParentheses(s) << endl;
	return 0;
}