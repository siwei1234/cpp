#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	bool _exist(vector<vector<char>>& board, vector<vector<int>> tmp, int i, int j, string& word, int index)
	{
		tmp[i][j] = 1;
		if (index == word.size())
			return true;
		index++;
		for (auto xy : dir)
		{
			int x = xy[0] + i;
			int y = xy[1] + j;
			if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || tmp[x][y] || board[x][y] != word[index - 1])
				continue;
			else
			{
				if (_exist(board, tmp, x, y, word, index))
					return true;
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>> tmp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					if (_exist(board, tmp, i, j, word, 1))
						return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<char>> nums = { {'a'} };
	string s = "ab";
	cout << Solution().exist(nums, s) << endl;
	return 0;
}