#pragma once
#include<iostream>
using namespace std;

namespace List
{
	// List的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			:_val(val)
			,_prev(nullptr)
			,_next(nullptr)
		{}
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
	};

	//List的迭代器类
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		Node* _node;
		ListIterator(Node* node = nullptr)
			:_node(node)
		{}
		ListIterator(const Self& l)
		{
			_node = l._node;
		}
		Ref& operator*()
		{
			return _node->_val;
		}
		Ptr operator->()
		{
			return &_node->_val;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self ret = *this;
			_node = _node->_next;
			return ret;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self& operator--(int)
		{
			Self ret = *this;
			_node = _node->_prev;
			return ret;
		}
		bool operator!=(const Self& l)
		{
			return _node != l._node;
		}
		bool operator==(const Self& l)
		{
			return _node == l._node;
		}
	};

	//list类
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		///////////////////////////////////////////////////////////////
		// List的构造
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(int n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (n)
			{
				Node* newnode = new Node;
				newnode->_val = value;
				newnode->_next = _head;
				newnode->_prev = _head->_prev;
				_head->_prev->_next = newnode;
				_head->_prev = newnode;
				n--;
			}
		}
		list(const list<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (auto e : l)
				push_back(e);
		}
		list<T>& operator=(list<T> l)
		{
			swap(l);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t ret = 0;
			while (cur != _head)
			{
				ret++;
				cur = cur->_next;
			}
			return ret;
		}
		bool empty()const
		{
			return _head->_next == _head;
		}

		////////////////////////////////////////////////////////////
		// List Access
		T& front()
		{
			return _head->_next->_val;
		}
		const T& front()const
		{
			return _head->_next->_val;
		}
		T& back()
		{
			return _head->_prev->_val;
		}
		const T& back()const
		{
			return _head->_prev->_val;
		}

		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val)
		{ 
			insert(begin(), val); 
		}
		void pop_back() 
		{
			erase(--end()); 
		}
		void push_front(const T& val) 
		{ 
			insert(begin(), val); 
		}
		void pop_front() 
		{ 
			erase(begin()); 
		}
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val = T())
		{
			Node* cur = pos._node;
			Node* newnode = new Node;
			newnode->_val = val;
			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			newnode->_prev->_next = newnode;
			cur->_prev = newnode;
			return pos;
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			cur->_prev->_next = next;
			next->_prev = cur->_prev;
			return iterator(next);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		void swap(list<T>& l)
		{
			::swap(_head, l._head);
		}
	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt(4, 100);
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct Date
	{
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

	void test_list2()
	{
		int* p1 = new int;
		*p1;
		Date* p2 = new Date;
		*p2;
		p2->_year;

		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " ";
			cout << it->_year << "-" << it->_month << "-" << it->_day << endl; // 更喜欢这么用
			cout << (*it)._year << "-" << (*it)._month << "-" << (*it)._day << endl;

			++it;
		}
		cout << endl;
	}

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		print_list(lt);

		lt.pop_back();
		lt.pop_front();
		print_list(lt);

		lt.clear();
		lt.push_back(10);
	}

	void test_list4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);

		list<int> lt2(lt1);
		print_list(lt2);

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);
		lt3.push_back(40);
		lt1 = lt3;
		print_list(lt1);
	}
};