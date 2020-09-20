#pragma once

#include<mutex>
using namespace std;
namespace ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~auto_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		unique_ptr(unique_ptr<T>& ap) = delete;

		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;


		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
	private:
		T* _ptr;
	};
	

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			add_ref_count();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;
				add_ref_count();
			}
			return *this;
		}

		void add_ref_count()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void release()
		{
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				if (_ptr)
				{
					delete _ptr;
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();
			if (flag)
			{
				delete _pmtx;
				_pmtx = nullptr;
			}
		}

		int use_count()
		{
			return *_pcount;
		}

		T* get_ptr() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~shared_ptr()
		{
			release();
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr() = default;

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get_ptr())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get_ptr();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}