#include "../includes/Red_Black_Tree/Red_Black_Tree.hpp"

namespace ft
{
	rb_base_node* rb_tree_increment(rb_base_node * x) throw()
	{
		if(x->right_child != 0) //if there is a right child, then the next node will the most left child of the right subtree
		{
			x = x->right_child; //go to the right child
			while (x->left_child != 0) //if there is a left child
				x = x->left_child; //go to the left child until the end
		}
		else
		{
			rb_base_node* y = x->parent; // find parent node 
			while(x == y->right_child) 
			{
				x = y;
				y = y->parent;
			}
			if (x->right_child != y)
				x = y; //parent node is next node
		}
		return (x);
	}

	const rb_base_node* rb_tree_increment(const rb_base_node * x) throw()
	{
		if(x->right_child != 0) //if there is a right child, then the next node will the most left child of the right subtree
		{
			x = x->right_child; //go to the right child
			while (x->left_child != 0) //if there is a left child
				x = x->left_child; //go to the left child until the end
		}
		else
		{
			rb_base_node* y = x->parent; // find parent node 
			while(x == y->right_child) 
			{
				x = y;
				y = y->parent;
			}
			if (x->right_child != y)
				x = y; //parent node is next node
		}
		return (x);
	}

	rb_base_node* rb_tree_decrement(rb_base_node * x) throw()
	{
		if (x->color == Red && x->parent->parent == x)
			x = x->right_child;
		else if(x->left_child != 0)
		{
			x = x->left_child;
			while (x->right_child != 0)
				x = x->right_child;
		}
		else
		{
			rb_base_node* y = x->parent;
			while (x == x->left_child)
			{
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return (x);
	}

	const rb_base_node* rb_tree_decrement(const rb_base_node * x) throw()
	{
				if (x->color == Red && x->parent->parent == x)
			x = x->right_child;
		else if(x->left_child != 0)
		{
			x = x->left_child;
			while (x->right_child != 0)
				x = x->right_child;
		}
		else
		{
			rb_base_node* y = x->parent;
			while (x == x->left_child)
			{
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return (x);
	}
