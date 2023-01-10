/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:52:23 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/01 19:33:25 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <cstddef>

namespace ft {

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*,  class Reference = T&>
	
	struct 	iterator {
		
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
};

#endif