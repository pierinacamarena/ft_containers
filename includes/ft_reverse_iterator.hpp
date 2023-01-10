/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:52:19 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/01 20:51:29 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_REVERSE_ITERATOR_
#define _FT_REVERSE_ITERATOR_

#include "ft_iterator.hpp"
#include "ft_iterator_traits.hpp"
#include "ft_random_access_iterator.hpp"

namespace ft {

	template <typename _Iterator>
	class reverse_iterator
	: public iterator<typename iterator_traits<_Iterator>::iterator_category,
                      typename iterator_traits<_Iterator>::value_type,
                      typename iterator_traits<_Iterator>::difference_type,
                      typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
{
	template<typename _Iter1> friend class reverse_iterator;
	protected:
	_Iterator _current;

		/**
		**************************************************
		 * reverse_iterator: Member types definition
		**************************************************
		**/
	
	public:
    typedef _Iterator                                            iterator_type;
    typedef typename iterator_traits<_Iterator>::difference_type difference_type;
    typedef typename iterator_traits<_Iterator>::reference       reference;
    typedef typename iterator_traits<_Iterator>::pointer         pointer;

	reverse_iterator(): _current() {}
	
	reverse_iterator(iterator_type x): _current(x) {}
	
	reverse_iterator(const reverse_iterator& other): _current(other._current) {}

	template <class _Iter1>
	reverse_iterator(const reverse_iterator<_Iter1>& other)
		: _current(other._current) {}

	/**
	**************************************************
		* reverse_iterator: copy assignment operator
	**************************************************
	*/

	template< class _Iter1>
	 reverse_iterator& operator=( const reverse_iterator<_Iter1>& other)
	 {
		_current = other._current;
		return (*this);
	 }

	/**
	**************************************************
		* reverse_iterator: access the underlying iterator
	**************************************************
	*/
	iterator_type base() const
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
		_Iterator tmp = _current; 
		return (*--tmp);
	}
	
    pointer  operator->() const				
	{
		return &(operator*());
	}

	/**
	**************************************************
		* reverse_iterator: operators (advances or decrements)
	**************************************************
	*/
	//pre increment, original iterator is decremented (++a)
    reverse_iterator& operator++()			
	{
		--_current;
		return (*this);
	}
	
	//post increment (a++)
    reverse_iterator  operator++(int) 		
	{
		reverse_iterator tmp(*this);
		--_current; 
		return (tmp);
	}

	//pre decrement, original iterator is incremented (--a)
    reverse_iterator& operator--() 			
	{
		++_current;
		return (*this);
	}
	
	//post decrement (a++)
    reverse_iterator  operator--(int)		
	{ 
		reverse_iterator tmp(*this);
		++_current;
		return (tmp);
	}
	
	//return iterator advanced by n, equivalent to -n because it is in reverse
    reverse_iterator  operator+ (difference_type n) const	
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
    reverse_iterator  operator- (difference_type n) const	
	{
		return (reverse_iterator(_current + n));
	}
	
	//advances the iterator by -n (in this case n as it is reverse)
    reverse_iterator& operator-=(difference_type n) 		
	{
		_current += n;
		return (*this);
	}
	
    reference         operator[](difference_type n) const	
	{ 
		return *(*this + n);
	}

};

//non member functions

template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
  { return lhs.base() == rhs.base();}

template <class ItLeft, class ItRight>
  bool operator== (const reverse_iterator<ItLeft>& lhs, const reverse_iterator<ItRight>& rhs)
  { return lhs.base() == rhs.base();}


template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,  const reverse_iterator<Iterator>& rhs)
  { return lhs.base() != rhs.base();}

template <class ItLeft, class ItRight>
  bool operator!= (const reverse_iterator<ItLeft>& lhs,  const reverse_iterator<ItRight>& rhs)
  { return lhs.base() != rhs.base();}


template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
  { return lhs.base() > rhs.base();}

template <class ItLeft, class ItRight>
  bool operator<  (const reverse_iterator<ItLeft>& lhs, const reverse_iterator<ItRight>& rhs)
  { return lhs.base() > rhs.base();}


template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
  { return lhs.base() >= rhs.base();}

template <class ItLeft, class ItRight>
  bool operator<= (const reverse_iterator<ItLeft>& lhs, const reverse_iterator<ItRight>& rhs)
  { return lhs.base() >= rhs.base();}


template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
  { return lhs.base() < rhs.base();}

template <class ItLeft, class ItRight>
  bool operator>  (const reverse_iterator<ItLeft>& lhs, const reverse_iterator<ItRight>& rhs)
  { return lhs.base() < rhs.base();}


template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
  { return lhs.base() <= rhs.base();}

template <class ItLeft, class ItRight>
  bool operator>= (const reverse_iterator<ItLeft>& lhs, const reverse_iterator<ItRight>& rhs)
  { return lhs.base() <= rhs.base();}


template< class Iterator >
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& it )
	{ return reverse_iterator<Iterator>(it.base() - n); }

template <class ItLeft, class ItRight>
	reverse_iterator<ItLeft> operator+(
		typename reverse_iterator<ItLeft>::difference_type n,
        const reverse_iterator<ItRight>& it )
	{ return reverse_iterator<ItLeft>(it.base() - n); }


template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (
    	const reverse_iterator<Iterator>& lhs,
    	const reverse_iterator<Iterator>& rhs)
	{ return rhs.base() - lhs.base(); }

template <class ItLeft, class ItRight>
  typename reverse_iterator<ItLeft>::difference_type operator- (
    	const reverse_iterator<ItLeft>& lhs,
    	const reverse_iterator<ItRight>& rhs)
	{ return rhs.base() - lhs.base(); }
}

#endif