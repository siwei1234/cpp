#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int, int> rank;
		for (int i = 0; i < arr2.size(); i++)
			rank[arr2[i]] = i;
		sort(arr1.begin(), arr1.end(), [&](int x, int y)
		{
			if (rank.count(x))
				return rank.count(y) ? rank[x] < rank[y] : true;
			else
				return rank.count(y) ? false : x < y;
		});
		return arr1;
	}
};

int main()
{
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };
	Solution().relativeSortArray(arr1, arr2);
	for (auto& i : arr1)
		cout << i << " ";
	cout << endl;
	return 0;
}