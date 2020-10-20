#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL)
			return;
		vector<ListNode*> v;
		ListNode* cur = head;
		while (cur != NULL)
		{
			v.emplace_back(cur);
			cur = cur->next;
		}
		int i = 0, j = v.size() - 1;
		while (i < j)
		{
			v[i]->next = v[j];
			i++;
			if (i == j)
				break;
			v[j]->next = v[i];
			j--;
		}
		v[i]->next = NULL;
	}
};

int main()
{
	return 0;
}