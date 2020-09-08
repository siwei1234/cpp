#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
class Solution {
public:
	void _treeToDoublyList(Node* root, Node*& prev)
	{
		if (root == NULL)
			return;
		_treeToDoublyList(root->left, prev);
		root->left = prev;
		if (prev)
			prev->right = root;
		prev = root;
		_treeToDoublyList(root->right, prev);
	}
	Node* treeToDoublyList(Node* root) {
		if (root == NULL)
			return NULL;
		Node* prev = NULL;
		_treeToDoublyList(root, prev);
		// Node* head = new Node;
		Node* cur = root;
		while (cur->left)
			cur = cur->left;
		//head->right = cur;
		while (prev->right)
			prev = prev->right;
		prev->right = cur;
		cur->left = prev;
		//return head->right;
		return cur;
	}
};
int main()
{
	return 0;
}