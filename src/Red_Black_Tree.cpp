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
		if (x->color = Red && x->parent->parent )
		else if(x->left_child != 0)
		{
			x = x->left_child;
			while (x->right_child != 0)
				x = x->right_child;
		}
		else
		{
			rb_base_node* y = 
		}
	}

	const rb_base_node* rb_tree_decrement(const rb_base_node * x) throw()
	{

	}


	
         // If it is a red street shop, and the parent node of the parent is equal to himself (status 1) The right child node is a solution.
    if (_M_node->_M_color == _S_rb_tree_red &&
        _M_node->_M_parent->_M_parent == _M_node)
      _M_node = _M_node->_M_right;
         // The above situation occurs when Node is Header (ie node is end ())
         / (Note, the HEADER's right child is MOSTRIGHT, pointing to the MAX node of the whole tree
 
         // If there is a left subpode (condition 2) make Y point to the left subpost, when Y has a right child node, go to the right of the right child to the end, the answer is the answer.
    else if (_M_node->_M_left != 0) {
      _Base_ptr __y = _M_node->_M_left;
      while (__y->_M_right != 0)
        __y = __y->_M_right;
      _M_node = __y;
    }
         // Non-root node, there is no left child node (condition 3), find the parent node, when the current node is the left child node, always alternately, know that the current node is not left sub-node
    else {
      _Base_ptr __y = _M_node->_M_parent;
      while (_M_node == __y->_M_left) {
        _M_node = __y;
        __y = __y->_M_parent;
      }
             _M_node = __y; // At this time, the parent node is the answer


}