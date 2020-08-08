#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> worddict(wordList.begin(), wordList.end());
		unordered_set<string> visit;
		visit.insert(beginWord);
		queue<string> q;
		q.push(beginWord);
		int ret = 1;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				string curword = q.front();
				q.pop();
				for (int i = 0; i < curword.size(); i++)
				{
					string newword = curword;
					for (auto ch = 'a'; ch <= 'z'; ch++)
					{
						newword[i] = ch;
						if (!worddict.count(newword) || visit.count(newword))
							continue;
						if (newword == endWord)
							return ret + 1;
						q.push(newword);
						visit.insert(newword);
					}
				}
			}
			ret++;
		}
		return 0;
	}
};


int main()
{
	vector<string> word = { "hot","dot","dog","lot","log","cog" };
	cout << Solution().ladderLength("hit", "cog", word) << endl;
	return 0;
}