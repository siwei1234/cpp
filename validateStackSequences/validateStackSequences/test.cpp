#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;
		int pushi = 0;
		int popi = 0;
		while (pushi < popped.size())
		{
			st.push(pushed[pushi++]);
			while (!st.empty() && st.top() == popped[popi])
			{
				st.pop();
				popi++;
			}
		}
		return st.empty();
	}
};


int main()
{
	vector<int> v1{ 1,2,3,4 };
	vector<int> v2{ 1,2,4,3 };
	cout << Solution().validateStackSequences(v1, v2) << endl;
	return 0;
}