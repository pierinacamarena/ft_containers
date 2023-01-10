/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexicographical_compare.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierina <pierina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:31:07 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/18 20:11:14 by pierina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXICOGRAPHICAL_COMPARE_HPP_
#define _LEXICOGRAPHICAL_COMPARE_HPP_

namespace ft
{	/*************************************************************************
	 * lexicographical_compare:
	 * Returns true if the first argument is less than the second lexicographically,
	 * otherwise false
	 *************************************************************************/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
		//this means it will return false if the second is the same lenght as the first 
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2,*first1))
				return (false);
			else if (comp(*first1,*first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
		//this means it will return false if the second is the same lenght as the first 
	}
}
#endif