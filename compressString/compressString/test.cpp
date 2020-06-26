#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		int i = 0;
		string ret;
		while (i < S.size())
		{
			ret += S[i];
			char tmp = S[i];
			int count = 0;
			while (S[i] == tmp)
			{
				count++;
				i++;
			}
			ret += to_string(count);
		}
		if (ret.size() < S.size())
			return ret;
		return S;
	}
};

int main()
{
	string s = "aabcccccaaa";
	cout << Solution().compressString(s) << endl;
	return 0;
}