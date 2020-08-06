#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;



class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:

	int dfs(unordered_map<int, Employee*>& info, int id)
	{
		int curImpo = info[id]->importance;
		for (auto& e : info[id]->subordinates)
		{
			curImpo += dfs(info, e);
		}
		return curImpo;
	}
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;
		unordered_map<int, Employee*> info;
		for (auto& e : employees)
		{
			info[e->id] = e;
		}
		return dfs(info, id);
	}
};

int main()
{
	return 0;
}