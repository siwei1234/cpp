#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		int last[26];
		for (int i = 0; i < S.size(); i++)
		{
			last[S[i] - 'a'] = i;
		}
		vector<int> ret;
		int start = 0, end = 0;
		for (int i = 0; i < S.size(); i++)
		{
			end = max(end, last[S[i] - 'a']);
			if (end == i)
			{
				ret.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return ret;
	}
};

int main()
{
	string s = "ababcbacadefegdehijhklij";
	vector<int> ret = Solution().partitionLabels(s);
	for (auto& i : ret)
		cout << i << " ";
	cout << endl;
	return 0;
}