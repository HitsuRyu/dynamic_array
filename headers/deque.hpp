#ifndef DEQUE_HPP
#define DEQUE_HPP

# include <stdlib.h>
# include <stdio.h>

template <typename T>
class						DequeElement
{
	protected:
	T						element;
	DequeElement<T>			*next;
	DequeElement<T>			*prev;
	
	public:
	DequeElement()
	{
		element = 0;
		next = NULL;
		prev = NULL;
	};

	DequeElement(T _element)
	{
		element = _element;
		next = NULL;
		prev = NULL;
	};

	DequeElement(T _element, DequeElement* _prev, DequeElement* _next)
	{
		element = _element;
		next = _next;
		prev = _prev;
	};

	void					SetElement(T _element)
	{
		element = _element;
	};

	T						GetElement()
	{
		return (element);
	};

	void					SetNext(DequeElement* _next)
	{
		next = _next;
	};

	DequeElement			*GetNext()
	{
		return (next);
	};

	void					SetPrev(DequeElement* _prev)
	{
		prev = _prev;
	};

	DequeElement			*GetPrev()
	{
		return (prev);
	};

	T						*GetElement(int)
	{
		return(&element);
	};
};


template <typename T>
class						Deque
{
	protected:      
    DequeElement<T> 		*left;
    DequeElement<T>			*right;
    T 						buffer;
	
	public:
    Deque()
	{
		left = NULL;
		right = NULL;
		// buffer = 0; в с++ если объект не инициализирован явно - он автоматически инициализируется нулем или NULL 
	};

    Deque(Deque<T>	&_deque)
	{
		DequeElement<T>	*tmp;
		
		// buffer = 0; в с++ если объект не инициализирован явно - он автоматически инициализируется нулем или NULL 
		left = NULL;
		right = NULL;
		tmp = _deque.left;
		while (tmp != NULL)
		{
			AddRight(tmp->GetElement());
			tmp = tmp->GetNext();
		}
	};

    virtual T				*AddLeft(T element)
	{
		DequeElement<T> *tmp;
		tmp = new DequeElement<T>(element, NULL, left);

		if (tmp == NULL)
			return (NULL);
		if (IsEmpty() == 1)
		{
			left = tmp;
			right = tmp;
		}
		else
		{
			left->SetPrev(tmp);
			left = tmp;
		}
		buffer = element;
		return (&(buffer));
	};

    virtual T 				*AddRight(T element)
	{
		DequeElement<T> *tmp;
		tmp = new DequeElement<T>(element, right, NULL);

		if (tmp == NULL)
			return (NULL);
		if (IsEmpty() == 1)
		{
			left = tmp;
			right = tmp;
		}
		else
		{
			right->SetNext(tmp);
			right = tmp;
		}
		buffer = element;
		return (&(buffer));
	};

	T 						*RemoveLeft()
	{
		DequeElement<T> *tmp;

		if (IsEmpty() == 1)
			return (NULL);
		tmp = left;
		buffer = left->GetElement();
		if (tmp->GetNext() == NULL)
		{
			delete tmp;
			left = NULL;
			right = NULL;
		}
		else
		{
			left = left->GetNext();
			left->SetPrev(NULL);
			delete tmp;
		}
		return (&(buffer));
	};

    T 						*RemoveRight()
	{
		DequeElement<T> *tmp;

		if (IsEmpty() == 1)
			return (NULL);
		tmp = right;
		buffer = right->GetElement();
		if (tmp->GetPrev() == NULL)
		{
			delete tmp;
			left = NULL;
			right = NULL;
		}
		else
		{
			right = right->GetPrev();
			right->SetNext(NULL);
			delete tmp;
		}
		return (&(buffer));
	};

    T						GetElement()
	{
		return (buffer);
	};

	DequeElement<T> 		*GetLeft()
	{
    	return (left);
	};

	DequeElement<T> 		*GetRight()
	{
		return (right);
	};

	int						IsEmpty()
	{
		if ((left) && (right))
			return 0;
		return 1;
	};

    T						*operator--()
	{
    	return(RemoveLeft());
	};

    T						*operator--(int)
	{
		return(RemoveRight());
	};

    Deque			&operator=(Deque& _deque)
	{
		DequeElement<T> *tmp;

		while(left != NULL)
		{
			RemoveLeft();
		}
		tmp = _deque.left;
		while (tmp != NULL)
		{
			AddRight(tmp->GetElement());
			tmp = tmp->GetNext();
		}
		return (*this);
	};

    int						operator==(Deque& _deque)
	{
		DequeElement<T> *tmp1;
		DequeElement<T> *tmp2;

		tmp1 = left;
		tmp2 = _deque.GetLeft();
		if ((tmp1 == NULL) && (tmp2 != NULL))
			return (0);
		if ((tmp1 != NULL) && (tmp2 == NULL))
			return (0);
		if ((tmp1 == tmp2) && (tmp1 == NULL))
			return (1);
		while((tmp1->GetNext() != NULL) || (tmp2->GetNext() != NULL))
		{
			if (tmp1->GetElement() != tmp2->GetElement())
				return(0);
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		if (tmp1->GetElement() != tmp2->GetElement())
			return(0);
		if ((tmp1->GetNext() == NULL && tmp2->GetNext() != NULL) || (tmp1->GetNext() != NULL && tmp2->GetNext() == NULL))
			return (0);
		return (1);
	};
	
    ~Deque()
	{
		DequeElement<T> *tmp;

		if (IsEmpty() == 1)
			return ;
		else
		{
			while (IsEmpty() != 1)
				RemoveLeft();
		}
	};
};

template <typename T>
T							*operator+(Deque<T>	&deque, T element)
{
	return (deque.AddRight(element));
};

template <typename T>
T							*operator+(T element, Deque<T>	&deque)
{
	return (deque.AddLeft(element));
};

#endif
