/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:12:08 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 04:20:07 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.hpp"

#define COLOR_ONE	"\033[35m"
#define COLOR_TWO	"\033[33m"
#define COLOR_NO	"\033[0m"

template < typename T >
void	printf_v(T & v, std::string name)
{
	std::cout << name << " = {";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i + 1 != v.size())
			std::cout << ", ";
	}
	std::cout << "}; \n";
}


int main()
{
	{
		LIB::vector<int> test(3,3);
		printf_v(test, "test");
		LIB::vector<LIB::vector<int> > self_assign;
		LIB::vector<LIB::vector<int> > *ptr = &self_assign;
		LIB::vector<LIB::vector<int> > *ptr2 = &self_assign;
		self_assign.assign(4, test);

	}
	{
		// const int size = 5;
		// LIB::vector<int> vct(size);
		// LIB::vector<int>::iterator it_one = vct.begin();
		// LIB::vector<int>::reverse_iterator it = vct.rbegin();
		// LIB::vector<int>::const_reverse_iterator ite = vct.rbegin();

		// for (int i = 0; i < size; ++i)
		// 	it[i] = (size - i) * 5;

		// printf_v(vct, "vct");
		// it = it + 5;
		// std::cout << "it: "<< *(it) << std::endl;
		// it = 1 + it;
		// std::cout << "it: "<< *(it) << std::endl;
		// it = it - 4;
		// std::cout << "it: "<< *(it) << std::endl;
		// std::cout << "it += 2: " << *(it += 2) << std::endl;
		// std::cout << "it -= 1: " << *(it -= 1) << std::endl;

		// *(it -= 2) = 42;
		// std::cout << "it: "<< *(it) << std::endl;
		// *(it += 2) = 21;
		// std::cout << "it: "<< *(it) << std::endl;

		// std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;
		// std::cout << "(it == const_it): " << (ite == it) << std::endl;
		// std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		// std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		// std::cout << "===============================================" << '\n';

	}
	return(0);
}