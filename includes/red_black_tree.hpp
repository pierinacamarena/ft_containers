/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:27:28 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/11 11:46:07 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MAIN_NODE_
#define _MAIN_NODE_

#include <clocale>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <iostream>

#include "nullptr.hpp"
#include "ft_reverse_iterator.hpp"

namespace ft
{

	enum Color { BLACK = false,	RED = true};

	template <class T>
	struct Node {

		T				data;
		Node*			parent;
		Node*			left;
		Node*			right;
		Color			color;

		Node() : data(0), parent(NULL), left(NULL), right(NULL), color(BLACK) {}
		Node(const T& data) : data(data), parent(NULL), left(NULL), right(NULL), color(BLACK) {}
		Node(const T& data, const Node* node) :  data(data), parent(node->parent), left(node->left), right(node->right), color(node->color) {}
		Node(const Node& copy) : data(copy.data), parent(copy.parent), left(copy.left), right(copy.right), color(copy.color) {}
		Node (T data, Node* parent, Node *left, Node *right, Color color):data(data), parent(parent), left(left), right(right), color(color){}
		~Node() {}

		Node & operator=(const Node & rhs) {
			new (this) Node(rhs);
			return (*this);
		}

		 Node *sibling() {
			if (parent == NULL)
			return NULL;
		
			if (isOnLeft())
			return parent->right;
		
			return parent->left;
		}

		bool hasRedChild() {
    		return (left != NULL && left->color == RED) ||
           (right != NULL && right->color == RED);
  		}

		bool isOnLeft() { return this == parent->left; }
	};

	template< typename T, typename N>
	class tree_iterator
	{
		public:
		typedef T								value_type;
		typedef T&								reference;
		typedef const T& 						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		protected:
		typedef	tree_iterator					iterator;
		typedef N								node_type;
		typedef	node_type*						node_pointer;

		node_pointer	_ptr;
		node_pointer	_root;
		node_pointer	_nil;

		public:

		tree_iterator() {
			_ptr = NULL;
			_root = NULL;
			_nil = NULL;
		}

		tree_iterator(node_pointer ptr, node_pointer root, node_pointer nil) : _ptr(ptr), _root(root), _nil(nil) {}

		tree_iterator(const iterator &copy) : _ptr(copy._ptr), _root(copy._root), _nil(copy._nil){}

		iterator &operator=(const iterator &rhs)
		{
			if(this != &rhs)
			{
				_ptr = rhs._ptr;
				_root = rhs._root;
				_nil = rhs._nil;
			}
			return (*this);
		}

		~tree_iterator() {}

		operator tree_iterator<const value_type, const node_type>()const
		{
			return (tree_iterator<const value_type, const node_type>(_ptr, _root, _nil));
		}

		//derefence

		
		reference operator*()
		{
			return ((_ptr->data));
		}

		const_reference operator*() const
		{
			return ((_ptr->data));
		}

		pointer operator->()
		{
			return (&(operator*()));
		}

		const_pointer operator->() const
		{
			return (&(operator*()));
		}

		//prefix
		iterator &operator++()
		{
			if (_ptr != _nil)
				_ptr = increment(_ptr);
			return (*this);
		} 

		//postfix
		iterator operator++(int)
		{
			iterator tmp = *this;
			_ptr = increment(_ptr);
			return (tmp);
		}

		//decrement

		//prefix
		iterator &operator--()
		{
			if(_ptr == _nil)
				_ptr = max(_root);
			else
				_ptr = decrease(_ptr);
			return (*this);
		}

		//postfix
		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		//equality operators

		friend bool operator==(const iterator &x, const iterator &y)
		{
			return (x._ptr == y._ptr);
		}

		friend bool operator!=(const iterator &x, const iterator &y)
		{
			return !(x == y);
		}

		//helper functions
		node_pointer get_ptr()
		{
			return (_ptr);
		}

		node_pointer	min(node_pointer node)
		{
			while (node->left != _nil)
				node = node->left;
			return (node);
		}

		node_pointer	max(node_pointer node)
		{
			while (node->right != _nil)
				node = node->right;
			return (node);
		}


		node_pointer	decrease(node_pointer node)
		{
			node_pointer tmp = node;
			if (node->left != _nil)
				return (max(node->left));
			node_pointer y = node->parent;
			while (y != NULL && node == y->left)
			{
				node = y;
				y = y->parent;
			}
			if (y == NULL)
				return (min(tmp));
			return (y);
		}

		node_pointer	increment(node_pointer x)
		{
			
			if(x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
				return (x);
			}
			else
			{
				node_pointer y = x->parent;
				while (y != NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (y == NULL)
					return (_nil);
				if (x->right != y)
					x = y;	
			}
			return (x);
		}
	};

	template <class Key, class Value, class KeyOfValue, class Compare = std::less<Key>, class Alloc = std::allocator<Value> >
	class Red_Black_Tree
	{
		public:
		typedef Key							key_type;
		typedef Value						value_type;
		typedef Compare						value_compare;
		typedef Alloc						allocator_type;
		typedef Node<value_type>			node_type;
		typedef Node<value_type>*			node_pointer;
		typedef std::size_t					size_type;

		typedef tree_iterator<value_type, node_pointer>				iterator;
		typedef tree_iterator<value_type const, node_pointer>		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		typedef typename Alloc::template rebind< Node<value_type> >::other	node_allocator_type;

		private:
		node_pointer			_root;
		node_pointer			_TNULL;
		node_allocator_type		_node_alloc;
		value_compare 			_comp;
		size_type				_size;

		public:
		Red_Black_Tree(const value_compare &comp = value_compare(), const allocator_type alloc = allocator_type()): _node_alloc(alloc), _comp(comp), _size(0) {
			_TNULL = _node_alloc.allocate(1);
			_root = _TNULL;
			_node_alloc.construct(_TNULL, node_type(value_type(), NULL, NULL, NULL, BLACK));
		}

		~Red_Black_Tree()
		{
			clear_rec(_root);
			_root = _TNULL;
			_node_alloc.destroy(_TNULL);
			_node_alloc.deallocate(_TNULL, 1);
		}

		node_pointer	getRoot(void) const{ return _root;}
		size_type	getSize(void) const{ return _size;}
		node_pointer	getNill(void) const{ return _TNULL;}
		size_type	max_size(void) const {return _node_alloc.max_size();}

		node_pointer		min(void) const
		{
			return min(_root);
		}

		node_pointer		min(node_pointer node) const
		{
			if (node == _TNULL)
				return _root;
			while (node->left != _TNULL)
				node = node->left;
			return node;
		}

		node_pointer		max(void) const
		{
			return max(_root);
		}

		node_pointer		max(node_pointer node) const
		{
			if(node == _TNULL)
				return _root;
			while(node->right != _TNULL)
				node = node->right;
			return node;
		}

		static int		max_depth(node_pointer n)
		{
			if (!n) return 0;
			return 1 + std::max(max_depth(n->left), max_depth(n->right));
		}

		void swap(Red_Black_Tree &rhs)
		{
			node_allocator_type		tmp_node_alloc = _node_alloc;
			value_compare 			tmp_comp = _comp;
			size_type				tmp_size = _size;
			node_pointer			tmp_root = _root;
			node_pointer			tmp_tnull = _TNULL;

			_node_alloc = rhs._node_alloc;
			_comp = rhs._comp;
			_size = rhs._size;
			_root = rhs._root;
			_TNULL = rhs._TNULL;

			rhs._size = tmp_size;
			rhs._comp = tmp_comp;
			rhs._node_alloc = tmp_node_alloc;
			rhs._root = tmp_root;
			rhs._TNULL = tmp_tnull;
		}

		int	altura(node_pointer node = NULL) const
		{
			if(!node)
				node = _root;
			int hl = 0;
			int	hr = 0;
			int h = 0;
			if( !node || node == _TNULL)
				h = 0;
			else
			{
				hl = altura(node->left);
				hr = altura(node->right);

				if (hl > hr)
					h = hl+ 1;
				else
					h = hr + 1;
			}
			return h;
		}

		void			set_size()
		{
			_size = 0;
		}

		value_type		&get_data(node_pointer node = NULL) const
		{
			if(!node)
				node = _root;
			return (node->data);
		}

		void printTree()
		{
			if (_root)
			{
				printHelper(_root, "", true);
			}
  		}

		node_pointer		search(const key_type &key) const
		{
			return  search(_root, key);
		}

		bool			insert(const value_type &data)
		{
			node_pointer	new_node = create_new_node(data);
			node_pointer	y = _TNULL; //a leaf
			node_pointer	x = _root; //root
			if (_size == 0)
			{
				_root = new_node;
				_size++;
				return (true);
			}
			while (x !=_TNULL)
			{
				y = x;
				if(_comp(KeyOfValue()(new_node->data), KeyOfValue()(x->data)))
					x = x->left;
				else if(_comp(KeyOfValue()(x->data), KeyOfValue()(new_node->data)))
					x = x->right;
				else
				{
					_node_alloc.destroy(new_node);
					_node_alloc.deallocate(new_node, 1);
					return false;
				}
			}
			new_node->parent = y;
			if (!y)
			{
					_root = new_node;}
			else if (_comp(KeyOfValue()(new_node->data), KeyOfValue()(y->data)))
			{
				y->left = new_node;
			}
			else
			{
				y->right = new_node;
			}
			_size++;
			new_node->left = _TNULL;
			new_node->right = _TNULL;
			new_node->color = RED;
			insert_fix(new_node);
			return true;
		}
	
		node_pointer create_new_node(const value_type &val)
		{
			node_type node(val);
			node.parent = NULL;
			node.left = _TNULL;
			node.right = _TNULL;
			node.color = BLACK;
			node_pointer new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, node);
			if (!_root)
				_root = new_node;
			else
				node.color = RED;
			return (new_node);
		}
		
		bool			deleteNode(const key_type &key)
		{
			node_pointer node_to_delete, x, y;
			Color		saved_color;
			bool		leaf;

			node_to_delete = search(key);
			if (node_to_delete == _TNULL)
				return false;
			leaf = is_leaf(node_to_delete);
			saved_color = node_to_delete->color;
			if(node_to_delete->left == _TNULL)
			{
				x = node_to_delete->right;
				rbTransplant(node_to_delete, node_to_delete->right);
			}
			else if(node_to_delete->right == _TNULL)
			{
				x = node_to_delete->left;
				rbTransplant(node_to_delete, node_to_delete->left);
			}
			else
			{
				y = min(node_to_delete->right);
				saved_color = y->color;
				x = y->right;
				if (y->parent == node_to_delete)
					x->parent = y;
				else
				{
					rbTransplant(y, y->right);
					y->right = node_to_delete->right;
					y->right->parent = y;
				}
				rbTransplant(node_to_delete, y);
				y->left = node_to_delete->left;
				y->left->parent = y;

				y->color = node_to_delete->color;
			}
			_node_alloc.destroy(node_to_delete);
			_node_alloc.deallocate(node_to_delete, 1);
			_size--;
			if(!leaf && saved_color == BLACK)
				deleteFix(x);
			return true;
		}

		void			rbTransplant(node_pointer a, node_pointer b)
		{
			node_pointer    p = a->parent;
			if(!p)
				_root = b;
			else if(is_left(a))
				p->left = b;
			else
				p->right = b;
			b->parent = p;
		}

		void			deleteFix(node_pointer node)
		{
			while(node != _root && node->color == BLACK)
			{
				node_pointer    _sibling = sibling(node);
				if(is_left(node) && _sibling != _TNULL)
				{
					if (_sibling->color == RED)
					{
						_sibling->color = BLACK;
						node->parent->color = RED;
						leftRotate(node->parent);
						_sibling = node->parent->right;
					}

					if(_sibling->left->color == BLACK && _sibling->right->color == BLACK)
					{
						_sibling->color = RED;
						node = node->parent;
					}
					else
					{
						if(_sibling->right->color == BLACK)
						{
							_sibling->left->color = BLACK;
							node->color = RED;
							rightRotate(node);
							_sibling = node->parent->right;
						}
						_sibling->color = node->parent->color;
						node->parent->color = BLACK;
						_sibling->right->color = BLACK;
						leftRotate(node->parent);
						node = _root;
						break;
					}
				}
				else
				{
					if (_sibling != _TNULL)
					{
						if (_sibling->color == RED)
						{
							_sibling->color = BLACK;
							node->parent->color = RED;
							rightRotate(node->parent);
							_sibling = node->parent->left;
						}

						if (_sibling->left->color == BLACK && _sibling->right->color == BLACK)
						{
							_sibling->color = RED;
							node = node->parent;
						}
						else
						{
							if(_sibling->left->color == BLACK)
							{
								_sibling->right->color = BLACK;
								_sibling->color = RED;
								leftRotate(node);
								_sibling = node->parent->left;
							}
							_sibling->color = node->parent->color;
							node->parent->color = BLACK;
							_sibling->left->color = BLACK;
							rightRotate(node->parent);
							node = _root;
							break;
						}
					}
				}
				if (_sibling == _TNULL)
					break;
			}
			node->color = BLACK;
		}
		
		private:

		
		void		leftRotate(node_pointer  x)
		{
			if (x != _TNULL)
			{			
				node_pointer y = x->right;
				x->right = y->left;
				if (y->left != _TNULL)
					y->left->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					this->_root = y;
				else if (x == x->parent->left)
					x->parent->left = y; 
				else
					x->parent->right = y;
				y->left = x; 
				x->parent = y;
			}
		}
		
		void		rightRotate(node_pointer x)
		{
			if (x != _TNULL)
			{
				node_pointer y = x->left;

				x->left = y->right;
				if (y != _TNULL && y->right != _TNULL && x!= _TNULL)
				{
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (!x->parent)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->right = x;
				x->parent = y;
			}
		}


		void		insert_fix(node_pointer x)
		{
				while (x->parent->color == RED)
				{
					if (x->parent == x->parent->parent->left)
					{
						node_pointer y = x->parent->parent->right;
						if (y && y->color == RED)
						{
							x->parent->color = BLACK;
							y->color = BLACK; 
							x->parent->parent->color = RED;
							x = x->parent->parent;
						}
						else
						{
							if (x == x->parent->right)
							{
								x = x->parent;
								leftRotate(x);
							}
							x->parent->color = BLACK;
							x->parent->parent->color = RED;
							rightRotate(x->parent->parent);
						}
					}
					else
					{
						node_pointer y = x->parent->parent->left;
						if (y && y->color == RED)
						{
							x->parent->color = BLACK;
							y->color = BLACK;
							x->parent->parent->color = RED;
							x = x->parent->parent;
						}
						else
						{
							if (x == x->parent->left)
							{
								x = x->parent;
								rightRotate(x);
							}
							x->parent->color = BLACK;
							x->parent->parent->color = RED;
							leftRotate(x->parent->parent);
						}
					}
					if (x == _root) {
        				break;
      				}
				}
				_root->color = BLACK;
		}

		bool			is_leaf(node_pointer node) const 
		{
			return (node->left == _TNULL && node->right == _TNULL);
		}

		node_pointer	search(node_pointer node, const key_type &key) const
		{
			if (node == _TNULL)
				return _TNULL;
			if (key == KeyOfValue()(node->data))
				return node;
			if (_comp(key, KeyOfValue()(node->data)))
				return (search(node->left, key));
			else
				return (search(node->right, key));
		}


		node_pointer	successor(node_pointer x)
		{
			node_pointer tmp = x;
			while (tmp->left != _TNULL)
				tmp = tmp->left;
			return (tmp);
		}


		void			rb_transplant(node_pointer u, node_pointer v)
		{	
			if (u->parent == _TNULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		}
		
		node_pointer	bst_replace(node_pointer x)
		{
			if (x->left == _TNULL and x->right == _TNULL) //node is a leaf
				return (_TNULL);
			if (x->left != _TNULL && x->right != _TNULL) //node has two children
				return (successor(x->right));
			if (x->left != _TNULL)
				return x->left;
			else
				return x->right;
		}

		node_pointer	sibling(node_pointer node)
		{
			node_pointer    p = node->parent;
			if (!p)
				return NULL;
			if (node == p->left)
				return p->right;
			else	
				return p->left;
		}
		
		static bool    is_left(node_pointer node)
		{ 
			return (node == node->parent->left);
		}
		
		static bool    is_right(node_pointer node)
		{
			return (node == node->parent->right);
		}

		void swapValues(node_pointer u, node_pointer v) {
			value_type temp;
			temp = u->data;
			u->data = v->data;
			v->data = temp;
		}
		
		void printHelper(node_pointer print_root, std::string indent, bool last) {
			if (print_root != _TNULL) 
			{
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = print_root->color ? "RED" : "BLACK";
				std::cout << KeyOfValue()(print_root->data) << "(" << sColor << ")" << std::endl;
				printHelper(print_root->left, indent, false);
				printHelper(print_root->right, indent, true);
			}
		}

		void fixDoubleBlack(node_pointer x)
		{
			if (x == _root)
				return;
		
			node_pointer sibling = x->sibling(), parent = x->parent;
			if (sibling == _TNULL)
			{
				// No sibiling, double black pushed up
				fixDoubleBlack(parent);
			} 
			else 
			{
				if (sibling->color == RED)
				{
					// Sibling red
					parent->color = RED;
					sibling->color = BLACK;
					if (sibling->isOnLeft())
					{
						// left case
						rightRotate(parent);
					} 
					else 
					{
						// right case
						leftRotate(parent);
					}
				fixDoubleBlack(x);
				} 
				else
				{
					// Sibling black
					if (sibling->hasRedChild())
					{
						// at least 1 red children
						if (sibling->left != _TNULL && sibling->left->color == RED)
						{
							if (sibling->isOnLeft())
							{
								// left left
								sibling->left->color = sibling->color;
								sibling->color = parent->color;
								rightRotate(parent);
							}
							else
							{
								// right left
								sibling->left->color = parent->color;
								rightRotate(sibling);
								leftRotate(parent);
							}
						}
						else 
						{
							if (sibling->isOnLeft())
							{
								// left right
								sibling->right->color = parent->color;
								leftRotate(sibling);
								rightRotate(parent);
							}
							else
							{
								// right right
								sibling->right->color = sibling->color;
								sibling->color = parent->color;
								leftRotate(parent);
							}
						}
						parent->color = BLACK;
					}
					else
					{
						// 2 black children
						sibling->color = RED;
						if (parent->color == BLACK)
							fixDoubleBlack(parent);
						else
							parent->color = BLACK;
					}
				}
			}
		}

		void clear_rec(node_pointer const &node)
		{
			if (node == _TNULL) //base case
				return;
			clear_rec(node->left);
			clear_rec(node->right);

			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
			_size--;
		}

	};
}

#endif