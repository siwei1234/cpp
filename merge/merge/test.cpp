#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		for (int i = 0; i < n; i++)
		{
			int end = m - 1 + i;
			int tmp = B[i];
			while (end >= 0)
			{
				if (tmp < A[end])
				{
					A[end + 1] = A[end];
					--end;
				}
				else
					break;
			}
			A[end + 1] = tmp;
		}
	}
};

int main()
{
	vector<int> A = { 1,2,3,0,0,0 };
	vector<int> B = { 2,5,6 };
	Solution().merge(A, 3, B, 3);

	for (auto& i : A)
		cout << i << " ";
	cout << endl;
	return 0;
}