#include <iostream>
#include <list>
#include <memory>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

template<typename T>
class smart_ptr
{
public:
	smart_ptr(T* ptr = nullptr) : _ptr{ ptr } {}
	smart_ptr(const smart_ptr&) = delete;
	smart_ptr& operator = (const smart_ptr&) = delete;

	~smart_ptr() { if (_ptr) delete _ptr; }

	T& operator * () { return *_ptr; }
	T* operator & () { return  _ptr; }
	T* operator -> () { return  _ptr; }
	T* get() { return _ptr; }

private:
	T* _ptr{};
};

class ref_count
{
public:
	ref_count() {}
	ref_count(const ref_count&) = delete;
	ref_count& operator = (const ref_count&) = delete;

	size_t inc() { return ++_count; }
	size_t dec() { return --_count; }
	size_t count() { return _count; }

private:
	size_t _count{};
};

template<typename T>
class ref_smart_ptr
{
public:
	ref_smart_ptr(T* ptr) : _ptr{ ptr }
	{
		_ref = new ref_count;
		_ref->inc(); 
	}
	ref_smart_ptr(const ref_smart_ptr& other)
	{
		_ptr = other._ptr; 
		_ref = other._ref;
		_ref->inc();
	}
	ref_smart_ptr& operator = (const ref_smart_ptr& other)
	{
		if (this != &other)
		{
			if (_ref->dec() == 0)
			{
				delete _ptr;
				delete _ref;
			}

			_ptr = other._ptr;
			_ref = other._ref;
			_ref->inc();
		}

		return *this;
	}
	~ref_smart_ptr() 
	{ 
		if (_ref->dec() == 0)
		{
			std::cout << "destroyed: " << *_ptr << std::endl;
			delete _ptr;
			delete _ref;
		}
	}

	T& operator *  () { return *_ptr; }
	T* operator &  () { return  _ptr; }
	T* operator -> () { return  _ptr; }
	T* get() { return _ptr; }

	size_t use_count() { return _ref->count(); }

private:
	T* _ptr{};
	ref_count* _ref{};
};

struct Employee
{
	Employee(const std::string& name) : _name{ name } {}

	friend bool operator == (const std::unique_ptr<Employee>& employee, const std::string& name) { return employee->_name == name; }

	std::string _name;
};

int main()
{
	// pointer arithmetic
	int a[5] = { 1, 2, 3, 4, 5 };
	int* p = a;
	std::cout << a << std::endl;
	std::cout << a + 2 << std::endl;
	std::cout << p << std::endl;
	std::cout << ++p << std::endl;
	std::cout << --p << std::endl;

	// raw pointers
	int i = 5;
	int* p1 = nullptr;
	int* p2 = &i;
	int* p3 = new int[5];
	delete[] p3;
	int* p4 = p3;

	// smart pointers
	{
		smart_ptr<int> sp(new int{ 5 });
		smart_ptr<int> spc;
		// spc = sp; // error

		std::cout << *sp << std::endl;
		std::cout << &sp << std::endl;
	}

	// referencecounted smart pointer
	{
		ref_smart_ptr<int> rsp(new int{ 7 });
		std::cout << "rsp count: " << rsp.use_count() << std::endl;

		{
			ref_smart_ptr<int> rsp1(rsp);
			std::cout << "rsp1 count: " << rsp1.use_count() << std::endl;
		}
		std::cout << "rsp count: " << rsp.use_count() << std::endl;

		ref_smart_ptr<int> rsp2(new int{ 9 });
		std::cout << "rsp2 count: " << rsp2.use_count() << std::endl;
		rsp2 = rsp;
		std::cout << "rsp2 count: " << rsp2.use_count() << std::endl;
	}


	// unique pointer
	{
		//std::unique_ptr<int> up;
		//std::unique_ptr<int> up{ new int{ 5 } };
		std::unique_ptr<int> up{ std::make_unique<int>(5) };
		std::cout << up << std::endl;
		std::cout << *up << std::endl;
		if (up) { std::cout << "holds pointer" << std::endl; }

		std::unique_ptr<int> upc;
		//upc = uc;
		upc = std::move(up);
		std::cout << "upc: " << upc << std::endl;
		std::cout << "up: " << up << std::endl;
	}

	// container - smart pointer
	{
		//std::list<Employee*> employees;
		//employees.push_back(new Employee{ "Tim" });
		//employees.push_back(new Employee{ "Eric" });

		std::list<std::unique_ptr<Employee>> employees;
		employees.push_back(std::make_unique<Employee>("Tim"));
		employees.push_back(std::make_unique<Employee>("Eric"));
		employees.push_back(std::make_unique<Employee>("Lily"));
		employees.push_back(std::make_unique<Employee>("Eric"));
		//employees.push_back(std::unique_ptr<Employee>(new Employee("Lily")));
		
		for (std::unique_ptr<Employee>& e : employees)
		{
			std::cout << e->_name << std::endl;
		}

		for (auto iter = employees.begin(); iter != employees.end(); iter++)
		{
			std::cout << (*iter)->_name << std::endl;
		}

		//auto iter = std::find(employees.begin(), employees.end(), "Tim");
		//if (iter != employees.end())
		//{
		//	employees.erase(iter);
		//}

		//auto iter = employees.begin();
		//while (iter != employees.end())
		//{
		//	iter = std::find(iter, employees.end(), "Tim");
		//	if (iter != employees.end())
		//	{
		//		iter = employees.erase(iter);
		//	}
		//}

		for (auto iter = employees.begin(); iter != employees.end();)
		{
			iter = std::find(iter, employees.end(), "Eric");
			if (iter != employees.end())
			{
				iter = employees.erase(iter);
			}
		}
	}

	_CrtDumpMemoryLeaks();
}