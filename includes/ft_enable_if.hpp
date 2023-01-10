/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:05:50 by pierina           #+#    #+#             */
/*   Updated: 2022/12/28 16:07:11 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
#define ENABLE_IF

namespace ft {

	/*************************************************************************
	 * enable_if:
	 * when the condition is false, you wont be able to retrieve ::type
	 * using this will allow a compilation failure when a particular condition
	 * is not met. 
	 *************************************************************************/
	template<bool cond, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif