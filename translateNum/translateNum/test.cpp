#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int backtrack(string& str, int pos)
	{
		int len = str.size();
		if (pos == len)
			return 1;
		if (str[pos] == '0' || str.substr(pos, 2) > "25" || pos == len - 1)
			return backtrack(str, pos + 1);
		return backtrack(str, pos + 1) + backtrack(str, pos + 2);
	}
	int translateNum(int num) {
		string str = to_string(num);
		return backtrack(str, 0);
	}
};

int main()
{
	int num = 11111;
	cout << Solution().translateNum(num) << endl;
	return 0;
}