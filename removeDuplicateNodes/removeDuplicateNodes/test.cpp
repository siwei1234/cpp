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
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tail = head->next;
		ListNode* prev = head;
		while (tail)
		{
			bool flag = true;
			ListNode* cur = head;
			while (cur != tail)
			{
				if (cur->val == tail->val)
				{
					flag = false;
					prev->next = tail->next;
					break;
				}
				cur = cur->next;
			}
			if (flag)
				prev = tail;
			tail = tail->next;
		}
		return head;
	}
};


int main()
{
	return 0;
}