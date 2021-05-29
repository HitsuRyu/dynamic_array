// ЛАБОРАТОРНАЯ РАБОТА №6 ДАВЛЕТШИН РОМАН МАРАТОВИЧ М6О-208Б-19
#ifndef ARRAY_HPP
#define ARRAY_HPP

# include "list.hpp"

template <typename T>
class 				Array : public List<T>
{
	protected:
	int				low;
	int				high;
	virtual T		*AddLeft(T element)
	{
		if (low>high)
			high = low;
		else
			low--;
		return (List<T>::AddLeft(element));
	};
    virtual T		*AddRight(T element)
	{
    	high++;
		return (List<T>::AddRight(element));
	};

	public:
	Array() : List<T>(), low(1), high(0) {};
	Array(int lb) : List<T>(), low(lb), high(lb - 1) {};
	Array(Array<T>	&b) : List<T>(b), low(b.low), high(b.high) {};
	Array(int lb, int cnt, T val) : List<T>(), low(lb), high(lb - 1)
	{
		int i;

		i = 0;
		while (i <= cnt - 1)
		{
			*this + val;
			i++;
		}
	};

	int				Low()
	{
		return (low);
	};

	int				High()
	{
		return (high);
	};

	int				Size()
	{
		int size;
		Array<T> tmp(*this);
		
		size = 0;
		if (tmp.GoToLeft())
		{
			size = 1;
			while (tmp.GoToNext())
				size++;
		}
		return (size);
	};

	Array<T>		&operator=(Array	&_array)
	{
		List<T>::operator=(_array);
		low = _array.Low();
		high = _array.High();
		return *this;
	};

	T				operator--()
	{
		T *tmp_t;

		if (this->IsEmpty() == 1)
			return (0);
		tmp_t = List<T>::operator--();
		if (this->IsEmpty() == 1)
			high = low - 1;
		else
			low++;
		return (*tmp_t);
	};

	T				operator--(int)
	{
		T *tmp_t;

		if (this->IsEmpty() == 1)
			return (0);
		tmp_t = List<T>::operator--(1);
		if (this->IsEmpty())
			high = low - 1;
		else
			high--;
		return (*tmp_t);
	};

	T				&operator[](int index)
	{
		int i;

		i = low;
		this->GoToLeft();
		while(i != index)
		{
			this->GoToNext();
			i++;
		}
		return *List<T>::current->GetElement(i);
	};
	
	virtual ~Array() {};
};

#endif
