/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:52:23 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 04:57:55 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "ft_iterator_traits.hpp"
#include "ft_random_access_iterator.hpp"
#include "ft_reverse_iterator.hpp"
#include "nullptr.hpp"
#include "ft_utils_vector.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cassert>

#include <cstdlib>
#include <cstdio>


namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		/**
		**************************************************
		**************************************************
		 * Vector: Member types definition
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

		typedef typename ft::random_access_iterator<T> iterator;
		typedef typename ft::random_access_iterator<T const> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/*
		*Other									pointer;

		*/
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		private:
		/**
		 * Attributes, data
		*/
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;


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
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_start(nullptr_t),
			_end(nullptr_t),
			_end_capacity(nullptr_t)
			{}

		/*Constructs a container with n elements, each element is a copy
		of val*/
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_start(nullptr_t),
			_end(nullptr_t),
			_end_capacity(nullptr_t)
		{
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (n > 0)
			{
				_start = _alloc.allocate(n);
				_end = _start + n;
				_end_capacity = _end;
				while (n > 0)
					_alloc.construct(_start + --n, val);
			}
		}

		/*Constructs a container with as many elements as the range [first, last],
		with each element constructed from its corresponding element in that range,
		in the same order*/
		
		template <class InputIterator> 
			vector (InputIterator first, 
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type& alloc = allocator_type())
				: _alloc(alloc),
				  _start(nullptr_t),
				  _end(nullptr_t),
				  _end_capacity(nullptr_t)
			{
				
				difference_type len = std::distance(first, last);
				_start = _alloc.allocate(len);		
				_end = _copy(first, last, _start);
				_end_capacity = _end;				
			}

		/*Constructs a container with a copy of each of the elements in x, in the same order*/
		vector (const vector& x) :
			_start(nullptr_t),
			_end(nullptr_t),
			_end_capacity(nullptr_t)
		{
			if (this == &x )
				return;
			const size_type otherLen = x.size();
			if (size() > 0)
				_destroy(_start, _end);
			_start = _alloc.allocate(otherLen);
			_end = _start;
			_copy(x.begin(), x.end(), _end);
			_end = _start + otherLen;
			_end_capacity = _end;
			_alloc = x._alloc;
		}

		/*Destructor*/
		virtual ~vector()
		{
			while (_end != _start)
			{
				--_end;
				_alloc.destroy(_end);
			}
			if (capacity() != 0)
				_alloc.deallocate(_start, capacity());
		}

		/*Copy operator: Copies all the elements from x into the container*/
		vector& operator= (const vector& x)
		{
			size_type original_capacity = capacity();
			if (*this == x)
				return(*this);
			if (size() > 0)
				_destroy(_start, _end);
			size_t newLen = x.size();
			if (newLen <= capacity())
			{
				_end = _copy(x.begin(), x.end(), _start);
			}
			else
			{
				pointer oldStart = _start;
				_start = _alloc.allocate(newLen);
				if (original_capacity > 0)
				{
					_alloc.deallocate(oldStart, capacity());
				}
				_end = _copy(x.begin(), x.end(), _start);
				_end_capacity = _start + newLen;				
			}
			return (*this);
		}

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

		iterator begin()
		{
			return (_start);
		}

		const_iterator begin() const
		{
			return (_start);
		}

		/*END: Returns an iterator referring to the past-the-end element in the
		vector container, if the container is empty returns the same as begin()*/

		iterator end()
		{
			if (this->empty())
				return (this->begin());
			return (_end);
		}

		const_iterator end() const
		{
			if (this->empty())
				return (this->begin());
			return (_end);
		}

		/*RBEGIN: Returns a reverse iterator pointing to the last element in the
		vector, reverse iterators iterate backwards, increasing them means moving
		them towards the begining, points the element right before the one pointed
		by end()*/
		

		reverse_iterator rbegin()
		{
			return (end());
		}

		const_reverse_iterator rbegin() const
		{
			return (end());
		}

		/*REND: Returns a reverse iterator pointing to the theoretical element
		preciding the first element in the vector*/

		reverse_iterator rend()
		{
			return (begin());
		}

		const_reverse_iterator rend() const
		{
			return begin();
		}

		/*
		******************************************
		 * Capacity functions
		******************************************
		*/

		/*SIZE: Returns the number of elements in the vector, which is not necessarily
		equal to its storage capacity*/

		size_type size() const
		{
			return (_end - _start);
		}
		
		/*MAX_SIZE: Returns the maximum number of elements that the vector can hold.

		*This is the maximum potential size the container can reach due to known system
		or library implementation limitations, but the container is by no means
		guaranteed to be able to reach that size: it can still fail to allocate storage
		at any point before that size is reached.
		https://en.cppreference.com/w/cpp/memory/allocator/max_size
		*/

		size_type max_size() const
		{
			return (allocator_type().max_size());
		}

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
		void resize (size_type n, value_type val = value_type())
		{
			size_t tmp_size = size();
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (n == tmp_size)
				return ;
			if (n < tmp_size)
			{
				_destroy(_start + n, _end);
				_end = _start + n;
			}
			else
			{
				size_t	tmp_cap = capacity();
				if (n > tmp_cap)
				{
					if (n > (tmp_cap * 2))
						reserve(n);
					else
						reserve(tmp_cap * 2);
				}
				for (size_t i = 0; i < (n - tmp_size); i++)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}
		}

		/*CAPACITY: Returns the size of the storage space currently allocated for the vector,
		expressed in terms of elements.
		This capacity is >= the vector size. If greater, the extra space allows to accommodate for growth
		without the need to reallocate on each insertion.
		Notice that this capacity does not suppose a limit on the size of the vector.
		When this capacity is exhausted and more is needed, it is automatically expanded by the container
		(reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.*/

		size_type capacity() const
		{
			return (_end_capacity - _start);
		}

		/*EMPTY: Returns whether the vector is empty (i.e. whether its size is 0).*/

		bool empty() const
		{
			if (size() == 0)
				return (true);
			return (false);
		}

		/*RESERVE: Requests that the vector capacity be at least enough to contain n elements.
		-If n > the current vector capacity, the function causes the container to reallocate
		its storage increasing its capacity to n (or greater).
		-In all other cases, the function call does not cause a reallocation
		and the vector capacity is not affected.
		*This function has no effect on the vector size and cannot alter its elements.*/

		void reserve (size_type n)
		{
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (capacity() == 0 && n > 0)
			{
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
			}		
			else if (n > capacity())
			{
				pointer tmp;
				tmp = _alloc.allocate(n);
				_copy(begin(), end(), tmp);
				if (n > 1)
				{
					_destroy(_start, _end);
					_alloc.deallocate(_start, capacity());
				}
				_end = tmp + size();
				_start = tmp;
				_end_capacity = _start + n;
			}
		}
		
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

		reference operator[] (size_type n)
		{
			return (*(_start + n));
		}

		const_reference operator[] (size_type n) const
		{
			return (*(_start + n));
		}

		/*AT: Returns a reference to the element at position n in the vector.
		-The function automatically checks whether n is within the bounds of valid elements
		in the vector, throwing an out_of_range exception if it is not
		(i.e., if n is greater than, or equal to, its size).
		This is in contrast with member operator[], that does not check against bounds.*/

		reference at (size_type n)
		{
			if (n >= size())
				throw(std::out_of_range("vector"));
			return ((*this)[n]);
		}

		const_reference at (size_type n) const
		{
			if (n >= size())
				throw(std::out_of_range("vector"));
			return ((*this)[n]);
		}

		/*FRONT: Returns a reference to the first element in the vector.
		-Unlike member vector::begin, which returns an iterator to this same element,
		this function returns a direct reference.
		-Calling this function on an empty container causes undefined behavior*/

		reference front()
		{
			return (*_start);
		}

		const_reference front() const
		{
			return (*_start);
		}

		/*BACK: Returns a reference to the last element in the vector.
		-Unlike member vector::end, which returns an iterator just past this element,
		this function returns a direct reference.
		-Calling this function on an empty container causes undefined behavior.*/

		reference back()
		{
			return (*(_end - 1));
		}

		const_reference back() const
		{
			return (*(_end - 1));
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

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

		// //range version

		template <typename InputIt>
    	void assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last)
    	{
			size_type len = ft::distance(first, last);
			size_type orig_size = size();
			size_type orig_capacity = capacity();
			if (capacity() == 0)
			{
				_start = _alloc.allocate(len);
				_copy(first, last, _start);
				_end = _start + len;
				_end_capacity = _end;
			}
			else if (capacity() > 0 && size() == 0)
			{
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(len);
				std::uninitialized_copy(first, last, _start);
				_end = _start + len;
				_end_capacity = _end;
			}
			else if (len > orig_capacity)
			{
				_destroy(_start, _end);
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(len);
				std::uninitialized_copy(first, last, _start);
				_end = _start + len;
				_end_capacity = _end;
			}
			else if (orig_size >= len)
			{
				_erase_at_end(std::copy(first, last, _start));}
			else
			{
				InputIt mid = first;
				std::advance(mid, orig_size);
				std::copy(first, mid, _start);
				_end = _copy(mid, last, _end);
			}	
   		}

		//fill version
		void assign (size_type n, const value_type& val)
		{
			size_t _capacity = capacity();
			_destroy(_start, _end);
			if (n > _capacity)
			{
				if (capacity() > 0)
					_alloc.deallocate(_start, _capacity);
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				while (n)
				{
					_alloc.construct(_end, val);
					_end++;
					n--;
				}
			}
			else
			{
				_end = _start;
				while(n)
				{
					_alloc.construct(_end, val);
					_end++;
					n--;
				}
			}
		}

		/*PUSH BACK: Adds a new element at the end of the vector, after its current last element.
		The content of val is copied (or moved) to the new element.
		This effectively increases the container size by one, which causes an automatic reallocation
		of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.*/

		void push_back (const value_type& val)
		{
			if (_end == _end_capacity)
				_grow();
			_alloc.construct(_end, val);
			_end++;
		}


		/*POP_BACK: Removes the last element in the vector, effectively reducing the container size by one.
		This destroys the removed element.*/

		void pop_back()
		{
			_alloc.destroy(--_end);
		}

		/*INSERT: The vector is extended by inserting new elements before the element at the specified position,
		effectively increasing the container size by the number of elements inserted.

		This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size
		surpasses the current vector capacity.

		Inserting elements in positions other than the vector end causes the container to relocate all the elements
		that were after position to their new positions.
		*/

		// single element
		iterator insert (iterator position, const value_type& val)
		{
			size_type distance_to_pos = ft::distance(begin(), position);
			if (_end != _end_capacity && position == (end() - 1))
				_alloc.construct(_end++, val);
			else
				insert(position, 1, val);
			return (begin() + distance_to_pos);
		}

		//fill
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (n == 0)
				return;
			size_type original_capacity = capacity();
			if (size_type(_end_capacity - _end) >= n)
			{
				size_type	elems_after_pos = end() - position;
				pointer		oldEnd = _end;
				if (elems_after_pos > n)
				{
					_copy(end() - n, end(), end());
					_copy_backward(position.base(), oldEnd - n, oldEnd);
					std::fill(position.base(), position.base() + n, val);
				}
				else
				{
					_uninitialized_fill_n(_end, n - elems_after_pos, val);
					_copy(position.base(), oldEnd, _end + (n - elems_after_pos));
					std::fill(position.base(), oldEnd, val);
				}
				_end += n;
			}
			else
			{
				size_type len = size() + std::max(n, size());
				pointer new_start = _alloc.allocate(len);
				pointer tmp;
				tmp = _copy(begin(), position, new_start);
				_uninitialized_fill_n(tmp, n, val);
				tmp = _copy(position, end(), tmp + n);
				if (size() > 0)
					_destroy(_start, _end);
				if (original_capacity > 0)
					_alloc.deallocate(_start, capacity());
				_start = new_start;
				_end = tmp;
				_end_capacity = _start + len;
			}
		}

		// range
		template <class InputIterator>    
		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if< !is_integral<InputIterator>::value, int>::type = 0)
		{
				if (first == last)
				return;
				const size_type n = ft::distance(first, last);
				if (size_type(_end_capacity - _end) >= n)
				{
					const size_type elemsAfterPos = end() - position;
					pointer oldFinish(_end);
					if (elemsAfterPos > n)
					{
						_copy(_end - n, _end, end().base());
						_copy_backward(position.base(), oldFinish - n, oldFinish);
						_destroy_and_copy(first, last, position);
						_end += n;
					}
					else
					{
						InputIterator mid = first;
						std::advance(mid, elemsAfterPos);
						_copy(mid, last, _end);
						_end += n - elemsAfterPos;
						_copy(position.base(), oldFinish, _end);
						_end += elemsAfterPos;
						std::copy(first, mid, position);
					}
					
				}
				else
				{
					size_type new_capacity = capacity() + std::max(n, capacity());
					pointer futur_start = _alloc.allocate(new_capacity);
					pointer tmp;
					tmp  = _copy(begin(), position, futur_start);
					tmp = _copy(first, last, tmp);
					tmp = _copy(position, end(), tmp);
					if (size() > 0)
						_destroy(_start, _end);
					if (capacity() > 0)
						_alloc.deallocate(_start, capacity());
					_start = futur_start;
					_end = tmp;
					_end_capacity = _start + new_capacity;
				}
		}

		/*ERASE: Removes from the vector either a single element (position) or a range of elements ([first,last)).
		This effectively reduces the container size by the number of elements removed, which are destroyed.
		erasing elements in positions other than the vector end causes the container to relocate all the
		elements after the segment erased to their new positions. */

		iterator erase (iterator position)
		{
			return (_erase_one_position(position));
		}

		iterator erase (iterator first, iterator last)
		{
			if (first != last)
			{
				if (last != end())
					std::copy(last, end(), first);
				_erase_at_end(first.base() + (end() - last));
			}
			return first;
		}

		/*SWAP: Exchanges the content of the container by the content of x, which is another vector object
		of the same type. Sizes may differ.
		All iterators, references and pointers remain valid for the swapped objects.*/

		void swap (vector& x)
		{
			if (*this == x)
				return;
			allocator_type	tmp_alloc = x._alloc;
			pointer			tmp_start = x._start;
			pointer			tmp_end = x._end;
			pointer			tmp_capacity = x._end_capacity;

			x._start = _start;
			x._end = _end;
			x._end_capacity = _end_capacity;
			x._alloc = _alloc;

			_alloc = tmp_alloc;
			_start = tmp_start;
			_end = tmp_end;
			_end_capacity = tmp_capacity;	
		}

		/*CLEAR: Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		A reallocation is not guaranteed to happen, and the vector capacity
		is not guaranteed to change due to calling this function.*/

		void clear()
		{
			while (_end != _start)
			{
				--_end;
				_alloc.destroy(_end);
			}
		}

		/*
		******************************************
		 * private_functions
		******************************************
		*/

		void check_size(size_type count)
		{
			if (count > max_size()) {
				throw(std::length_error("vector::reserve"));
			}
		}

		pointer construct_range(pointer dst, const_pointer end, const_reference value)
		{
			for (; dst != end; ++dst) {
				_alloc.construct(dst, value);
			}
			return dst;
		}

		iterator _erase_one_position(iterator position)
		{
			if (position.base() + 1 != _end)
				std::copy(position + 1, end(), position);
			--_end;
			_alloc.destroy(_end);
			return position;
		}

		void _erase_at_end(pointer p)
		{
			const size_type n = _end - p;
			pointer it = p + n;
			if (n)
			{
				while(it != p)
					_alloc.destroy(--it);
				_end = p;
			}
		}

		void _destroy(pointer start, pointer end)
		{
			while (start != end)
			{
				_alloc.destroy(start);
				start++;
			}
		}

		void _deallocate_full()
		{
			_alloc.deallocate(_start, capacity());
			_start = nullptr_t;
			_end = nullptr_t;
			_end_capacity = nullptr_t;
		}

		void _deallocate_specify(pointer start, size_type len)
		{
			_alloc.deallocate(start, len);
		}

		void
		_uninitialized_fill_n(pointer start, size_type n, const value_type &val)
		{
			for (size_type i = 0; i < n; i++)
			{		
				_alloc.construct(start, val);
				start++;
			}
		}

		void
		_initialized_fill_n(pointer start, size_type n, const value_type &val)
		{
			for (size_type i = 0; i < n; i++)
			{		
				_alloc.destroy(start);
				_alloc.construct(start, val);
				start++;
			}
		}

		void
		_copy_backward(iterator first, iterator last, iterator end)
		{
			while (last > first)
			{
				--last;
				--end;
				_alloc.destroy(end.base());
				_alloc.construct(end.base(), *last);
			}
		}	

		pointer _allocate(size_type n)
		{
			return n == 0 ? pointer() : _alloc.allocate(n);
		}

		template<typename InputIterator>
		pointer _alloc_copy(size_type n, InputIterator first, InputIterator last)
		{
			pointer result = _allocate(n);
			std::uninitialized_copy(first, last, result);
			return result;
		}
		
		template <typename InputIterator>
		pointer
		_copy(InputIterator first, InputIterator last, iterator start)
		{
			while (first != last)	
			{
				_alloc.construct(start++.base(), *first++);
			}
			return (start.base());
		}

		template <typename InputIterator>
		iterator
		_destroy_and_copy(InputIterator first, InputIterator last, iterator start)
		{
			while (first != last)	
			{
				_alloc.destroy(&(*start));
				*start++ = *first++;
			}
			return (start);
		}
		

		void _grow(size_t n = 0)
		{
			if (capacity() == 0 && (n <= 1))
			{
				reserve(1);
			}
			else if (n > capacity())
				reserve(capacity() + n);
			else
				reserve(capacity() * 2);
		}
		
	};
	/**
	********************************
	  Non member function overloads
	*********************************
	*/

	/**
	 * Relational operators
	**/

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!operator==(lhs, rhs));
	}
	
	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!operator<(rhs, lhs));
	}
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!operator<(lhs, rhs));
	}


	/**
	 * Swap
	**/

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}

#endif