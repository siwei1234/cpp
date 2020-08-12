#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> masterMind(string solution, string guess) {
		unordered_map<char, int> cs;
		int ret = 0, sum = 0;
		for (int i = 0; i < 4; i++)
			cs[guess[i]]++;
		for (int i = 0; i < 4; i++)
		{
			if (guess[i] == solution[i])
				ret++;
			if (cs[solution[i]])
			{
				sum++;
				cs[solution[i]]--;
			}
		}
		return { ret, sum - ret };
	}
};

int main()
{
	string s = "RGBY";
	string p = "GGRR";
	vector<int> ret = Solution().masterMind(s, p);
	cout << ret[0] << " " << ret[1] << endl;
	return 0;
}