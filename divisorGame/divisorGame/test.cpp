#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool divisorGame(int N) {
		vector<int> f(N + 5, false);

		f[1] = false;
		f[2] = true;
		for (int i = 3; i <= N; ++i) {
			for (int j = 1; j < i; ++j) {
				if (i % j == 0 && !f[i - j]) {
					f[i] = true;
					break;
				}
			}
		}

		return f[N];
	}
};

int main()
{
	cout << Solution().divisorGame(10) << endl;
	return 0;
}