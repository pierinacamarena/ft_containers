/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierina <pierina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:10:56 by pierina           #+#    #+#             */
/*   Updated: 2022/12/20 17:59:28 by pierina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_RANDOM_ACCESS_ITERATOR_
#define _FT_RANDOM_ACCESS_ITERATOR_

namespace ft
{
	template<typename T>
    class random_access_iterator
    {
    protected:
		//atributtes 
		T *_ptr;

		//added for readability
		typedef ft::iterator_traits<T*>           __traits_type;

	/*********Random_access_iterator typedefs*********/

    public:
		typedef T											iterator_type;
		typedef typename __traits_type::iterator_category	iterator_category;
		typedef typename __traits_type::value_type			value_type;
		typedef typename __traits_type::difference_type		difference_type;
		typedef typename __traits_type::reference			reference;
		typedef typename __traits_type::pointer				pointer;

		//constructors

		random_access_iterator() : _ptr(NULL){}
		random_access_iterator(T *ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &it) : _ptr(it._ptr) {}

		//destructor
		~random_access_iterator();
		
		//conversion to another type, when it is instantiated with const
		operator random_access_iterator<T const>() const
		{
			return (random_access_iterator<const T>(_ptr));
		}

		//assignment operator
		random_access_iterator &operator=(const random_access_iterator &it)
		{
			if (*this != &it)
				_ptr = it._ptr;
			return (*this);
		}

		//access to the pointer to the iterator

		random_access_iterator base() const
		{
			return (_ptr);
		}

		/**
		**************************************************
		 * random_access_iterator: access the pointed-to element
		**************************************************
		*/

		reference operator*() const
		{
			return (*_ptr);
		}

		pointer operator->() const
		{
			return (_ptr);
		}
	};
}

#endif