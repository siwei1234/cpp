#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		vector<int> dp(T + 1, INT_MAX - 1);
		dp[0] = 0;
		for (int i = 1; i <= T; i++)
		{
			for (auto& it : clips)
			{
				if (it[0] < i && i <= it[1])
					dp[i] = min(dp[i], dp[it[0]] + 1);
			}
		}
		if (dp[T] == INT_MAX - 1)
			return -1;
		return dp[T];
	}
};


int main()
{
	vector<vector<int>> clips = { {0, 2},{4, 6},{8, 10},{1, 9}, {1, 5}, { 5, 9 } };
	cout << Solution().videoStitching(clips, 10) << endl;
	return 0;
}