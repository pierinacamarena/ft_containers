/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:18 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/09 06:05:26 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"
// #include "map.hpp"
#include <iostream>
#include <vector>


#include <sstream>
#include <iomanip>

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

// template <class Key, class T>
// void	print_m(ft::map<Key, T>& lst)
// {
// 	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << it->first << " => " << it->second << '\n';
// }


template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << "< " << (first < second) << std::endl;
	std::cout << "<= " << (first <= second) << std::endl;
	std::cout << "> " << (first > second) << std::endl;
	std::cout << ">= " << (first >= second) << std::endl;
	std::cout << "-----------" << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

int main()
{
		// Create a vector containing integers
	{
		const int size = 5;
		std::vector<int> vct(size);
		std::vector<int>::iterator it_one = vct.begin();
		std::vector<int>::reverse_iterator it = vct.rbegin();
		std::vector<int>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		printf_v(vct, "vct");
		it = it + 5;
		std::cout << "it: "<< *(it) << std::endl;
		it = 1 + it;
		std::cout << "it: "<< *(it) << std::endl;
		it = it - 4;
		std::cout << "it: "<< *(it) << std::endl;
		std::cout << "it += 2: " << *(it += 2) << std::endl;
		std::cout << "it -= 1: " << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		std::cout << "it: "<< *(it) << std::endl;
		*(it += 2) = 21;
		std::cout << "it: "<< *(it) << std::endl;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;
		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		std::cout << "===============================================" << '\n';

	}
	{
		const int size = 5;
		ft::vector<int> vct(size);
		ft::vector<int>::iterator it_one = vct.begin();
		ft::vector<int>::reverse_iterator it = vct.rbegin();
		ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		printf_v(vct, "vct");
		it = it + 5;
		std::cout << "it: "<< *(it) << std::endl;
		it = 1 + it;
		std::cout << "it: "<< *(it) << std::endl;
		it = it - 4;
		std::cout << "it: "<< *(it) << std::endl;
		std::cout << "it +=2: " << *(it += 2) << std::endl;
		std::cout << "it -= 1: " << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		// std::cout << "it: "<< *(it) << std::endl;
		*(it += 2) = 21;
		// std::cout << "it: "<< *(it) << std::endl;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	}
	{
		// const int size = 5;
		// std::vector<int> vct(size);
		// std::vector<int>::reverse_iterator it_0(vct.rbegin());
		// std::vector<int>::reverse_iterator it_1(vct.rend());
		// std::vector<int>::reverse_iterator it_mid;

		// std::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
		// std::vector<int>::const_reverse_iterator cit_1;
		// std::vector<int>::const_reverse_iterator cit_mid;
		
		// for (int i = size; it_0 != it_1; --i)
		// 	*it_0++ = i;

		// printf_v(vct, "vct");

		// it_0 = vct.rbegin();
		// cit_1 = vct.rend();
		// it_mid = it_0 + 3;
		// std::cout << "it_mid: " << *it_mid << '\n';
		// std::cout << "it_0 + 3: " << *(it_0 + 3) << '\n';
		// cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		// std::cout << std::boolalpha;
		// std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

		// std::cout << "\t\tft_eq_ope:" << std::endl;
		// ft_eq_ope(it_0 + 3, it_mid);
		// std::cout << "it_0: " << *(it_0) << '\n';
		// std::cout << "it_1: " << *(it_1) << '\n';
		
		// //#############################################################
		
		// ft::vector<int> vct_ft(size);
		// ft::vector<int>::reverse_iterator it_0_ft(vct_ft.rbegin());
		// ft::vector<int>::reverse_iterator it_1_ft(vct_ft.rend());
		// ft::vector<int>::reverse_iterator it_mid_ft;

		// ft::vector<int>::const_reverse_iterator cit_0_ft = vct_ft.rbegin();
		// ft::vector<int>::const_reverse_iterator cit_1_ft;
		// ft::vector<int>::const_reverse_iterator cit_mid_ft;

		// for (int i = size; it_0_ft != it_1_ft; --i)
		// 	*it_0_ft++ = i;
		
		// printf_v(vct_ft, "vct_ft");

		// it_0_ft = vct_ft.rbegin();
		// cit_1_ft = vct_ft.rend();
		// it_mid_ft = it_0_ft + 3;
		// // std::cout << "it_mid: " << *it_mid_ft << '\n';
		// // std::cout << "it_0 + 3: " << *(it_0_ft + 3) << '\n';
		
		// cit_mid_ft = it_0_ft + 3; cit_mid_ft = cit_0_ft + 3; cit_mid_ft = it_mid_ft;

		// std::cout << std::boolalpha;
		// std::cout << ((it_0_ft + 3 == cit_0_ft + 3) && (cit_0_ft + 3 == it_mid_ft)) << std::endl;
		
		// std::cout << "\t\tft_eq_ope:" << std::endl;
		// // ft_eq_ope(it_0 + 3, it_mid);
		// std::cout << "it_0_ft: " << *(it_0_ft) << '\n';
		// std::cout << "it_1_ft: " << *(it_1_ft) << '\n';
		// ft_eq_ope(it_0, it_1);
	}
	{		
		// std::cout << COLOR_TWO << "/--Testing: max_size(), size(), capacity()--/" << COLOR_NO << std::endl;
		// ft::vector<int>		e_m;
		// std::vector<int>	e_v;
		// ft::vector<int>		m(10, 42);
		// std::vector<int>	v(10, 42);
		// ft::vector<int>		m2(m);

		// std::cout << "Testing: empty constructor" << std::endl;
		// if (e_v.max_size() != e_m.max_size())
		// 	std::cout << "Max_size: ✘" << std::endl;
		// else
		// 	std::cout << "Max_size: ✔" << std::endl;

		// if (e_v.size() != e_m.size())
		// 	std::cout << "size: ✘" << std::endl;
		// else
		// 	std::cout << "size: ✔" << std::endl;

		// if (e_v.capacity() != e_m.capacity())
		// 	std::cout << "capacity: ✘" << std::endl;
		// else
		// 	std::cout << "capacity: ✔" << "\n\n";		

		// std::cout << "Testing: fill constructor" << std::endl;
		// if (v.max_size() != m.max_size())
		// 	std::cout << "Max_size: ✘" << std::endl;
		// else
		// 	std::cout << "Max_size: ✔" << std::endl;

		// if (v.size() != m.size())
		// 	std::cout << "size: ✘" << std::endl;
		// else
		// 	std::cout << "size: ✔" << std::endl;

		// if (v.capacity() != m.capacity())
		// 	std::cout << "capacity: ✘" << std::endl;
		// else
		// 	std::cout << "capacity: ✔" << "\n\n";

		
		// std::cout << "Testing: copy constructor " << std::endl;
		// if (v.max_size() != m2.max_size())
		// 	std::cout << "Max_size: ✘" << std::endl;
		// else
		// 	std::cout << "Max_size: ✔" << std::endl;

		// if (v.size() != m2.size())
		// 	std::cout << "size: ✘" << std::endl;
		// else
		// 	std::cout << "size: ✔" << std::endl;

		// if (v.capacity() != m2.capacity())
		// 	std::cout << "capacity: ✘" << std::endl;
		// else
		// 	std::cout << "capacity: ✔" << "\n\n";

		// v.push_back(7);
		// v.push_back(5);
		// v.push_back(16);
		// v.push_back(8);
		// v.push_back(13);

		// m.push_back(7);
		// m.push_back(5);  
		// m.push_back(16);
		// m.push_back(8);
		// m.push_back(13);
	
		// printf_v(v, "v");
		// printf_v(m, "m");
		// std::cout << "MAX_SIZE: " << v.max_size() << "\n";
		// std::cout << "max_size: " << m.max_size() << "\n";
		// std::cout << "SIZE: " << v.size() << "\n";
		// std::cout << "size: " << m.size() << "\n";
		// std::cout << "CAPACITY: " << v.capacity() << "\n";
		// std::cout << "capacity: " << m.capacity() << "\n";
		// ft::vector<int>::iterator ft_it = m.begin();
		// ft_it = ft_it + 11;
		// std::cout << "content at iterator is : " << *ft_it << "\n";
		// std::vector<int>::iterator std_it = v.begin() + 11;
		// std::cout << "content at iterator is : " << *std_it << "\n";
		// printf_v(v, "v");
		// v.insert(std_it, 5, 125);
		// printf_v(v, "v");
		// ft::vector<int>::iterator ft_it = m.begin() + 11;
		// std::cout << "content at iterator is : " << *ft_it << "\n";
		// printf_v(m, "m");
		// m.insert(ft_it, 125);
		// printf_v(m, "m");
		
		// printf_v(m, "m");
		// m.erase(m.begin() + 2, ft_it);
		// printf_v(m, "m");

		// printf_v(e_v, "e_v");
		// e_v.reserve(12);
		// e_v.push_back(1);
		// e_v.push_back(2);
		// e_v.push_back(3);
		// e_v.push_back(4);
		// e_v.push_back(5);
		// e_v.push_back(6);
		// e_v.push_back(7);
		// std::vector<int>::iterator std_it = e_v.begin() + 4;
		// std::cout << e_v.capacity() << '\n';
		// printf_v(e_v, "e_v");
		// e_v.insert(e_v.end(), 150);
		// printf_v(e_v, "e_v");
		// std::cout << "####################################" << '\n';
		// e_m.reserve(12);
		// e_m.push_back(1);
		// e_m.push_back(2);
		// // e_m.push_back(3);
		// // e_m.push_back(4);
		// // e_m.push_back(5);
		// // e_m.push_back(6);
		// // e_m.push_back(7);
		// std::cout << e_m.capacity() << '\n';
		// ft::vector<int>::iterator ft_it = e_m.end();
		// // std::cout << "end: " << *ft_it << '\n';
		// printf_v(e_m, "e_m");
		// e_m.insert(ft_it, 150);
		// printf_v(e_m, "e_m");
	// }
	// {
	// 	std::cout << COLOR_TWO << "/--Testing: iterator--/" << COLOR_NO << std::endl;
	// 	ft::vector<int>		m(10, 42);
	// 	std::vector<int>	v(10, 42);

	// 	printf_v(v, "std vector v");
	// 	printf_v(m, "ft vector v");
	// 	ft::vector<int>::iterator ft_it = m.begin();
	// 	std::vector<int>::iterator std_it = v.begin();
	// 	ft::vector<int>::iterator ft_end = m.end();
	// 	while (ft_it != ft_end)
	// 	{
    //     	if (*ft_it != *std_it)
  	//           std::cout <<"iterator: ✘" << "\n";
	// 		ft_it++;
	// 		std_it++;
	// 	}
  	//     std::cout <<"iterator: ✔" << "\n";

	// 	printf_v(m, "ft vector v");
	// 	m.resize(15, 21);
	// 	std::cout << "size: " << m.size() << "\n";
	// 	printf_v(m, "ft vector v");

	// 	printf_v(v, "std vector v");
	// 	v.resize(15, 21);
	// 	std::cout << "SIZE: " << v.size() << "\n";
	// 	printf_v(v, "std vector v");

	// 	// m.assign(24, 30);
	// 	// printf_v(m, "ft vector v");
	}
}