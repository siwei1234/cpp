#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int strToInt(string str) {
		int index = 0;
		long long ret = 0;
		while (str[index] == ' ')
			index++;
		int flag = 1;
		if (str[index] == '-')
			flag = -1;
		if (str[index] == '-' || str[index] == '+')
			index++;
		for (int i = index; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
				break;
			ret = ret * 10 + (str[i] - '0');
			if (ret >= INT_MAX && flag == 1)
				return INT_MAX;
			if (ret > INT_MAX && flag == -1)
				return INT_MIN;
		}
		return flag * ret;
	}
};

int main()
{
	string s = "-548541shduasgd";
	cout << Solution().strToInt(s) << endl;
	return 0;
}