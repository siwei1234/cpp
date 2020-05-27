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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* cur = head->next;
		ListNode* tail = head->next->next;
		while (tail != cur)
		{
			if (tail == NULL || tail->next == NULL)
				return NULL;
			cur = cur->next;
			tail = tail->next->next;
		}
		cur = head;
		while (cur != tail)
		{
			cur = cur->next;
			tail = tail->next;
		}
		return cur;
	}
};

int main()
{
	return 0;
}