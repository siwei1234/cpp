#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* phead = head;
		ListNode* cur = head->next;
		while (cur != nullptr)
		{
			if (phead->val <= cur->val)
				phead = phead->next;
			else
			{
				ListNode* prev = newhead;
				while (prev->next->val <= cur->val)
					prev = prev->next;
				phead->next = cur->next;
				cur->next = prev->next;
				prev->next = cur;
			}
			cur = phead->next;
		}
		return newhead->next;
	}
};
int main()
{
	return 0;
}