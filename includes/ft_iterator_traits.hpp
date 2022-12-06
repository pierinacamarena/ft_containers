/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:12:38 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/06 22:48:25 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _FT_ITERATOR_TRAITS_HPP
#define _FT_ITERATOR_TRAITS_HPP

namespace ft {

	template<class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};
	
	template<class T> struct iterator_traits<T*> {
		typedef std::ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef	T&										reference;
		typedef	std::random_access_iterator_tag				iterator_category;
	};
	
	template<class T>struct iterator_traits<const T*> {
		typedef std::ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef	T&										reference;
		typedef	std::random_access_iterator_tag				iterator_category;
	};

}

#endif