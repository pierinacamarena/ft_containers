/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierina <pierina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:32:51 by pierina           #+#    #+#             */
/*   Updated: 2022/12/19 10:10:49 by pierina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_IS_INTEGRAL_
#define	_FT_IS_INTEGRAL_

#include "ft_remove_cv.hpp"

namespace ft {
	/*************************************************************************
	 * is_integral:
	 * will check if the template parameter is an integral type
	 *************************************************************************/
	
	template <typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<short int>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long int>
	{
		static const bool value = true;
	};

	template<typename T>
	struct is_integral_cv
	{
		static const bool value = is_integral<typename remove_cv<T>::type>::value;
	};
}

#endif