#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;



int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

class Solution {
public:

	void dfs(vector<vector<char>>& board, int row, int col, int i, int j)
	{
		board[i][j] = '*';
		for (int k = 0; k < 4; k++)
		{
			int newi = i + dir[k][0];
			int newj = j + dir[k][1];
			if (newi < 0 || newi >= row || newj < 0 || newj >= col)
				continue;
			if (board[newi][newj] == 'O')
				dfs(board, row, col, newi, newj);
		}
	}
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; i++)
		{
			if (board[i][0] == 'O')
				dfs(board, row, col, i, 0);
			if (board[i][col - 1] == 'O')
				dfs(board, row, col, i, col - 1);
		}

		for (int i = 0; i < col; i++)
		{
			if (board[0][i] == 'O')
				dfs(board, row, col, 0, i);
			if (board[row - 1][i] == 'O')
				dfs(board, row, col, row - 1, i);
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == '*')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
	}
};


int main()
{
	vector<vector<char>> c = { { 'X','X', 'X', 'X', },{'X', 'O', 'O', 'X'},{'X', 'X', 'O', 'X'},{'X', 'O', 'X', 'X'} };
	Solution().solve(c);
	return 0;
}