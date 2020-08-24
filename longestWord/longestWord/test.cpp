#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> setwords(words.begin(), words.end());
		string ret;
		for (auto word : words)
		{
			auto tmp = setwords;
			tmp.erase(word);
			if (isCombinated(word, tmp))
			{
				if (word.size() > ret.size())
					ret = word;
				if (word.size() == ret.size())
					ret = min(word, ret);
			}
		}
		return ret;
	}

	bool isCombinated(string word, unordered_set<string>& setwords)
	{
		if (word.size() == 0)
			return true;
		for (int i = 1; i <= word.size(); i++)
		{
			if (setwords.count(word.substr(0, i)) && isCombinated(word.substr(i), setwords))
				return true;
		}
		return false;
	}
};

int main()
{
	vector<string> word = { "cat","banana","dog","nana","walk","walker","dogwalker" };

	cout << Solution().longestWord(word) << endl;
}