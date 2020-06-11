#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int len = T.size();
		vector<int> ret(len, 0);
		stack<int> st;
		for (int i = 0; i < len; i++)
		{
			while (!st.empty() && T[i] > T[st.top()])
			{
				int tmp = st.top();
				st.pop();
				ret[tmp] = i - tmp;
			}
			st.push(i);
		}
		return ret;
	}
};

int main()
{
	vector<int> nums{ 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> ret = Solution().dailyTemperatures(nums);
	for (auto e : ret)
	{
		cout << e;
	}
	return 0;
}