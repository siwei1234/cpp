#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> ret;
		int i = A.size();
		while (--i >= 0 || K > 0)
		{
			if (i >= 0)
				K += A[i];
			ret.push_back(K % 10);
			K /= 10;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	vector<int> A = { 5,1,2,4,0,5 };
	vector<int> ret = Solution().addToArrayForm(A, 98);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i];
	cout << endl;
	return 0;
}