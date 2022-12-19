/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_cv.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierina <pierina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:29:50 by pierina           #+#    #+#             */
/*   Updated: 2022/12/19 09:32:09 by pierina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_REMOVE_CV_
#define _FT_REMOVE_CV_

namespace ft {

	/*************************************************************************
	 * remove_cv:
	 Provides the member typedef type which is the same as T, 
	 except that its topmost cv-qualifiers are removed.
		1) remove_cv removes the topmost const, or the topmost volatile,
		or both, if present.
		2) remove_const removes the topmost const
		3) remove_volatile removes the topmost volatile
	*************************************************************************/

	template< class T > struct remove_cv                   { typedef T type; };
	template< class T > struct remove_cv<const T>          { typedef T type; };
	template< class T > struct remove_cv<volatile T>       { typedef T type; };
	template< class T > struct remove_cv<const volatile T> { typedef T type; };

	template< class T > struct remove_const                { typedef T type; };
	template< class T > struct remove_const<const T>       { typedef T type; };

	template< class T > struct remove_volatile             { typedef T type; };
	template< class T > struct remove_volatile<volatile T> { typedef T type; };	
}

#endif