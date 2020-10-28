#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> m;
		for (int i = 0; i < arr.size(); i++)
			m[arr[i]]++;
		unordered_set<int> s;
		for (auto i : m)
		{
			s.insert(i.second);
		}
		return m.size() == s.size();
	}
};


int main()
{
	vector<int> arr = { -3,0,1,-3,1,1,1,-3,10,0 };
	cout << Solution().uniqueOccurrences(arr) << endl;
	return 0;
}