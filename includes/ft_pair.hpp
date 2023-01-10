/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:16:28 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 05:54:57 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_FT_PAIR_
#define _FT_PAIR_

namespace ft
{
	template <class Input, class Output>
	struct selectFirst : public std::unary_function<Input, Output>
	{
		const Output &operator()(const Input &x) const
		{
			return (x.first);
		}
	};

	template<class T1, class T2>
	struct pair
	{
		//Member objects
		typedef T1	first_type;
		typedef T2	second_type;

		//member types
		first_type	first;
		second_type	second;

		//members functions
		pair() : first(first_type()), second(second_type()) {};
		template <class U, class V>
		pair(const pair<U,V> &pr) : first(pr.first), second(pr.second) {};
		pair(const first_type &a, const second_type &b) : first(a), second(b) {};

		pair & operator=(pair const & rhs) {
		new (this) pair(rhs);
		return (*this); }
	};

	//(Non-member functions)
	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 x, T2 y) { return (ft::pair<T1, T2>(x, y)); }

	template <class T1, class T2>
	bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); }

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(rhs < lhs)); }

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }

	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs < rhs)); }
		

} // namespace ft


#endif