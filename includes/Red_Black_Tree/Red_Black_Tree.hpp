/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_Black_Tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:32:10 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/05 00:19:20 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_RED_BLACK_TREE_
#define	_RED_BLACK_TREE_

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
struct rb_node : public rb_base_node{
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



}
#endif