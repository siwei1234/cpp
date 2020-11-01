#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr, *tail = nullptr;
		int next = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + next;
			if (!head)
				head = tail = new ListNode(sum % 10);
			else
			{
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			next = sum / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (next > 0)
			tail->next = new ListNode(next);
		return head;
	}
};

int main()
{
	return 0;
}