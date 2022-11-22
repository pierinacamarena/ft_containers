/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:52:23 by pcamaren          #+#    #+#             */
/*   Updated: 2022/11/17 18:41:45 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		/**
		**************************************************
		**************************************************
		 * Member types definition
		**************************************************
		**************************************************
		**/
		//type of element the container will hold/holds
		typedef T value_type;
		//allocator used to allocate memory
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference reference;

		typedef typename allocator_type::const_reference const_reference;

		typedef typename allocator_type::pointer pointer;

		typedef typename allocator_type::const_pointer const_pointer;

		/*
		*Iterators
		*/

		// typedef typename ;
		//
		// typedef typename ;
		//
		// typedef typename ;
		//
		// typedef typename ;

		/*
		*Other
		*/
		typedef iterator_traits<iterator>::difference_type difference_type;

		typedef size_t size_type;

		private:
		/**
		 * Attributes
		*/

			size_type size;
			size_type capacity;
			allocator_type	alloc


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
		//template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		/*Constructs a container with a copy of each of the elements in x, in the same order*/
		//vector (const vector& x);

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
		//iterator begin();

		//const_iterator begin() const;

		/*END: Returns an iterator referring to the past-the-end element in the
		vector container, if the container is empty returns the same as begin()*/
		//iterator end();

		//const_iterator end() const;

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

		*This function changes the actual content of the container
		by inserting or erasing elements from it.*/
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

		/*
		******************************************
		 * Element access functions
		******************************************
		*/

		/*If the vector object is const-qualified, the function returns a const_reference.
		Otherwise, it returns a reference.

		Member types reference and const_reference are the reference types
		to the elements of the container (see vector member types).*/

		/*OPERATOR[]: Returns a reference to the element at position n in the vector container.*/

		reference operator[] (size_type n);

		const_reference operator[] (size_type n) const;

		/*AT: Returns a reference to the element at position n in the vector.
		-The function automatically checks whether n is within the bounds of valid elements
		in the vector, throwing an out_of_range exception if it is not
		(i.e., if n is greater than, or equal to, its size).
		This is in contrast with member operator[], that does not check against bounds.*/

		reference at (size_type n);

		const_reference at (size_type n) const;

		/*FRONT: Returns a reference to the first element in the vector.
		-Unlike member vector::begin, which returns an iterator to this same element,
		this function returns a direct reference.
		-Calling this function on an empty container causes undefined behavior*/

		reference front();

		const_reference front() const;

		/*BACK: Returns a reference to the last element in the vector.
		-Unlike member vector::end, which returns an iterator just past this element,
		this function returns a direct reference.
		-Calling this function on an empty container causes undefined behavior.*/

		reference back();

		const_reference back() const;

		/*
		******************************************
		 * Modifier functions
		******************************************
		*/

		/*ASSIGN: Assigns new contents to the vector, replacing its current contents,
		and modifying its size accordingly.

		-In the range version, the new contents are elements constructed from each of the elements
		in the range between first and last, in the same order.
		-In the fill version, the new contents are n elements, each initialized to a copy of val.

		*If a reallocation happens,the storage needed is allocated using the internal allocator.

		-Any elements held in the container before the call are destroyed and replaced by
		newly constructed elements (no assignments of elements take place).
		-This causes an automatic reallocation of the allocated storage space
		if -and only if- the new vector size surpasses the current vector capacity.*/

		//range version
		template <class InputIterator>  void assign (InputIterator first, InputIterator last);

		//fill version
		void assign (size_type n, const value_type& val);

		/*PUSH BACK: Adds a new element at the end of the vector, after its current last element.
		The content of val is copied (or moved) to the new element.
		This effectively increases the container size by one, which causes an automatic reallocation
		of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.*/

		void push_back (const value_type& val);

		/*POP_BACK: Removes the last element in the vector, effectively reducing the container size by one.
		This destroys the removed element.*/

		void pop_back();

		/*INSERT: The vector is extended by inserting new elements before the element at the specified position,
		effectively increasing the container size by the number of elements inserted.

		This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size
		surpasses the current vector capacity.

		Inserting elements in positions other than the vector end causes the container to relocate all the elements
		that were after position to their new positions.
		*/

		//single element
		iterator insert (iterator position, const value_type& val);

		//fill
		void insert (iterator position, size_type n, const value_type& val);

		//range
		template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

		/*ERASE: Removes from the vector either a single element (position) or a range of elements ([first,last)).
		This effectively reduces the container size by the number of elements removed, which are destroyed.
		erasing elements in positions other than the vector end causes the container to relocate all the
		elements after the segment erased to their new positions. */

		iterator erase (iterator position);

		iterator erase (iterator first, iterator last);

		/*SWAP: Exchanges the content of the container by the content of x, which is another vector object
		of the same type. Sizes may differ.
		All iterators, references and pointers remain valid for the swapped objects.*/

		void swap (vector& x);

		/*CLEAR: Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		A reallocation is not guaranteed to happen, and the vector capacity
		is not guaranteed to change due to calling this function.*/

		void clear();

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
