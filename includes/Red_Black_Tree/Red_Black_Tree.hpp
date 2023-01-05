/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_Black_Tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:32:10 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/05 19:29:14 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_RED_BLACK_TREE_
#define	_RED_BLACK_TREE_

#include <iostream>

namespace ft

{

enum Color { Black = false,	Red = true, };

/*
This is a double layered implementation of the node structure
this is done to have bigger elasticity.
The rb_node, inherits from the rb_base_node
*/ 

struct rb_base_node 
{
	typedef rb_base_node *base_ptr;
	typedef const rb_base_node *base_ptr_const;

	base_ptr	parent;
	base_ptr	left_child;
	base_ptr	right_child;
	enum Color	color;

	//returns the most left child
	static base_ptr minimum(base_ptr iter)
	{
		while (iter->left_child != 0)
			iter = iter->left_child;
		return (iter);
	}

	static base_ptr_const minimum(base_ptr_const iter)
	{
		while (iter->left_child != 0)
			iter = iter->left_child;
		return (iter);
	}

	static base_ptr	maximum(base_ptr iter)
	{
		while (iter->right_child != 0)
			iter = iter->right_child;
		return (iter);
	}

	static base_ptr_const maximum(base_ptr_const iter)
	{
		while (iter->right_child != 0)
			iter = iter->right_child;
		return (iter);
	}
};

template <class T>
struct rb_node : public rb_base_node
{
	typedef rb_base_node<Value>* type_link; //it links the received value to the rb_base_pointer
	T	value;

	rb_node(const T& val) : value(val){} //value constructor
	T* value_ptr() //this function will be useful for the rb_iterator
	{
		return (&value);
	}

	const T* value_ptr()
	{
		return (&value);
	}
};

rb_base_node* rb_tree_increment(rb_base_node * x) throw();

const rb_base_node* rb_tree_increment(const rb_base_node * x) throw();

rb_base_node* rb_tree_decrement(rb_base_node * x) throw();

const rb_base_node* rb_tree_decrement(const rb_base_node * x) throw();


template<typename T>
	struct Rb_tree_iterator
	{
		typedef T  								value_type;
		typedef T& 								reference;
		typedef T* 								pointer;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		typedef Rb_tree_iterator<T>				self;
		typedef rb_base_node::_Base_ptr			base_ptr;
		typedef rb_node<T>*	   					link_type;

		//Constructors
		Rb_tree_iterator() : _node(){}
		explicit Rb_tree_iterator(base_ptr x) : _node(x) {}

		//Access operators

		//dereference operator 
		reference	operator*() const
		{
			return (*static_cast<link_type>(_node)->value_ptr();)
		}

		//
		pointer		operator->() const
		{
			return (static_cast<link_type>(_node)->value_ptr();)
		}

		//Increment operators

		self&		operator++()
		{
			_node = rb_tree_increment(_node);
			return (*this);
		}

		self		operator++(int)
		{
			self tmp = *this;
			_node = rb_tree_increment(_node);
			return (tmp);
		}
		//Decrement operators

		self&		operator--()
		{
			_node = rb_tree_decrement(_node);
			return (*this);
		}

		self		operator--(int)
		{
			self tmp = *this;
			_node = rb_tree_decrement(_node);
			return (tmp);
		}

		//equality operators

		friend bool	operator==(const self &x, const self &y) const
		{
			return (_node == x._node);
		}

		friend bool	operator!=(const self &x, const self &y) const
		{
			return (_node != x._node);			
		}

		protected:
		base_ptr	_node;

	}; /*Rb_tree_iterator*/

//Rb_tree_const_iterator

template<typename T>
	struct Rb_tree_const_iterator
	{
		typedef T								value_type;
		typedef const T&						reference;
		typedef const T*						pointer;
		
		typedef	Rb_tree_iterator<T>				iterator;
		
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;
		
		typedef Rb_tree_const_iterator<T>		self;
		typedef rb_base_node::base_ptr_const	base_ptr;
		typedef const rb_node<T>				link_type;

		//Constructors

		Rb_tree_const_iterator() : _node(); {}

		Rb_tree_const_iterator(base_ptr x) : _node(x); {}

		Rb_tree_const_iterator(const iterator& it) : _node(it._node); {}

		self &operator=(const iterator &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		iterator _const_cast()
		{
			return (iterator(const_cast<typename iterator::base_ptr>(_node));)
		}

		//Accessors 

		reference operator*() const
		{
			return (*static_cast<link_type>(_node)->value_ptr();)
		}

		pointer operator->() const
		{
			return (static_cast<link_type>(_node)->value_ptr();)
		}
		
		//Increment

		self& operator++()
		{
			_node = rb_tree_increment(_node);
			return (*this);
		}

		self operator++(int)
		{
			self tmp = *this;
			_node = rb_tree_increment(_node);
			return (tmp);
		}

		//Decrement

		self& operator--()
		{
			_node = rb_tree_decrement(_node);
			return (*this);
		}

		self operator--(int)
		{
			self tmp = *this;
			_node = rb_tree_decrement(_node);
			return (tmp);
		}

		//Equality operators
		
		friend bool operator==(const self &x, const self &y) const
		{
			return (x._node == y._node);
		}

		friend bool operator==(const self &x, const self &y) const
		{
			return (x._node != x._node);
		}
		
		protected:

		base_ptr _node;
		
	}; /*Rb_tree_const_iterator*/


template<class Key,class Value, class KeyOfValue, class Compare = std::less<Key> , class Alloc = std::allocator<Value> >
class red_black_tree
{
	private:

	typedef rb_base_node*				base_ptr;
	typedef const rb_base_node*			const_base_ptr;
	
	typedef rb_node<Value>				node_type;
	typedef	node_type*					node_pointer;
	typedef const node_type*			const_node_pointer;
	
	typedef std::allocator<node_type>	node_allocator;
	
	public:
	typedef Key					key_type;
	typedef Value				value_type;
	
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef size_t				size_type;
	typedef std::ptrdiff_t		difference_type;
	
}; /*red_black_tree*/


}
#endif