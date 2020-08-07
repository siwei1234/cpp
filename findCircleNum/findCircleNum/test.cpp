#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class UnionFindSet
{
public:
	UnionFindSet(int n)
	{
		_v.resize(n, -1);
	}
	int FindRoot(int x)
	{
		while (_v[x] >= 0)
			x = _v[x];
		return x;
	}

	bool Union(int x, int y)
	{
		int root1 = FindRoot(x);
		int root2 = FindRoot(y);
		if (root1 == root2)
			return false;
		_v[root1] += _v[root2];
		_v[root2] = root1;
		return true;
	}

	size_t Size()
	{
		size_t n = 0;
		for (auto& i : _v)
		{
			if (i < 0)
				++n;
		}
		return n;
	}
private:
	vector<int> _v;
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		UnionFindSet us(M.size());
		for (int i = 0; i < M.size(); ++i)
		{
			for (int j = 0; j < M[i].size(); ++j)
			{
				if (M[i][j] == 1)
					us.Union(i, j);
			}
		}
		return us.Size();
	}
};

int main()
{
	vector<vector<int>> M = { {1,1,0},{1,1,0},{0,0,1} };
	cout << Solution().findCircleNum(M) << endl;
	return 0;
}