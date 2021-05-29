// ЛАБОРАТОРНАЯ РАБОТА №6 ДАВЛЕТШИН РОМАН МАРАТОВИЧ М6О-208Б-19
#ifndef LIST_HPP
#define LIST_HPP

#include"deque.hpp"

template <typename T>
class 							List : public Deque<T>
{
	protected:
	DequeElement<T>				*current;

	virtual T					*AddLeft(T element)
	{
		T	*_buffer;
		_buffer = Deque<T>::AddLeft(element);
		GoToLeft();
		return (_buffer);
	};

	virtual T					*AddRight(T element)
	{
		T	*_buffer;
		_buffer = Deque<T>::AddRight(element);
		GoToRight();
		return (_buffer);
	};

	public:
	List() : Deque<T>(), current(NULL) {} ;
	List(List<T> &plist) : Deque<T>(plist)
	{
		DequeElement<T> *tmp1;
		DequeElement<T> *tmp2;

		tmp1 = plist.GetLeft();
		tmp2 = this->GetLeft();
		while (tmp1 != plist.current)
		{
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		current = tmp2;
	};

	DequeElement<T>			*GoToLeft()
	{
  		current = Deque<T>::left;
  		return (current);
	};

	DequeElement<T>			*GoToRight()
	{
  		current = Deque<T>::right;
 		 return (current);
	};

	DequeElement<T>			*GoToNext()
	{
		if (current == Deque<T>::right)
			return (NULL);
		else if (current == NULL)
			return (NULL);
		else 
		{
			current = current -> GetNext();
			return (current);
		}
	};
	
	DequeElement<T>			*GoToPrev()
	{
		if (current == Deque<T>::left)
			return (NULL);
		else if (current == NULL)
			return (NULL);
		else
		{ 
			current = current -> GetPrev();
			return (current);
		}
	};

	T							*Fetch()
	{
		if (current == NULL)
			return NULL;
		else
		{
			Deque<T>::buffer = current -> GetElement();
			return &(Deque<T>::buffer);
		}
	};

	T							*Store(T elem)
	{
		if (current != NULL)
		{
			current -> SetElement(elem);
			Deque<T>::buffer = current -> GetElement();
			return &(Deque<T>::buffer);
		} 
		else
		{
			return (NULL);
		}
	};

	T							*operator--()
	{
		T	*tmp_t;
		tmp_t = Deque<T>::operator--();
		current = this->GetLeft();
		return tmp_t;
	};

	T							*operator--(int)
	{
		T	*tmp_t;
		tmp_t = Deque<T>::operator--(1);
		current = this->GetRight();
		return tmp_t;
	};

	List<T>					&operator=(List<T>	&plist)
	{
		Deque<T>::operator=(plist);

		DequeElement<T> *tmp1;
		DequeElement<T> *tmp2;
		tmp1 = plist.GetLeft();
		tmp2 = this->GetLeft();
		while (tmp1 != plist.current)
		{
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		current = tmp2;
		return (*this);
	};

	int							operator==(List<T>	&plist)
	{
		DequeElement<T> *tmp1;
		DequeElement<T> *tmp2;
		
		if (this->IsEmpty() == 1 && plist.IsEmpty() == 1)
				return (1);
		if (Deque<T>::operator==(plist) == 0)
			return (0);
		else
		{
			tmp1 = plist.GetLeft();
			tmp2 = this->GetLeft();
			while (tmp1 != NULL && tmp2 != NULL && tmp1 != plist.current)
			{
				tmp1 = tmp1->GetNext();
				tmp2 = tmp2->GetNext();
			}
			if (tmp1->GetElement() != tmp2->GetElement())
				return (0);
		}
		return (1);
	};

	virtual	~List() {};
};

#endif