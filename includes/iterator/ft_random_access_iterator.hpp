/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:10:56 by pierina           #+#    #+#             */
/*   Updated: 2022/12/22 00:06:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_RANDOM_ACCESS_ITERATOR_
#define _FT_RANDOM_ACCESS_ITERATOR_

#include "ft_iterator.hpp"
#include "ft_iterator_traits.hpp"

namespace ft
{
	template<typename T>
    class random_access_iterator
    {
    protected:
		//atributtes 
		pointer _ptr;

	/*********Random_access_iterator typedefs*********/

    public:
				
		typedef T value_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;
		typedef value_type* pointer;
		typedef value_type& reference;

		//constructors

		random_access_iterator() : _ptr(NULL){}
		random_access_iterator(T *ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &it) : _ptr(it._ptr) {}

		//destructor
		
		~random_access_iterator() {}
		
		//conversion to another type, when it is instantiated with const
		operator random_access_iterator<T const>() const
		{
			return (random_access_iterator<const T>(_ptr));
		}

		//assignment operator
		random_access_iterator &operator=(const random_access_iterator &it)
		{
			if (*this != &it)
				_ptr = it._ptr;
			return (*this);
		}

		//access to the pointer to the iterator

		random_access_iterator base() const
		{
			return (_ptr);
		}

		/**
		**************************************************
		 * random_access_iterator: dereference
		**************************************************
		*/

		reference operator*() const
		{
			return (*_ptr);
		}

		pointer operator->() const
		{
			return &(operator *());
		}
		
		//offset dereference operator
		reference operator[](size_t n) const
		{
			return (*(_ptr + n));
		}


		/**
		**************************************************
		 * random_access_iterator: incrementation 
		 * (if in a deferenceable state)
		 * result is deferenceable or a past the end iterator
		 * two iterators that compare equal, keep comparing equal
		 * after both being increased
		**************************************************
		**/

		//pre ++a
		random_access_iterator& operator++()
		{
			++_ptr;
			return (*this);
		}
		//post a++
		random_access_iterator operator++(int)
		{
			random_access_iterator tmp = _ptr;
			++_ptr;
			return (tmp);
		}

		/**
		**************************************************
		 * random_access_iterator: decrementation
		 * (if a deferenceable iterator value precedes it)
		**************************************************
		**/

		//pre --a
		random_access_iterator& operator--()
		{
			--_ptr;
			return (*this);
		}
		//post a--
		random_access_iterator operator--(int)
		{
			random_access_iterator tmp = _ptr;
			--_ptr;
			return (*this);
		}

		/**
		**************************************************
		 * random_access_iterator: arithmetic operators
		 * between an iterator and an integer value
		 * or substracting an iterator from another (this will be done outside)
		**************************************************
		**/

		random_access_iterator operator+(difference_type n) const
		{
			return (_ptr + n);
		}

		random_access_iterator operator-(difference_type n) const
		{
			return (_ptr - n);
		}
		
		
		/**
		**************************************************
		 * random_access_iterator: compound assignment
		 * operators
		**************************************************
		**/
		random_access_iterator operator+=(difference_type n) const
		{
			return (_ptr += n);
		}
		random_access_iterator operator-=(difference_type n) const
		{
			return (_ptr -= n);
		}
	};
	
		/**
		**************************************************
		 * random_access_iterator: comparing for equivalence
		**************************************************
		**/

		
		==
		!=
		/**
		**************************************************
		 * random_access_iterator: comparison with inequality
		 * operators
		**************************************************
		**/

		a < b
		a > b
		a <= b
		a >= b

		a - b
}

#endif