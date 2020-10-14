#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void rotateA(string& A)
	{
		char tmp = A[0];
		for (int i = 1; i < A.size(); i++)
		{
			A[i - 1] = A[i];
		}
		A[A.size() - 1] = tmp;
	}
	bool rotateString(string A, string B) {
		if (A.size() != B.size())
			return false;
		if (A.empty() && B.empty())
			return true;
		for (int i = 0; i < A.size(); i++)
		{
			if (A == B)
				return true;
			rotateA(A);
		}
		return false;
	}
};

int main()
{
	string A = "abcde";
	string B = "cdeab";
	cout << Solution().rotateString(A, B) << endl;
	return 0;
}