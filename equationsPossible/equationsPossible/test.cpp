#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int parent[26];
	bool equationsPossible(vector<string>& equations) {
		if (equations.empty())
			return true;
		for (int i = 0; i < 26; i++)
			parent[i] = i;
		for (int i = 0; i < equations.size(); i++)
		{
			if (equations[i][1] == '=')
			{
				int val1 = find(equations[i][0] - 'a');
				int val2 = find(equations[i][3] - 'a');
				if (val1 != val2)
					parent[val1] = val2;
			}
		}
		for (int i = 0; i < equations.size(); i++)
		{
			if (equations[i][1] == '!')
			{
				int val1 = find(equations[i][0] - 'a');
				int val2 = find(equations[i][3] - 'a');
				if (val1 == val2)
					return false;
			}
		}
		return true;
	}
	int find(int i)
	{
		while (i != parent[i])
		{
			parent[i] = parent[parent[i]];
			i = parent[i];
		}
		return i;
	}
};

int main()
{
	vector<string> nums{ "c==c","b==d","x!=z" };
	cout << Solution().equationsPossible(nums) << endl;
	return 0;
}