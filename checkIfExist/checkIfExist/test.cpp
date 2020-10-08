#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		int cnt[4001] = { 0 };
		int* cur = cnt + 2000;
		for (auto i : arr)
			++cur[i];
		for (auto i : arr)
		{
			if (i != 0 && cur[2 * i] >= 1)
				return true;
			else if (i == 0 && cur[2 * i] >= 2)
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> v = { 10,2,5,3 };
	cout << Solution().checkIfExist(v);
	return 0;
}