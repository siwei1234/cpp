#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> freq;
		for (char ch : tasks) {
			++freq[ch];
		}

		// ����ִ�д���
		int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
			return u.second < v.second;
		})->second;
		// �������ִ�д�������������
		int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
			return acc + (u.second == maxExec);
		});

		return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
	}
};

int main()
{
	vector<char> tasks = { 'A','A','A','B','B','B' };
	cout << Solution().leastInterval(tasks, 2) << endl;
	return 0;
}