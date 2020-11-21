#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int i = 0;
		while (i < n) {
			int sumOfGas = 0, sumOfCost = 0;
			int cnt = 0;
			while (cnt < n) {
				int j = (i + cnt) % n;
				sumOfGas += gas[j];
				sumOfCost += cost[j];
				if (sumOfCost > sumOfGas) {
					break;
				}
				cnt++;
			}
			if (cnt == n) {
				return i;
			}
			else {
				i = i + cnt + 1;
			}
		}
		return -1;
	}
};


int main()
{
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << Solution().canCompleteCircuit(gas, cost) << endl;
	return 0;
}