/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:10:56 by pierina           #+#    #+#             */
/*   Updated: 2022/12/31 13:50:15 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_RANDOM_ACCESS_ITERATOR_
#define _FT_RANDOM_ACCESS_ITERATOR_

#include "ft_iterator.hpp"
#include "ft_iterator_traits.hpp"
#include "../utils/nullptr.hpp"
#include <iostream>

namespace ft
{
	template<typename T>
    class random_access_iterator : ft::iterator<random_access_iterator_tag, T>
    {

	/*********Random_access_iterator typedefs*********/

    public:

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
		typedef	typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;

		//constructors

		random_access_iterator(void) : _ptr(nullptr_t){}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &it) : _ptr(it._ptr) {}

		//destructor
		
		virtual ~random_access_iterator() {}
		
		//conversion to another type, when it is instantiated with const
		operator random_access_iterator<const T>() const
		{
			return (random_access_iterator<const T>(_ptr));
		}

		//assignment operator
		random_access_iterator &operator=(const random_access_iterator &it)
		{
			if (*this != it)
				_ptr = it._ptr;
			return (*this);
		}

		//access to the pointer to the iterator

		pointer base() const
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
			return (tmp);
		}

		/**
		**************************************************
		 * random_access_iterator: arithmetic operators
		 * between an iterator and an integer value
		 * or substracting an iterator from another (this will be done outside)
		**************************************************
		**/

		//a+n
		random_access_iterator operator+(difference_type n) const
		{
			return (_ptr + n);
		}
		//a-n
		random_access_iterator operator-(difference_type n) const
		{
			return (_ptr - n);
		}
		
		
		/**
		**************************************************\
		 * random_access_iterator: compound assignment
		 * operators
		**************************************************
		**/
		random_access_iterator operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}
		random_access_iterator operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		protected:
			pointer _ptr;
			//atributtes 
	};
	
		/**
		**************************************************
		 * random_access_iterator: comparing for equivalence
		**************************************************
		**/

		template<typename T>
		bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template<typename Iter1, typename Iter2>
		bool operator==(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template<typename T>
		bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template<typename Iter1, typename Iter2>
		bool operator!=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (!(lhs.base() == rhs.base()));
		}
		/**
		**************************************************
		 * random_access_iterator: comparison with inequality
		 * operators
		**************************************************
		**/

		//a<b
		template<typename T>
		bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() < rhs.base());
		}
		
		template<typename Iter1, typename Iter2>
		bool operator<(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (lhs.base() < rhs.base());
		}

		//a>b

		template<typename T>
		bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template<typename Iter1, typename Iter2>
		bool operator>(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

		//a<=b

		template<typename T>
		bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		template<typename Iter1, typename Iter2>
		bool operator<=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		//a>=b
		
		template<typename T>
		bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}
		
		template<typename Iter1, typename Iter2>
		bool operator>=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}

		//a-b
		template <typename T>
		typename random_access_iterator<T>::difference_type 
		operator-(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{
			return (lhs.base() - rhs.base());
		}

		template< typename Iter1, typename Iter2 >
		typename random_access_iterator<Iter1>::difference_type
    	operator-( const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs )
		{
			return (lhs.base() - rhs.base());
		}

		//a+n
		template <typename Iterator>
		random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator>& it)
		{
			return (random_access_iterator<Iterator>(it.base() + n));
		}
		
}

#endif