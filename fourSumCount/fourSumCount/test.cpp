#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> countAB;
		for (auto& u : A)
		{
			for (auto& v : B)
				++countAB[u + v];
		}
		int ret = 0;
		for (auto& u : C)
		{
			for (auto& v : D)
			{
				if (countAB.count(-u - v))
					ret += countAB[-u - v];
			}
		}
		return ret;
	}
};


int main()
{
	vector<int> A = { 1,2 };
	vector<int> B = { -2,-1 };
	vector<int> C = { -1,2 };
	vector<int> D = { 0,2 };
	cout << Solution().fourSumCount(A, B, C, D) << endl;
	return 0;
}