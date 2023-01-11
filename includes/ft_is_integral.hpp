/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:32:51 by pierina           #+#    #+#             */
/*   Updated: 2023/01/11 11:48:20 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_IS_INTEGRAL_
#define	_FT_IS_INTEGRAL_

// #include "ft_remove_cv.hpp"

namespace ft {
	/*************************************************************************
	 * is_integral:
	 * will check if the template parameter is an integral type
	 *************************************************************************/

	template <typename T, T v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;

		operator value_type() const
		{
			return value;
		}

		value_type operator()() const
		{
			return value;
		}
	};

	template <bool V>
	struct bool_constant : public integral_constant<bool, V> {
	};

	struct true_type : public bool_constant<true> {
	};

	struct false_type : public bool_constant<false> {
	};
	
	template <typename T>
	struct remove_const {
		typedef T type;
	};

	template <typename T>
	struct remove_const<const T> {
		typedef T type;
	};

	template <typename T>
	struct remove_volatile {
		typedef T type;
	};

	template <typename T>
	struct remove_volatile<volatile T> {
		typedef T type;
	};

	template <typename T>
	struct remove_cv {
		typedef typename remove_volatile<typename remove_const<T>::type>::type type;
	};

	template <typename>
	struct is_integral_base : public false_type {
	};

	template <>
	struct is_integral_base<bool> : public true_type {
	};

	template <>
	struct is_integral_base<char> : public true_type {
	};

	template <>
	struct is_integral_base<signed char> : public true_type {
	};

	template <>
	struct is_integral_base<short int> : public true_type {
	};

	template <>
	struct is_integral_base<int> : public true_type {
	};

	template <>
	struct is_integral_base<long int> : public true_type {
	};

	template <>
	struct is_integral_base<unsigned char> : public true_type {
	};

	template <>
	struct is_integral_base<unsigned short int> : public true_type {
	};

	template <>
	struct is_integral_base<unsigned int> : public true_type {
	};

	template <>
	struct is_integral_base<unsigned long int> : public true_type {
	};

	template <typename T>
	struct is_integral : is_integral_base<typename remove_cv<T>::type> {
	};
}

#endif