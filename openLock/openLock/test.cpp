#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;


class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> dead(deadends.begin(), deadends.end());
		if (dead.count("0000"))
			return -1;
		queue<string> q;
		q.push("0000");

		unordered_set<string> book;
		book.insert("0000");

		int ret = 0;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				string curstr = q.front();
				q.pop();
				if (curstr == target)
					return ret;
				for (int j = 0; j < 4; j++)
				{
					string newstr1 = curstr;
					string newstr2 = curstr;
					newstr1[j] = newstr1[j] == '9' ? '0' : newstr1[j] + 1;
					newstr2[j] = newstr2[j] == '0' ? '9' : newstr2[j] - 1;
					if (!dead.count(newstr1) && !book.count(newstr1))
					{
						q.push(newstr1);
						book.insert(newstr1);
					}
					if (!dead.count(newstr2) && !book.count(newstr2))
					{
						q.push(newstr2);
						book.insert(newstr2);
					}
				}
			}
			ret++;
		}
		return -1;
	}
};

int main()
{
	vector<string> vs = { "0201","0101","0102","1212","2002" };
	cout << Solution().openLock(vs, "0202") << endl;
	return 0;
}