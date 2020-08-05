#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:


	void dfs(vector<int>& candidates, vector<vector<int>>& solutions, vector<int>& solution, int cur, int prev, int target)
	{
		if (cur >= target)
		{
			if (cur == target)
				solutions.push_back(solution);
			return;
		}
		for (int i = prev; i < candidates.size(); i++)
		{
			if (candidates[i] > target)
				continue;
			solution.push_back(candidates[i]);
			dfs(candidates, solutions, solution, cur + candidates[i], i, target);
			solution.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> solutions;
		vector<int> solution;
		if (candidates.empty())
			return solutions;
		int cur = 0;
		dfs(candidates, solutions, solution, cur, 0, target);
		return solutions;
	}
};

int main()
{
	vector<int> cnad = { 2,3,6,7 };
	vector<vector<int>> ret = Solution().combinationSum(cnad, 7);

	for (auto& i : ret)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}