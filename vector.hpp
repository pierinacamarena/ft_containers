/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:52:23 by pcamaren          #+#    #+#             */
/*   Updated: 2022/11/16 18:24:24 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft {
	template < class T, class Alloc = allocator<T> >
	class vector
	{
		public:
		/**
		***************************
		 * Member types definition
		***************************
		*/
		private:
		/**
		 * 
		*/
		public:
		/**
		**************************************************
		**************************************************
		 * Vector: Member functions
		**************************************************
		**************************************************
		*/

		/*
		******************************************
		 * Constructors, destructors and copy
		******************************************
		*/
		
		/*Constructs an empty container with no elements*/
		explicit vector (const allocator_type& alloc = allocator_type());

		/*Constructs an empty container with n elements, each element is a copy
		of val*/
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

		/*Constructs a container with as many elements as the range [first, last],
		with each element constructed from its corresponding element in that range,
		in the same order*/
		template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		/*Constructs a container with a copy of each of the elements in x, in the same order*/
		vector (const vector& x);
		
		/*Destructor*/
		~vector();

		/*Copy operator: Copies all the elements from x into the container*/
		vector& operator= (const vector& x);

		/*
		******************************************
		 * Iterators
		******************************************
		*/

		/*note: A const_iterator is an iterator that points to const content.
		This iterator can be increased and decreased (unless it is itself also const)
		just like the iterator returned by vector::end, 
		but it cannot be used to modify the contents it points to, 
		even if the vector object is not itself const. */
		
		/*BEGIN: Returns an iterator pointing to the first element in the vector
		if the container is empty, the returned iterator value shall not be dereferenced*/
		iterator begin();
		
		const_iterator begin() const;
		
		/*END: Returns an iterator referring to the past-the-end element in the 
		vector container, if the container is empty returns the same as begin()*/
		iterator end();
		
		const_iterator end() const;

		/*RBEGIN: Returns a reverse iterator pointing to the last element in the
		vector, reverse iterators iterate backwards, increasing them means moving
		them towards the begining, points the element right before the one pointed
		by end()*/

		reverse_iterator rbegin();
		
		const_reverse_iterator rbegin() const;

		/*REND: Returns a reverse iterator pointing to the theoretical element
		preciding the first element in the vector*/

		reverse_iterator rend();
		
		const_reverse_iterator rend() const;

		/*CBEGIN: Returns a const_iterators pointing to the first element in the
		container, if the containor is empty, the returned iterator value shall not
		be dereferenced.*/

		const_iterator cbegin() const noexcept;

		/*CEND: Returns a const_iterator pointing to the past-the-end element in the 
		container. If the container is empty it returns the same as cbegin*/

		const_iterator cend() const noexcept;

		/*CRBEGIN: Returns a const_reverse_iterator pointing to the last element in
		the container*/
		
		const_reverse_iterator crbegin() const noexcept;

		/*CREND: Returns a const_reverse_iterator pointing to the theoretical element
		preceding the first element in the container (which is considered its reverse end).*/

		const_reverse_iterator crend() const noexcept;
		
		/*
		******************************************
		 * Capacity functions
		******************************************
		*/

		/*SIZE: Returns the number of elements in the vector, which is not necessarily 
		equal to its storage capacity*/

		size_type size() const;

		/*MAX_SIZE: Returns the maximum number of elements that the vector can hold.
		
		*This is the maximum potential size the container can reach due to known system
		or library implementation limitations, but the container is by no means 
		guaranteed to be able to reach that size: it can still fail to allocate storage 
		at any point before that size is reached.*/

		size_type max_size() const;

		/*RESIZE: Resizes the container so that it contains n elements.
		-If n < current container size, the content is reduced to its first n elements, 
		removing and destroying those beyond.
		-If n > the current container size, the content is expanded by inserting at the end
		as many elements as needed to reach a size of n. If val is specified, 
		the new elements are initialized as copies of val, otherwise, they are value-initialized.
		-If n is also greater than the current container capacity, 
		an automatic reallocation of the allocated storage space takes place.

		*This function changes the actual content of the container by inserting or erasing elements from it.*/
		void resize (size_type n, value_type val = value_type());

		/*CAPACITY: Returns the size of the storage space currently allocated for the vector, 
		expressed in terms of elements.
		This capacity is >= the vector size. If greater, the extra space allows to accommodate for growth 
		without the need to reallocate on each insertion.
		Notice that this capacity does not suppose a limit on the size of the vector. 
		When this capacity is exhausted and more is needed, it is automatically expanded by the container
		(reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.*/

		size_type capacity() const;

		/*EMPTY: Returns whether the vector is empty (i.e. whether its size is 0).*/

		bool empty() const;
		
		/*RESERVE: Requests that the vector capacity be at least enough to contain n elements.
		-If n > the current vector capacity, the function causes the container to reallocate 
		its storage increasing its capacity to n (or greater).
		-In all other cases, the function call does not cause a reallocation 
		and the vector capacity is not affected.
		*This function has no effect on the vector size and cannot alter its elements.*/
		
		void reserve (size_type n);

		/*SHRINK_TO_FIT: Requests the container to reduce its capacity to fit its size.*/

		/*
		******************************************
		 * Element access functions
		******************************************
		*/

		/*
		******************************************
		 * Modifier functions
		******************************************
		*/

		/*
		******************************************
		 * Allocator
		******************************************
		*/

	};
	
	/**
	********************************
	  Non member function overloads
	*********************************
	*/

	/**
	 * Relational operators
	**/

	/**
	 * Swap
	**/
}

#endif