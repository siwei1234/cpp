#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 * @param s string�ַ���
	 * @return int����
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