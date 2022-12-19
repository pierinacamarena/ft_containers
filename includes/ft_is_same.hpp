/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_same.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierina <pierina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:01:25 by pierina           #+#    #+#             */
/*   Updated: 2022/12/19 10:05:53 by pierina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _IS_SAME_
#define _IS_SAME_

namespace ft {

	/*************************************************************************
	 * is_same:
	 * Will check if two template parameters are the same 
	 *************************************************************************/

	//-->to ask, what is the difference between declaring typename and class
	//according to my notes it can be used interchangeably with class ok
	//what is the reason of doing = void?

	template<typename T = void, typename U = void>
	struct is_same {
		static const bool value = false;
	};
	
	//specialization
	template<typename T>
	struct is_same<T, T> {
		static const bool value = true;
	};
}
#endif