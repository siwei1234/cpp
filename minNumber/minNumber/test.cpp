#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		auto compare = [](string sa, string sb) {return sa + sb < sb + sa; };
		vector<string> tmp;
		for (auto e : nums) {
			tmp.push_back(to_string(e));
		}
		sort(tmp.begin(), tmp.end(), compare);
		string ret;
		for (string s : tmp) ret += s;
		return ret;
	}
};

int main()
{
	vector<int> nums{ 5,30,3,7 };
	cout << Solution().minNumber(nums) << endl;
	return 0;
}