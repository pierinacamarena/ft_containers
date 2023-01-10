/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:23 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 05:44:03 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>
#include "vector.hpp"


namespace ft {
	
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
		/**
		**************************************************
		 * Stack: Member types definition
		**************************************************
		**/

		typedef typename Container::value_type			value_type;
		typedef Container								container_type;
		typedef typename Container::size_type			size_type;

		
		/**
		**************************************************
		 * Attributes, data
		**************************************************
		**/
		
		private:
		Container _container;

		public:
		/**
		**************************************************
		 * Stack: member functions
		**************************************************
		*/

		/*
		******************************************
		 * Constructors, destructors and copy
		******************************************
		*/
		
		/*A container adaptor keeps internally a container
		object as data. This container object is a copy of 
		the ctnr argument passed to the constructor, if any,
		otherwise it is an empty container.*/
		explicit stack (const Container & ctnr = Container()) :_container(ctnr) {}

		// virtual ~stack(void) {};
		/*
		******************************************
		 * Capacity functions
		******************************************
		*/

		/*EMPTY: Returns whether the stack is empty: i.e. whether its size is zero.
		Effectively calls member empty of the underlying container object.*/
		bool empty() const
		{
			return (_container.empty());
		}

		/*SIZE: Returns the number of elements in the stack.
		This member function effectively calls member size of 
		the underlying container object.*/
		size_type size() const
		{
			return (_container.size());
		}
		
		/*
		******************************************
		 * Element access functions
		******************************************
		*/

		/*TOP: Returns a reference to the top element in the stack.
		Since stacks are last-in first-out containers,
		the top element is the last element inserted into the stack.
		This member function effectively calls member back of 
		the underlying container object.
		*/
		value_type& top()
		{
			return (_container.back());
		}
		
		const value_type& top() const
		{
			return (_container.back());
		}

		/*
		******************************************
		 * Modifier functions
		******************************************
		*/

		/*PUSH: Inserts a new element at the top of the stack, 
		above its current top element. The content of this new element
		is initialized to a copy of val.
		
		This member function effectively calls the member function push_back
		of the underlying container object.*/

		void push (const value_type& val)
		{
			_container.push_back(val);
		}
		
		/*POP: Removes the element on top of the stack, effectively 
		reducing its size by one. The element removed is the latest element 
		inserted into the stack, whose value can be retrieved by calling member stack::top.
		This calls the removed element's destructor.
		This member function effectively calls the member function pop_back of the 
		underlying container object.*/

		void pop()
		{
			_container.pop_back();
		}

		/**
		 * Relational operators
		**/
		private:
	template<class T1, class Container1>
	friend bool operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);
	
	template<class T1, class Container1>
	friend bool operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);	
	};

	template<class T, class Container>
	inline bool
	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._container == rhs._container; }

	template<class T, class Container>
	inline bool
	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._container < rhs._container; }
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
	
}

#endif