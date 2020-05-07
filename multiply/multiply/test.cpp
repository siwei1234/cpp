#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int end1 = num1.size();
		int end2 = num2.size();
		int* tmp = new int[end1 + end2];
		memset(tmp, 0, sizeof(int)*(end1 + end2));
		for (int i = 0; i < end1; i++)
		{
			for (int j = 0; j < end2; j++)
			{
				int val = (num1[i] - '0') * (num2[j] - '0');
				val += tmp[i + j];
				tmp[i + j] = val % 10;
				tmp[i + j + 1] += val / 10;
			}
		}
		int index = end1 + end2 - 1;
		while (index >= 0 && tmp[index] == 0)
			index--;
		string ret = "";
		while (index >= 0)
		{
			ret += tmp[index] + '0';
			index--;
		}
		return ret;
	}
};

int main()
{
	cout << Solution().multiply("123", "456") << endl;
}