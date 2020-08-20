#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;


class Solution {
public:

	void dfs(string& tiles, string cur, vector<int>& used, unordered_set<string>& total)
	{
		if (!cur.empty())
			total.insert(cur);
		for (int i = 0; i < tiles.size(); i++)
		{
			if (used[i])
				continue;
			used[i] = 1;
			dfs(tiles, cur + tiles[i], used, total);
			used[i] = 0;
		}
	}

	int numTilePossibilities(string tiles) {
		if (tiles.empty())
			return 0;
		unordered_set<string> total;
		vector<int> used(tiles.size(), 0);
		dfs(tiles, "", used, total);
		return total.size();
	}
};


int main()
{
	string s = "AAB";
	cout << Solution().numTilePossibilities(s) << endl;
	return 0;
}