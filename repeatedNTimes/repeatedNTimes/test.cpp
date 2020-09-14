#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		map<int, int> ret;
		for (auto e : A)
		{
			ret[e]++;
		}
		for (auto e : ret)
		{
			if (e.second >= A.size() / 2)
			{
				return e.first;
			}
		}
		return 0;
	}
};


int main()
{
	vector<int> A{ 1,1,1,2,2 };
	cout << Solution().repeatedNTimes(A) << endl;
	return 0;
}