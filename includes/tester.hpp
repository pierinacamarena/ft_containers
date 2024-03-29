/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:22:31 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/11 06:17:12 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TESTER_HPP_
#define _TESTER_HPP_

#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"

# include <vector>
# include <map>
# include <stack>
# include <fstream>
# include <iostream>
# include <typeinfo>
# include <cstdlib>
# include<string>

#ifndef LIB
#define LIB ft
#endif

void vector_test();
void stack_test();
void map_test();

#endif
