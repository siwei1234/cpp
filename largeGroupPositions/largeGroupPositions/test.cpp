#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		int num = 1;
		int n = s.size();
		vector<vector<int>> ret;
		for (int i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] != s[i + 1])
			{
				if (num >= 3)
					ret.push_back({ i - num + 1, i });
				num = 1;
			}
			else
				num++;
		}
		return ret;
	}
};


int main()
{
	string s = "abbxxxxzzy";
	vector<vector<int>> ret = Solution().largeGroupPositions(s);
	for (auto& i : ret)
		cout << i[0] << "," << i[1] << endl;
	return 0;
}