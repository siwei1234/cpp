#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return NULL;
		unordered_map<Node*, Node*> mp;
		Node* cur = head;
		while (cur)
		{
			mp[cur] = new Node(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur)
		{
			if (cur->next)
			{
				mp[cur]->next = mp[cur->next];
			}
			if (cur->random)
			{
				mp[cur]->random = mp[cur->random];
			}
			cur = cur->next;
		}
		return mp[head];
	}
};

int main()
{
	return 0;
}