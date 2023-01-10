/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:47:07 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 03:42:59 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_
#define _MAP_

#include <iostream>
#include "nullptr.hpp"
#include "ft_pair.hpp"
#include "ft_iterator_traits.hpp"
#include "red_black_tree.hpp"
#include "ft_reverse_iterator.hpp"
#include "ft_lexicographical_compare.hpp"
#include "ft_equal.hpp"


namespace ft
{
	template < class Key, class T,	class Compare = std::less<Key>,	class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
public:
	// types:
	typedef Key																key_type;
	typedef T																mapped_type;
	typedef pair<const Key, T>												value_type;
	typedef Compare															key_compare;
	typedef Alloc															allocator_type;

	
	typedef typename allocator_type::reference								reference; 
	typedef typename allocator_type::const_reference						const_reference;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;

	typedef Node<value_type>												node_type;
	typedef node_type*														node_pointer;
	
	typedef typename ft::tree_iterator<value_type, node_type>				iterator;
	typedef typename ft::tree_iterator<const value_type, const node_type>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
	typedef typename std::size_t											size_type;
	
	typedef ft::Red_Black_Tree<key_type, value_type, ft::selectFirst<value_type, key_type>, key_compare> tree_type;

	class value_compare
	{
		friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type &x, const value_type &y) const
		{
			return comp(x.first, y.first);
		}
	};
	
	private:
		allocator_type		_alloc;
		key_compare			_comp;
		tree_type			_rbt;

	public:

// construct
	explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _comp(comp), _rbt() {}
	
	template <class InputIterator>
 	 map(InputIterator first, InputIterator last,
	  	const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp), _rbt()
		{
			insert(first, last);
		}

	map(const map& other) : _alloc(other._alloc), _comp(other._comp)
	{
		insert(other.begin(), other.end());
	}
	
	~map(){}

	map& operator= (const map& other)
	{
		if (this != &other)
		{
			if (_rbt.getSize() > 0)
			{
				clear();
			}
			_alloc = other._alloc;
			_comp = other._comp;
			insert(other.begin(), other.end());
		}
		return (*this);
	}

// iterator
	iterator		begin()
	{
		return (iterator(_rbt.min(), _rbt.getRoot(), _rbt.getNill()));
	}
	
	const_iterator	begin() const
	{
		return (const_iterator(_rbt.min(), _rbt.getRoot(), _rbt.getNill()));
	}
	
	iterator		end()
	{
		return (iterator(_rbt.getNill(), _rbt.getRoot(), _rbt.getNill()));
	}
	
	const_iterator	end() const
	{
		return (const_iterator(_rbt.getNill(), _rbt.getRoot(), _rbt.getNill()));
	}

	reverse_iterator		rbegin()
	{
		return (reverse_iterator(end()));
	}
	
	const_reverse_iterator	rbegin() const
	{
		return (const_reverse_iterator(end()));
	}
	
    reverse_iterator		rend()
	{
		return (reverse_iterator(begin()));
	}
	
	const_reverse_iterator	rend() const
	{
		return (const_reverse_iterator(begin()));
	}

// capacity
	bool		empty() const
	{
		return (_rbt.getSize() == 0);
	}
	
	size_type	size() const
	{
		return (_rbt.getSize());
	}
	size_type	max_size() const
	{
		return (_rbt.max_size());
	}

// element access 
	mapped_type& operator[] (const key_type& k)
	{

		// return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		node_pointer found = _rbt.search(k);
		if (found != _rbt.getNill())
			return (found->data.second);
		_rbt.insert(value_type(k, mapped_type()));
		found = _rbt.search(k);
		return (found->data.second);
	}

// modifiers
	ft::pair<iterator,bool>	insert(const value_type& val)
	{
		bool b = _rbt.insert(val);
		iterator iter = find(val.first);
		return (ft::pair<iterator, bool>(iter, b));
	}
	
	iterator	insert(iterator position, const value_type& val)
	{
		(void)position;
		return (insert(val)).first;
	}

	template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
	{
		while (first != last)
			_rbt.insert(*(first++));
	}
	
	void		erase(iterator position)
	{
		erase((*position).first);
	}
	size_type	erase(const key_type& k)
	{
		if (_rbt.deleteNode(k))
			return (1);
		return (0);
	}
    void		erase(iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
	}
	
	void 		swap(map& other)
	{
		_rbt.swap(other._rbt);
	}
	
	void 		clear()
	{
		erase(begin(), end());
	}

// observers
	/*
	Returns a copy of the comparison object used by the container to compare keys.
	*/
	key_compare	key_comp() const
	{
		return (_comp);
	}
	
	/*
	Returns a comparison object that can be used to compare two elements
	to get whether the key of the first one goes before the second.
	*/
	
	value_compare value_comp() const
	{
		return (value_compare(_comp));
	}

// operations

	/*
	Searches the container for an element with a key equivalent to k 
	Return: an iterator to it if found, 
	otherwise it returns an iterator to map::end.
	*/

    iterator		find(const key_type& k)
	{
		node_pointer found = _rbt.search(k);
		
		if (found == _rbt.getNill())
			return (end());
		return (iterator(found, _rbt.getRoot(), _rbt.getNill()));
	}
	
	const_iterator	find(const key_type& k) const
	{
		node_pointer found = _rbt.search(k);
		
		if (found == _rbt.getNill())
			return (end());
		return (const_iterator(found, _rbt.getRoot(), _rbt.getNill()));
	}

	/*
	Searches the container for elements with a key equivalent to k.
	Returns the number of matches.
	
	Because all elements in a map container are unique,
	the function can only return 1 (if the element is found) or zero (otherwise).
	*/
	
	size_type		count(const key_type& k) const
	{
		node_pointer	found_node = _rbt.search(k);
		if(found_node == _rbt.getNill())
			return (0);
		return (1);
	}
	
	/*
	Returns an iterator pointing to the first element in the container whose key 
	is not considered to go before k (i.e., either it is equivalent or goes after).
	*/
	iterator		lower_bound (const key_type& k)
	{
		if (_rbt.getSize() == 0)
			return (end());
		iterator iter = begin();
		while (iter != end())
		{
			if (_comp((*iter).first, k) == false)
				break;
			iter++;
		}
		return (iter);
	}
	
	const_iterator	lower_bound (const key_type& k) const
	{
		if (_rbt.getSize() == 0)
			return (end());
		const_iterator iter = begin();
		while (iter != end())
		{
			if (_comp((*iter).first, k) == false)
				break;
			iter++;
		}
		return (iter);
	}
	
	/*Returns an iterator pointing to the first element 
	in the container whose key is considered to go after k.*/
	iterator		upper_bound (const key_type& k)
	{
		if (_rbt.getSize() == 0)
			return (end());
		iterator iter = begin();
		while (iter != end())
		{
			if (_comp(k, (*iter).first) == true)
				break;
			iter++;
		}
		return (iter);
	}
	const_iterator	upper_bound (const key_type& k) const
	{
		if (_rbt.getSize() == 0)
			return (end());
		const_iterator iter = begin();
		while (iter != end())
		{
			if (_comp(k, (*iter).first) == true)
				break;
			iter++;
		}
		return (iter);
	}
	pair<iterator,iterator>             equal_range(const key_type& k)
	{
		return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	}
	
	pair<const_iterator,const_iterator> equal_range(const key_type& k) const
	{
		return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
	}

	allocator_type	get_allocator() const
	{
		return (_alloc);
	}

}; /* class map */

template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// not equal <==> !(==)
	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!operator==(lhs, rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!operator<(rhs,lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!operator<(lhs, rhs));
	}

template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
}

} /*namespace ft*/

#endif /*MAP*/
