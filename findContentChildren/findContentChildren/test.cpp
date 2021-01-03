#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int ret = 0;
		for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++)
		{
			while (j < s.size() && g[i] > s[j])
				j++;
			if (j < s.size())
				ret++;
		}
		return ret;
	}
};


int main()
{
	vector<int> g = { 1,2,3 };
	vector<int> s = { 1,1 };
	cout << Solution().findContentChildren(g, s) << endl;
	return 0;
}