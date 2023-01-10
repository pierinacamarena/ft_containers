/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:35:39 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/27 12:58:43 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NULLPTR_
#define _NULLPTR_

namespace ft
{
	/*returns a pointer of any type, member or non member*/
	
	const class nullptr_t					/*this is a const object*/
	{
		public:
			template<class T>				/*convertible to any type*/
			operator T*() const				/*of null non-member*/
			{return 0;}						/*pointer*/

			template<class C, class T>		/*or any type of null*/	
			operator T C::*() const			/*member pointer*/
			{ return 0;}

		private:
			void operator&() const;			/*can't take address of nullptr*/
	} nullptr_t = {};							/*name is t_nullptr*/
}

#endif