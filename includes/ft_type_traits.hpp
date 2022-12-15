/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:31:13 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/15 22:27:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_UTILS_HPP_
#define _FT_UTILS_HPP_

namespace ft{
	
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

	/*************************************************************************
	 * lexicographical_compare:
	 * If the first argument is less than the second, otherwise false
	 * 
	 *************************************************************************/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		looping over InputIterator1
		{
			if (end of iterator2 or *first1 > *first2)
				return (false)
			else if (first )
			
		}		
	}

	/*************************************************************************
	 * is_same:
	 * Will check if two template parameters are the same 
	 *************************************************************************/

	template<class T, class U>
	struct is_same {
		static const bool value = false;
	};
	
	//specialization
	template<class T>
	struct is_same<T, T> {
		static const bool value = true;
	};

	//another potential implementation
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

	/*************************************************************************
	 * remove_cv:
	 Provides the member typedef type which is the same as T, 
	 except that its topmost cv-qualifiers are removed.
		1) remove_cv removes the topmost const, or the topmost volatile, or both, if present.
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
	struct is_integral_const
	{
		static const bool value = is_integral<typename remove_cv<T>::type>::value;
	};
	

	//bool
	//char
	//wchar_t
	//signed_char
	//short int
	//int
	//long int
	//lon long int
	//unsigned char
	//unsigned short int
	//unsigned int
	//unsigned long int
	//unsigned long long int
}

#endif