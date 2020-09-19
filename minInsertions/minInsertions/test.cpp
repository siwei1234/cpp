#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * @param s string字符串
	 * @return int整型
	 */
	int minInsertions(string s) {
		// write code here
		int ret = 0;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else
			{
				if (st.empty())
				{
					if (s[i + 1] == ')')
					{
						ret++;
						i++;
					}
					else
					{
						ret += 2;
					}
				}
				else
				{
					if (s[i + 1] == ')')
						i++;
					else
						ret++;
				}
				st.pop();
			}
		}

		while (!st.empty())
		{
			st.pop();
			ret += 2;
		}

		return ret;
	}
};

int main()
{
	string s = "())";
	cout << Solution().minInsertions(s) << endl;
	return 0;
}