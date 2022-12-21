/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:52:19 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/21 23:41:39 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_REVERSE_ITERATOR_
#define _FT_REVERSE_ITERATOR_

#include "ft_iterator.hpp"
#include "ft_iterator_traits.hpp"
#include "ft_random_access_iterator.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator
	{
		/**
		**************************************************
		 * reverse_iterator: Member types definition
		**************************************************
		**/
		public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		/**
		**************************************************
		 * reverse_iterator: Attributes, data
		**************************************************
		**/
		protected:
		Iterator _current;
		
		/**
		**************************************************
		 * reverse_iterator: constructor copy
		**************************************************
		*/
		public:

		reverse_iterator() : _current() {}
		
		explicit reverse_iterator(Iterator x) :_current(x) {}
		
		template <class Iter> 
		reverse_iterator(const reverse_iterator<Iter> &rev_iter) : _current(rev_iter._current) {}

		/**
		**************************************************
		 * reverse_iterator: destructor
		**************************************************
		*/

		~reverse_iterator();

		/**
		**************************************************
		 * reverse_iterator: copy assignment operator
		**************************************************
		*/

		template< class Iter >
		reverse_iterator& operator=( const reverse_iterator<Iter> &other )
		{
			if (*this != other)
				_current = (other.base());
			return (*this);
		}

		/**
		**************************************************
		 * reverse_iterator: conversion to another type
		 * in this case instantiating the template with const
		 * it is different from the compiler standpoint
		**************************************************
		*/

		template<typename T>
		reverse_iterator<ft::random_access_iterator<const T>>()const
		{
			return (reverse_iterator<ft::random_access_iterator<const T>>(_current));
		}

		//need to do one for the rbt iterator
		/**
		**************************************************
		 * reverse_iterator: access the underlying iterator
		**************************************************
		*/

		Iterator base() const // explicit
		{
			return (_current);
		}
		/**
		**************************************************
		 * reverse_iterator: access the pointed-to element
		**************************************************
		*/

		reference operator*() const
		{
			Iterator tmp = _current;
			return (*--tmp);
		}
		pointer operator->() const
		{
			return &(operator *());
		}
		/**
		**************************************************
		 * reverse_iterator: operators (advances or decrements)
		**************************************************
		*/
		
		//pre increment, original iterator is decremented (++a)
		reverse_iterator& operator++(){
			--_current;
			return (*this);
		}
		//post increment (a++)
		reverse_iterator operator++(int){
			reverse_iterator tmp = *this;
			--_current;
			return(tmp);
		}
		//pre decrement, original iterator is incremented (--a)
		reverse_iterator& operator--()
		{
			++_current;
			return (*this);
		}
		//post decrement (a--)
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++_current;
			return (tmp);
		}
		//return iterator advanced by n, equivalent to -n because it is in reverse
		reverse_iterator operator+ (difference_type n) const
		{
			return (reverse_iterator(_current - n));
		}
		//advances the iterator by n (in this case -n as it is reverse)
		reverse_iterator& operator+=(difference_type n)
		{
			_current -= n;
			return (*this);
		}
		//return iterator advanced by -n, equivalent to +n because it is in reverse
		reverse_iterator operator- (difference_type n) const
		{
			return (reverse_iterator(_current + n));
		}
		//advances the iterator by -n (in this case +n as it is reverse)
		reverse_iterator& operator-=(difference_type n)
		{
			_current += n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (*(_current - n -1));
		}
	};

	//non member function 
	
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() == rhs.base());
	}

	//
	
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
		
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() != rhs.base());
	}
	//
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base < rhs.base());
	}

	template< class Iterator1, class Iterator2 > 
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base < rhs.base());
	}

	//
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() > rhs.base());
	}

	//

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() >= rhs.base());
	}

	//
	
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	
	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() <= rhs.base());
	}
	//

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type 
	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type
    operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() - rhs.base());
	}
	
	//
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& it)
	{
		return (reverse_iterator<Iterator>(it.base() - n));
	}
}

#endif