#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool Ischar(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return true;
		return false;
	}
	string reverseOnlyLetters(string S) {
		int begin = 0;
		int end = S.size() - 1;
		while (begin < end)
		{
			while (begin < end && Ischar(S[begin]) == false)
				++begin;
			while (begin < end && Ischar(S[end]) == false)
				--end;
			swap(S[begin], S[end]);
			++begin;
			--end;
		}
		return S;
	}
};

int main()
{
	Solution s;
	string s1("a-bC-dEf-ghIj");
	cout << s.reverseOnlyLetters(s1) << endl;
}