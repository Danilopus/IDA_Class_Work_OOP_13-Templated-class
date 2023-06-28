#pragma once
#include <vector>
#include <string>
#include "Service functions.h"
#include <array>

//параметр int size
template <typename some_type_of_data, const int size_tp>
class MyClass
{
//private:
	//some_type_of_data* _data [size];
	some_type_of_data _data[size_tp];
	const size_t _size { size_tp };

public:

	MyClass(int A1,	double A2,	std::string A3) {}
	//MyClass(): _data(nullptr), _size(0) {}
	MyClass() {}

	size_t size() const	{ return _size; }

	some_type_of_data& operator [](size_t index)
	{
		return _data[index];
	}


	// tail trace - указание возвращаемого типа в конце (для удобства читаемости)
	// вывод типа ключевое слово auto
	auto at(size_t index) -> some_type_of_data&
	{
		return _data[index];
	}
	
	
	auto at(size_t index) const -> const some_type_of_data&
	{
		return _data[index];
	}

	/*some_type_of_data* begin() { return _data; }
	some_type_of_data* end() { return _data +_size; }*/

	//iterator begin() { return _data; }
	//iterator end() { return _data + _size; }

	
	class iterator 
	{
		some_type_of_data* _data_iterator;
		
	public:
		//iterator() = default; указание компилятору создать конструктор  по умолчанию
		iterator() = delete;
		iterator(some_type_of_data* data) : _data_iterator(data) {}

		iterator& operator++()
		{
			_data_iterator++;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			_data_iterator++;
			return tmp;
		}

		iterator& operator--()
		{
			_data_iterator--;
			return *this;
		}

		iterator& operator--(int)
		{
			iterator tmp(*this);
			_data_iterator--;
			return tmp;
		}

		some_type_of_data& operator*()
		{
			return *_data_iterator;
		}
		bool operator != (const iterator& obj)
		{
			return (this->_data_iterator != obj._data_iterator);
		}
		bool operator == (const iterator& obj)
		{
			return this->_data_iterator == obj._data_iterator;
		}

	};

	iterator begin() { return _data; }
	iterator end() { return (_data + _size); }

	

};



