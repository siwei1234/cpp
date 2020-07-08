#pragma once

#include<iostream>
#include<map>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RETreeNode
{
	RETreeNode(pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
	RETreeNode<K, V>* _left;
	RETreeNode<K, V>* _right;
	RETreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;
};

template<class K, class V>
class RETree
{
	typedef RETreeNode<K, V> Node;
public:
	bool Insert(pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			Node* grandfther = parent->_parent;
			if (grandfther->_left == parent)
			{
				Node* uncle = grandfther->_right;
				if (uncle && uncle->_col == RED)
				{
					grandfther->_col = RED;
					parent->_col = uncle->_col = BLACK;

					parent = grandfther->_parent;
					cur = grandfther;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					RotateR(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
					break;
				}
			}
			else
			{
				Node* uncle = grandfther->_left;
				if (uncle && uncle->_col == RED)
				{
					grandfther->_col = RED;
					parent->_col = uncle->_col = BLACK;

					parent = grandfther->_parent;
					cur = grandfther;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						::swap(parent, cur);
					}
					RotateL(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
				cur = cur->_left;
			else if (cur->_kv.first < key)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node* _root = nullptr;
};