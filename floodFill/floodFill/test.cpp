#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;



int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

class Solution {
public:
	void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book, int sr, int sc, int oldColor, int newColor)
	{
		image[sr][sc] = newColor;
		book[sr][sc] = 1;
		for (int i = 0; i < 4; i++)
		{
			int newsr = sr + dir[i][0];
			int newsc = sc + dir[i][1];
			if (newsr >= row || newsr < 0 || newsc >= col || newsc < 0)
				continue;
			if (image[newsr][newsc] == oldColor && book[newsr][newsc] == 0)
				dfs(image, row, col, book, newsr, newsc, oldColor, newColor);
		}
	}


	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;
		int row = image.size();
		int col = image[0].size();
		vector<vector<int>> book(row, vector<int>(col, 0));
		int oldColor = image[sr][sc];

		dfs(image, row, col, book, sr, sc, oldColor, newColor);
		return image;
	}
};

int main()
{
	vector<vector<int>> image = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
	
	vector<vector<int>> ret = Solution().floodFill(image, 1, 1, 2);
	for (auto& i : ret)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}