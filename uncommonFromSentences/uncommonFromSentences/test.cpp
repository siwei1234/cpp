#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		string str = A + " " + B;
		unordered_map<string, int> tmp;
		int i = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ')
			{
				tmp[str.substr(i, j - i)]++;
				i = j + 1;
			}
		}
		tmp[str.substr(i, str.size() - i)]++;
		vector<string> ret;
		for (auto it : tmp)
		{
			if (it.second == 1)
				ret.push_back(it.first);
		}
		return ret;
	}
};

int main()
{
	string A = "this apple is sweet";
	string B = "this apple is sour";
	vector<string> ret = Solution().uncommonFromSentences(A, B);
	for (auto e : ret)
		cout << e << endl;
	return 0;
}