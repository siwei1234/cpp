#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		vector<int> table(26, 0);
		for (auto& i : s)
			table[i - 'a']++;
		for (auto&i : t)
		{
			table[i - 'a']--;
			if (table[i - 'a'] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << Solution().isAnagram(s, t) << endl;
	return 0;
}