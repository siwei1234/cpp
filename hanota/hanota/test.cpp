#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
		int n = A.size();
		move(n, A, B, C);
	}
	void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
	{
		if (n == 1)
		{
			C.push_back(A.back());
			A.pop_back();
			return;
		}
		move(n - 1, A, C, B);
		C.push_back(A.back());
		A.pop_back();
		move(n - 1, B, A, C);
	}

	void _move(int n, char a, char b, char c)
	{
		if (n == 1)
		{
			cout << a << "->" << c << endl;
			return;
		}
		_move(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		_move(n - 1, b, a, c);
	}

};

int main()
{
	vector<int> A = { 2,1,0 };
	vector<int> B;
	vector<int> C;
	Solution().hanota(A, B, C);
	Solution()._move(3, 'A', 'B', 'C');
	return 0;
}